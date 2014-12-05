#ifndef HEAD_GET_DESTINATION
#define HEAD_GET_DESTINATION


// Serial
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>


// Serial Port
#define SERIAL_PORT "/dev/ttyUSB0"


/*===== Destination =====*/
class Destination
{
    public:
        Destination();
        int get_destination_count();
        int get_all_count();
        int get_home_count();

    private:
        void recive_serial(char* char_destination);
        int comv_destination_char2int(char* char_destination);

        int fd;
        char buf[100];
        int all_count;
        char char_destination[10];
};


#endif // HEAD_GET_DESTINATION
