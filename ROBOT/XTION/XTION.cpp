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
            depthImage = showDepthStream( depthFrame );
            cv::imshow( "Depth Stream", depthImage );
        }

    private:

        cv::Mat showDepthStream( const openni::VideoFrameRef& depthFrame ) {
            cv::Mat depthImage = cv::Mat( depthFrame.getHeight(), depthFrame.getWidth(), CV_16UC1, (unsigned short*)depthFrame.getData() );
            depthImage.convertTo( depthImage, CV_8U, 255.0 / 10000 );
            showCenterDistance( depthImage, depthFrame );
            return depthImage;
        }

        void showCenterDistance( cv::Mat& depthImage, const openni::VideoFrameRef& depthFrame ) {
            openni::VideoMode videoMode = depthStream.getVideoMode();

            int centerX = videoMode.getResolutionX() / 2;
            int centerY = videoMode.getResolutionY() / 2;
            int centerIndex = ( centerY * videoMode.getResolutionX()) + centerX;

            unsigned short* depth = (unsigned short*)depthFrame.getData();

            std::stringstream ss;
            ss << "Center Point :" << depth[centerIndex];
            cv::putText( depthImage, ss.str(), cv::Point( 0, 50 ), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar( 255 ) );

            unsigned short min = 10000;
            for (int i = 0; i < 320; i++) {
                if (depth[i] == 0) {
                    std::cout << depth[i] << '\n';
                }
                else if (min > depth[i]) {
                    min = depth[i];
                }
            }
            std::cout << "Min : " << min << "\n\n";
        }

        openni::Device device;
        openni::VideoStream depthStream;

        cv::Mat depthImage;
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
