#include <iostream>
#include <stdlib.h>

#include "../include/get_destination.hpp"
#include "../include/get_sensor_value.hpp"


int main()
{
    Destination destination;
    SensorValue sensor;

    while (true) {      // 1 Round
        int destination_position = destination.get_position();
        std::cout << "Destination Position is: " << destination_position << '\n';

        while (true) {
            int sensor_value = sensor.get_sensor_value();
            std::cout << "\t\tSensor Value is: " << std::hex << sensor_value << '\n';
        }

    }

    return EXIT_SUCCESS;

}
