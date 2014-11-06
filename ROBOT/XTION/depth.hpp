#ifndef HEAD_DEPTH
#define HEAD_DEPTH

#include <OpenNI.h>
#include <opencv2/opencv.hpp>

#include <stdexcept>


class DepthSensor
{
    public:

        void initialize();
        unsigned short update();

    private:

        unsigned short getSmallerDepth( const openni::VideoFrameRef& depthFrame );

        openni::Device device;
        openni::VideoStream depthStream;

};

#endif // HEAD_DEPTH
