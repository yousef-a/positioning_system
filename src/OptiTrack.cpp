#include "OptiTrack.hpp"
#include <iostream>

OptiTrack::OptiTrack() {
    Quaternion _bodyAtt;
    Vector3D _bodyPos;

}

OptiTrack::~OptiTrack() {

}

Quaternion OptiTrack::getAttitudeHeading(){

    std::cout << "Hello, I'm OptiTrack Attitude!\n";
    Quaternion quat;
    quat.x = 0;
    quat.y = 0;
    quat.z = 0;
    quat.w = 0.99;

    return quat;
}

Vector3D OptiTrack::getPosition(){

    std::cout << "x: " << _bodyPos.x << std::endl;
    std::cout << "y: " << _bodyPos.y << std::endl;
    std::cout << "z: " << _bodyPos.z << std::endl;
    
    return _bodyPos;
}

void OptiTrack::receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type){
    
    double _position[3];
    double* tmp_ptr[3];
    _bodyPos.x = *((double *) &data[sizeof(double)*0]);
    _bodyPos.y = *((double *) &data[sizeof(double)*1]);
    _bodyPos.z = *((double *) &data[sizeof(double)*2]);
    
}