#include "OptiTrack.hpp"
#include <iostream>

OptiTrack::OptiTrack() {

}

OptiTrack::~OptiTrack() {

}

Quaternion OptiTrack::getAttitude(){

    std::cout << "Hello, I'm OptiTrack Attitude!\n";
    Quaternion quat;
    quat.x = 0;
    quat.y = 0;
    quat.z = 0;
    quat.w = 0.99;

    return quat;
}

Vector3D OptiTrack::getPosition(){

    std::cout << "Hello, I am OptiTrack Position\n";
    Vector3D data;
    data.x = 0;
    data.y = 1;
    data.z = 0;
    
    return data;
}