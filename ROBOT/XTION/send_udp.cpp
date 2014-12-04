#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "send_udp.hpp"


void SendUdp::initialize() {
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = inet_addr("172.16.14.100");
}


void SendUdp::stop_send() {
    sendto(sock, "STOP", 4, 0, (struct sockaddr *)&addr, sizeof(addr));
    close(sock);
}


void SendUdp::stat_send() {
    sendto(sock, "STAT", 4, 0, (struct sockaddr *)&addr, sizeof(addr));
    close(sock);
}
