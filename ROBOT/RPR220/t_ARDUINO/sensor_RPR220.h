#ifndef INCLUDE_SENSOR_RPR220
#define INCLUDE_SENSOR_RPR220

// #include <EEPROM.h>

class RPR220
{
    public:
        RPR220();
        void set_threshold(bool sw1, bool sw2);
        unsigned int get_binary();

    private:
        void read_sensor(int* sensor_value);
        unsigned int comv_value_2binaly(int* sensor_value);
        void calc_sensor_threshold();
        void write_EEPROM(int addr, int* sensor_value);
        void read_EEPROM(int addr, int* sensor_value);

        int sensor_online_value[6];
        int sensor_ofline_value[6];
        int sensor_threshold_value[6];
};


#endif // INCLUDE_SENSOR_RPR220
