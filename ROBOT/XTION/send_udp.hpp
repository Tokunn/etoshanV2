#ifndef HEAD_SEND_UDP
#define HEAD_SEND_UDP

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


class SendUdp
{
    public:
        void initialize();
        void send();

    private:
        int sock;
        struct sockaddr_in addr;
};


#endif // HEAD_SEND_UDP
