#include "../include/get_sensor_value.hpp"


#include <iostream>
#include <stdlib.h>


/*----- initialize() -----*/
SensorValue::SensorValue() {
    fd = open(SENSOR_SERIAL_PORT, O_RDWR);
}


/*----- get_sensor_value() -----*/
int SensorValue::get_sensor_value() {
    int value;
    do {
        recive_serial(&sensor_value);
        value = check_sensor_value(&sensor_value);
    } while (value < 0);
    return value;
}


/*----- recive_serial() -----*/
void SensorValue::recive_serial(int* p_sensor_value) {
    char sensor_value_char[10];
    char *endptr;
    read(fd, sensor_value_char, sizeof(sensor_value_char));
    sensor_value_char[2] = '\0';
    int raw_sensor_value = strtol(sensor_value_char, &endptr, 16);
    if (raw_sensor_value >= 0x10) {
        *p_sensor_value = raw_sensor_value - 0x10;
    }
    else {
        *p_sensor_value = -1;
    }
}


/*----- check_sensor_value() -----*/
int SensorValue::check_sensor_value(const int* p_sensor_value) {
    if ((*p_sensor_value <= 0x3F) && (*p_sensor_value >= 0x0)) {
        // 0x3F = 0b111111      0x0 = 0b000000
        return *p_sensor_value;
    }
    else {
        return -1;
    }
}
