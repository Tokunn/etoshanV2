#include <OpenNI.h>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <stdexcept>

#include "depth.hpp"



void DepthSensor::initialize() {
    openni::Status ret = device.open( openni::ANY_DEVICE );
    if ( ret != openni::STATUS_OK ) {
        throw std::runtime_error( "openni::Device::open() failed." );
    }
    depthStream.create( device, openni::SENSOR_DEPTH );
    depthStream.start();
}


unsigned short DepthSensor::update() {
    unsigned short min = 10000;
    openni::VideoFrameRef depthFrame;
    depthStream.readFrame( &depthFrame );
    return getSmallerDepth( depthFrame );
}


unsigned short DepthSensor::getSmallerDepth( const openni::VideoFrameRef& depthFrame ) {
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
    return min;
}
