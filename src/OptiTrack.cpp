#include "OptiTrack.hpp"
#include <iostream>

OptiTrack::OptiTrack(std::string t_name, block_type t_type) : MotionCapture(t_name, t_type){
    Quaternion _bodyAtt;
    Vector3D _bodyPos;
    std::cout << "Optitrack constructor" << std::endl;
}

OptiTrack::~OptiTrack() {

}

Vector3D OptiTrack::getAttitude(){
    // Vector3D rpy = getEulerfromQuaternion(_bodyAtt);
    // rpy.z = 0.0;

    // std::cout << "getAttitude"<< std::endl;
    // std::cout << "roll: " << rpy.x << std::endl;
    // std::cout << "pitch: " << rpy.y << std::endl;
    // std::cout << "yaw: " << rpy.z << std::endl;

    // return rpy;
}

double OptiTrack::getHeading(){
    // Vector3D rpy = getEulerfromQuaternion(_bodyAtt);
    // rpy.x = 0.0;
    // rpy.y = 0.0; 

    // std::cout << "getHeading"<< std::endl;
    // std::cout << "roll: " << rpy.x << std::endl;
    // std::cout << "pitch: " << rpy.y << std::endl;
    // std::cout << "yaw: " << rpy.z << std::endl;

    // return rpy.z;
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

void OptiTrack::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::optitrack){

        OptitrackMessage* opti_msg = (OptitrackMessage*)t_msg;
        
        _bodyPos = opti_msg->getPosition();
        _bodyAtt = opti_msg->getAttitudeHeading();
    }
}