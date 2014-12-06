#ifndef HEAD_GET_DESTINATION
#define HEAD_GET_DESTINATION


// Serial
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>


// Serial Config
#include "../include/serial_config.hpp"


// Pose number
enum Pose{ NONE=0, MAJOKO=1, OBAKE=2, KAIDAN=3, NEKO=4, KING=5, BRUNA=6 };


/*===== Destination =====*/
class Destination
{
    public:
        Destination();
        int get_position();
        int get_all_count();

    private:
        void recive_serial(char* char_destination);
        int comv_destination_char2int(char* char_destination);

        int fd;
        int all_count;
        char char_destination[7];
        char pose_char[7][8];
};


#endif // HEAD_GET_DESTINATION
