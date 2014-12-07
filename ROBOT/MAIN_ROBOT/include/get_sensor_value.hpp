#ifndef HEAD_GET_SENSOR_VALUE
#define HEAD_GET_SENSOR_VALUE


// Serial
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

// Serial Config
#include "serial_config.hpp"


/*===== SensorValue =====*/
class SensorValue
{
    public:
        SensorValue();
        int get_sensor_value();

    private:
        void recive_serial(int* p_sensor_value);
        int check_sensor_value(const int* p_sensor_value);

        int fd;
        int sensor_value;
};

#endif // HEAD_GET_SENSOR_VALUE
