#include "../include/get_sensor_value.hpp"


/*----- initialize() -----*/
SensorValue::SensorValue() {
    fd = open(SENSOR_SERIAL_PORT, O_RDWR);
}
