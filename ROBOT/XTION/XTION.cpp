#include <iostream>

#include "depth.hpp"
#include "send_udp.hpp"


int main( int argc, const char * argv[] ) {
    unsigned short min_distance;

    try {
        openni::OpenNI::initialize();

        DepthSensor sensor;
        sensor.initialize();

        SendUdp udp;
        udp.initialize();

        while (true) {
            min_distance = sensor.update();
            std::cout << min_distance << '\n';
            if (min_distance < 500) {
                std::cout << "[!!] STOP\n";
                udp.send();
            }
        }
    }
    catch ( std::exception& ) {
        std::cout << openni::OpenNI::getExtendedError() << std::endl;
    }

    return 0;
}
