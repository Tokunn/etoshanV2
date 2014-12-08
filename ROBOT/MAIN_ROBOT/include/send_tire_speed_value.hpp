#ifndef HEAD_SEND_TIRE_SPEED_VALUE
#define HEAD_SEND_TIRE_SPEED_VALUE


// Serial
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>


// Serial Config
#include "serial_config.hpp"


/*===== TireSpeedvalue =====*/
class TireSpeedvalue
{
    public:
        TireSpeedvalue();
        void send_speed(int speed);

    private:
        void comv_speed_i2a(char* p_speed_char, int* p_speed);
        void send_serial(char* p_speed_char);

        int fd;
};

#endif // HEAD_SEND_TIRE_SPEED_VALUE
