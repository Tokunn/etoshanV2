#include <iostream>
#include <stdlib.h>
#include <bitset>
#include <iomanip>

#include "../include/get_destination.hpp"
#include "../include/get_sensor_value.hpp"
#include "../include/do_linetrace.hpp"
#include "../include/send_tire_speed_value.hpp"


int main()
{
    Destination destination;
    SensorValue sensor;
    LineTrace command_lib;
    TireSpeedvalue motor;

    while (true) {      // 1 Round
        bool onlineflag = false;
        int count = 0;
        int stopline = destination.get_position();
        int all_count = destination.get_all_count();
        int stop_val = 0x00;

        std::cout << "Stop Line: " << stopline << '\n';

        while (true) {
            int val = sensor.get_sensor_value();
            command_lib.set_sensor_value(&val);

            if (val != 0x3F) {      // 0x3F = 0b111111
                onlineflag = false;
                std::cout << "\tONLine Flag = false";
            }
            else if (onlineflag == false) {
                count++;
                onlineflag = true;
                std::cout << "\tONLine Flag = true";
            }

            if ((val == 0x3F) && ((count == stopline) || (count == all_count))) {
                command_lib.set_sensor_value(&stop_val);
                std::cout << "[!!]STOP\n";
            }

            int command = command_lib.get_tire_speed_value();

            std::cout << "\tCount: " << count;
            std::cout << "\tSensor Val: " << std::bitset<6>(val);
            std::cout << "\tTire Speed: " << std::setw(6) << std::setfill('0') << command << std::endl;

            motor.send_speed(command);
            if (count == all_count) {
                break;
            }
        }

    }

    return EXIT_SUCCESS;

}
