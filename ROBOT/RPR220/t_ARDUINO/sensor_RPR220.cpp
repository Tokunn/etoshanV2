#include "sensor_RPR220.hpp"


/*---- Initialize ----*/
RPR220::RPR220()
{
    // TODO Read EEPROM
    calc_sensor_threshold();
}


/*---- set_threshold() ----*/
void RPR220::set_threshold(bool sw1, bool sw2)
{
    if (sw1) {
        read_sensor(sensor_online_value);
    }
    else if (sw2) {
        read_sensor(sensor_ofline_value);
    }
    calc_sensor_threshold();
    // TODO Write EEPROM
}


/*---- get_binary() ----*/
unsigned int RPR220::get_binary()
{
    int sensor_raw_value[6];
    read_sensor(sensor_raw_value);
    return comv_value_2binaly(sensor_raw_value);
}


/*---- read_sensor() ----*/
void RPR220::read_sensor(int* sensor_value)
{
    for (int i = 0; i < 6; i++) {
        sensor_value[i] = analogRead(i);
    }
}


/*---- comv_value_2binaly ----*/
unsigned int RPR220::comv_value_2binaly(int* sensor_value)
{
    int sensor_value_2binaly[6];
    for (int i = 0; i < 6; i++) {
        if (sensor_value[i] > sensor_threshold_value[i]) {
            sensor_value_2binaly[i] = 1;
        } else {
            sensor_value_2binaly[i] = 0;
        }
    }
    unsigned int value_binaly = 0;
    for (int i = 0; i < 6; i++) {
        value_binaly = (value_binaly<<1) + sensor_value_2binaly[i];
    }
    return value_binaly;
}


/*---- calc_sensor_threshold() ----*/
void RPR220::calc_sensor_threshold()
{
    for (int i = 0; i < 6; i++) {
        sensor_threshold_value[i] = sensor_ofline_value[i] + ((sensor_online_value[i] - sensor_ofline_value[i]) / 2);
    }
}
