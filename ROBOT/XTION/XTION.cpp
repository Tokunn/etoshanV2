#include <OpenNI.h>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <stdexcept>


class DepthSensor
{
    public:

        void initialize() {
            openni::Status ret = device.open( openni::ANY_DEVICE );
            if ( ret != openni::STATUS_OK ) {
                throw std::runtime_error( "openni::Device::open() failed." );
            }
            depthStream.create( device, openni::SENSOR_DEPTH );
            depthStream.start();
        }

        void update() {
            openni::VideoFrameRef depthFrame;
            depthStream.readFrame( &depthFrame );
            showDepthStream( depthFrame );
        }

    private:

        void showDepthStream( const openni::VideoFrameRef& depthFrame ) {
            openni::VideoMode videoMode = depthStream.getVideoMode();

            int depthIndex = videoMode.getResolutionX() * videoMode.getResolutionY();

            unsigned short* depth = (unsigned short*)depthFrame.getData();

            unsigned short min = 10000;

            for (int i = 0; i < depthIndex; i++) {
                if (depth[i] == 0) {
                }
                else if (min > depth[i]) {
                    min = depth[i];
                }
            }
            std::cout << "Min : " << min << "\n\n";
        }

        openni::Device device;
        openni::VideoStream depthStream;

};

int main( int argc, const char * argv[] ) {
    try {
        openni::OpenNI::initialize();
        DepthSensor sensor;
        sensor.initialize();
        while( 1 ) {
            sensor.update();
        }
    }
    catch ( std::exception& ) {
        std::cout << openni::OpenNI::getExtendedError() << std::endl;
    }

    return 0;
}
