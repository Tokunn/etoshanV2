#ifndef INCLUDE_SEND_UDP
#define INCLUDE_SEND_UDP

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


class SendUdp
{
    public:
        void initialize();
        void stop_send();
        void stat_send();

    private:
        int sock;
        struct sockaddr_in addr;
};


#endif // INCLUDE_SEND_UDP
