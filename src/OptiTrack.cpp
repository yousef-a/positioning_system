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

    std::cout << "Hello, I am OptiTrack Position\n";
    Vector3D data;
    data.x = 0;
    data.y = 1;
    data.z = 0;
    
    return data;
}

void OptiTrack::receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type){
    
    //double _position[3];
    //uint8_t* tmp_ptr = (uint8_t*) &data[0];

    //for(int i = 0; i < len/sizeof(double); i++){
    //    _position[i] = *((double *) tmp_ptr[i]);
    //}
    std::cout << "Receive Data Pos\n"; 
    //_bodyPos.x = _position[0];
    //_bodyPos.y = _position[1];
    //_bodyPos.z = _position[2];
    
}