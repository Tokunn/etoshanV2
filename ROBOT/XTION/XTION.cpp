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

            colorStream.create( device, openni::SENSOR_COLOR );
            colorStream.start();
        }

        void update() {
            openni::VideoFrameRef colorFrame;
            colorImage = showColorStream( colorFrame );
            cv::imshow( "Color Stream", colorImage );
        }

    private:

        cv::Mat showColorStream( const openni::VideoFrameRef& colorFrame ) {
            cv::Mat colorImage = cv::Mat( colorFrame.getHeight(),
                                          colorFrame.getWidth(),
                                          CV_8UC3,
                                          (unsigned char*)colorFrame.getData()
                    );
            cv::cvtColor( colorImage, colorImage, CV_RGB2BGR );

            return colorImage;
        }

        openni::Device device;
        openni::VideoStream colorStream;

        cv::Mat colorImage;
};

int main( int argc, const char * argv[] ) {
    try {
        openni::OpenNI::initialize();
        DepthSensor sensor;
        sensor.initialize();

        while( 1 ) {
            sensor.update();
            int key = cv::waitKey( 10 );
            if ( key == 'q' ) {
                break;
            }
        }
    }
    catch ( std::exception& ) {
        std::cout << openni::OpenNI::getExtendedError() << std::endl;
    }

    return 0;
}
