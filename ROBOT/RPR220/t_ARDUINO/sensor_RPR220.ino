#include "sensor_RPR220.h"


/*---- Initialize ----*/
RPR220::RPR220()
{
    int strtaddr_online = 0;
    int strtaddr_ofline = 6;

    read_EEPROM(strtaddr_online, sensor_online_value);
    read_EEPROM(strtaddr_ofline, sensor_ofline_value);

    calc_sensor_threshold();
}


/*---- set_threshold() ----*/
void RPR220::set_threshold(bool sw1, bool sw2)
{
    int strtaddr_online = 0;
    int strtaddr_ofline = 6;

    if (sw1) {
        read_sensor(sensor_online_value);
        write_EEPROM(strtaddr_online, sensor_online_value);
        delay(1000);
    }
    else if (sw2) {
        read_sensor(sensor_ofline_value);
        write_EEPROM(strtaddr_ofline, sensor_ofline_value);
        delay(1000);
    }
    calc_sensor_threshold();
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
        sensor_value[i] = (analogRead(i) - 600);
        // sensor_value[i] += 600; // #=DEBUG=#
        Serial.print(sensor_value[i]); // #=DEBUG=#
        Serial.print(' ');  // #=DEBUG=#
    }
    Serial.println(' '); // #=DEBUG=#
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
        sensor_threshold_value[i] = sensor_online_value[i] + ((sensor_ofline_value[i] - sensor_online_value[i]) / 2);
    }
}


/*---- write_EEPROM ----*/
void RPR220::write_EEPROM(int addr, int* sensor_value)
{
    for (int i = 0; i < 6; i++) {
        int j_addr = i + addr;
        EEPROM.write(j_addr, sensor_value[i]);
        delay(5);
    }
}


/*---- read_EEPROM ----*/
void RPR220::read_EEPROM(int addr, int* sensor_value)
{
    for (int i = 0; i < 6; i++) {
        int j_addr = i + addr;
        sensor_value[i] = EEPROM.read(j_addr);
    }
}
