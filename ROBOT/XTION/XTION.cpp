#include <iostream>

#include "depth.hpp"


int main( int argc, const char * argv[] ) {

    try {
        openni::OpenNI::initialize();
        DepthSensor sensor;
        sensor.initialize();

        while (true) {
            std::cout << sensor.update() << '\n';
        }
    }

    catch ( std::exception& ) {
        std::cout << openni::OpenNI::getExtendedError() << std::endl;
    }

    return 0;
}
