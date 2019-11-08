#include "OptiTrack.hpp"
#include <iostream>

OptiTrack::OptiTrack() {
    Quaternion _bodyAtt;
    Vector3D _bodyPos;

}

OptiTrack::~OptiTrack() {

}

Vector3D OptiTrack::getAttitude(){
    Vector3D rpy = getEulerfromQuaternion(_bodyAtt);
    rpy.z = 0.0;

    std::cout << "getAttitude"<< std::endl;
    std::cout << "roll: " << rpy.x << std::endl;
    std::cout << "pitch: " << rpy.y << std::endl;
    std::cout << "yaw: " << rpy.z << std::endl;

    return rpy;
}

double OptiTrack::getHeading(){
    Vector3D rpy = getEulerfromQuaternion(_bodyAtt);
    rpy.x = 0.0;
    rpy.y = 0.0; 

    std::cout << "getHeading"<< std::endl;
    std::cout << "roll: " << rpy.x << std::endl;
    std::cout << "pitch: " << rpy.y << std::endl;
    std::cout << "yaw: " << rpy.z << std::endl;

    return rpy.z;
}

Quaternion OptiTrack::getAttitudeHeading(){

    std::cout << "getAttitudeHeading"<< std::endl;
    std::cout << "x: " << _bodyAtt.x << std::endl;
    std::cout << "y: " << _bodyAtt.y << std::endl;
    std::cout << "z: " << _bodyAtt.z << std::endl;
    std::cout << "w: " << _bodyAtt.w << std::endl;
    
    return _bodyAtt;
}

Vector3D OptiTrack::getPosition(){

    std::cout << "getPosition"<< std::endl;
    std::cout << "x: " << _bodyPos.x << std::endl;
    std::cout << "y: " << _bodyPos.y << std::endl;
    std::cout << "z: " << _bodyPos.z << std::endl;
    
    return _bodyPos;
}

void OptiTrack::receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type){
    if(_msg_type == msg_type::optitrack){

        msg_type_optitrack _msg_type_optitrack = *((msg_type_optitrack*)&data[0]);

        if(_msg_type_optitrack == msg_type_optitrack::position){
            _bodyPos.x = *((double *) &data[sizeof(double)*0 + 4]);
            _bodyPos.y = *((double *) &data[sizeof(double)*1 + 4]);
            _bodyPos.z = *((double *) &data[sizeof(double)*2 + 4]);

        }else if (_msg_type_optitrack == msg_type_optitrack::attitude){
            _bodyAtt.x = *((double *) &data[sizeof(double)*0 + 4]);
            _bodyAtt.y = *((double *) &data[sizeof(double)*1 + 4]);
            _bodyAtt.z = *((double *) &data[sizeof(double)*2 + 4]);
            _bodyAtt.w = *((double *) &data[sizeof(double)*3 + 4]);

        }
    }
}