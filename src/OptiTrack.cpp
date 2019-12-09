#include "OptiTrack.hpp"
#include <iostream>

OptiTrack::OptiTrack(std::string t_name, block_type t_type) : MotionCapture(t_name, t_type){
    Quaternion _bodyAtt;
    Vector3D _bodyPos;
    // std::cout << "Optitrack constructor" << std::endl;
}

OptiTrack::~OptiTrack() {

}

AttitudeMsg OptiTrack::getAttitude(){
    Vector3D rpy = getEulerfromQuaternion(_bodyAtt);
    AttitudeMsg t_att_msg;
    t_att_msg.roll = rpy.x;
    t_att_msg.pitch = rpy.y;
    //rpy.z = 0.0;

    // std::cout << "getAttitude"<< std::endl;
    // std::cout << "roll: " << rpy.x << std::endl;
    // std::cout << "pitch: " << rpy.y << std::endl;
    // std::cout << "yaw: " << rpy.z << std::endl;

    return t_att_msg;
}

HeadingMsg OptiTrack::getHeading(){
    Vector3D rpy = getEulerfromQuaternion(_bodyAtt);
    HeadingMsg t_heading_msg;
    t_heading_msg.yaw = rpy.z;
    rpy.x = 0.0;
    rpy.y = 0.0; 

    // std::cout << "getHeading"<< std::endl;
    // // std::cout << "roll: " << rpy.x << std::endl;
    // // std::cout << "pitch: " << rpy.y << std::endl;
    // std::cout << "yaw: " << rpy.z << std::endl;

    return t_heading_msg;
}

Quaternion OptiTrack::getAttitudeHeading(){

    // std::cout << "getAttitudeHeading"<< std::endl;
    // std::cout << "x: " << _bodyAtt.x << std::endl;
    // std::cout << "y: " << _bodyAtt.y << std::endl;
    // std::cout << "z: " << _bodyAtt.z << std::endl;
    // std::cout << "w: " << _bodyAtt.w << std::endl;
    
    return _bodyAtt;
}

PositionMsg OptiTrack::getPosition(){

    PositionMsg t_pos_msg;
    t_pos_msg.x = _bodyPos.x;
    t_pos_msg.y = _bodyPos.y;
    t_pos_msg.z = _bodyPos.z;
    // std::cout << "getPosition"<< std::endl;
    // std::cout << "x: " << _bodyPos.x << std::endl;
    // std::cout << "y: " << _bodyPos.y << std::endl;
    // std::cout << "z: " << _bodyPos.z << std::endl;
    
    return t_pos_msg;
}

void OptiTrack::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::optitrack){

        OptitrackMessage* opti_msg = (OptitrackMessage*)t_msg;
        
        _bodyPos = opti_msg->getPosition();
        _bodyAtt = opti_msg->getAttitudeHeading();
    }
}

Vector3D OptiTrack::getEulerfromQuaternion(Quaternion q){

    // roll (x-axis rotation)
    double sinr_cosp = +2.0 * (q.w * q.x + q.y * q.z);
    double cosr_cosp = +1.0 - 2.0 * (q.x * q.x + q.y * q.y);
    _euler.x = atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = +2.0 * (q.w * q.y - q.z * q.x);
    if (fabs(sinp) >= 1)
        _euler.y = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        _euler.y = asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = +2.0 * (q.w * q.z + q.x * q.y);
    double cosy_cosp = +1.0 - 2.0 * (q.y * q.y + q.z * q.z);  
    _euler.z = atan2(siny_cosp, cosy_cosp);

    return _euler;
}

Quaternion OptiTrack::getQuaternionfromEuler(Vector3D euler){
    
    double roll = euler.x;
    double pitch = euler.y;
    double yaw = euler.z;

    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);

    _quat.w = cy * cp * cr + sy * sp * sr;
    _quat.x = cy * cp * sr - sy * sp * cr;
    _quat.y = sy * cp * sr + cy * sp * cr;
    _quat.z = sy * cp * cr - cy * sp * sr;
    
    return _quat;
}