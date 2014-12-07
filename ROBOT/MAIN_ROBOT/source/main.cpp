#include <iostream>
#include <stdlib.h>

#include "../include/get_destination.hpp"
#include "../include/get_sensor_value.hpp"


int main()
{
    Destination destination;
    SensorValue sensor;

    while (true) {
        int destination_position = destination.get_position();
        int sensor_value = sensor.get_sensor_value();
        std::cout << "Destination Position is: " << destination_position << "\t\tSensor Value is: " << sensor_value << '\n';
    }

    return EXIT_SUCCESS;

}
