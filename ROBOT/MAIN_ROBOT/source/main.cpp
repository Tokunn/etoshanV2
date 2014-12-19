#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <iomanip>

#include "../include/get_destination.hpp"
#include "../include/get_sensor_value.hpp"
#include "../include/do_linetrace.hpp"
#include "../include/write_tire_speed_value.hpp"
//#include "../include/send_tire_speed_value.hpp"


int main()
{
    Destination destination;
    SensorValue sensor;
    LineTrace command_lib;
    TireSpeedvalueGPIO motor;
    //TireSpeedvalue motor;

    while (true) {      // 1 Round
        bool onlineflag = false;
        int count = 0;
        int stopline = destination.get_position();
        int all_count = destination.get_all_count();
        int stop_val = 0x00;

        //std::cout << "Stop Line: " << stopline << '\n';
        printf("Stop Line: %d\n", stopline);

        while (true) {
            int val = sensor.get_sensor_value();
            command_lib.set_sensor_value(&val);

            if (val != 0x3F) {      // 0x3F = 0b111111
                onlineflag = false;
                //std::cout << "\tONLine Flag = false";
                printf("\tON Line Flag = false");
            }
            else if (onlineflag == false) {
                count++;
                onlineflag = true;
                //std::cout << "\tONLine Flag = true";
                printf("\tON Line Flag = true");
            }

            if ((val == 0x3F) && ((count == stopline) || (count == all_count))) {
                command_lib.set_sensor_value(&stop_val);
                //std::cout << "[!!]STOP\n";
                printf("[!!]STOP\n");
            }

            int command = command_lib.get_tire_speed_value();

            printf("\tCount: %d", count);
            std::cout << "\tSensor Val: " << std::bitset<6>(val);
            printf("\tTire Speed: %06d\n", command);
            //std::cout << "\tTire Speed: " << std::setw(6)
            //<< std::setfill('0') << command << std::endl;

            //motor.send_speed(command);
            motor.write_speed(command);
            if (count == all_count) {
                break;
            }
        }

    }

    return EXIT_SUCCESS;

}
