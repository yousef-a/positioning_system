#include "ROSUnit_Positioning.hpp"
#include <iostream>

ROSUnit_Positioning::ROSUnit_Positioning() {
    
}


ROSUnit_Positioning::~ROSUnit_Positioning(){

}

void ROSUnit_Positioning::setSubscribers(){

    sub_positioning = main_handler.subscribe("/Robot_1/pose", 10, callbackPositioning);

}


void ROSUnit_Positioning::callbackPositioning(const geometry_msgs::PoseStamped& msg){

    //std::cout << msg;
    Vector3D _posXYZ;
    
    double tmp_float = msg.pose.position.x;
    uint8_t* data_ptr=(uint8_t*)&tmp_float;
    uint8_t payload[3];
    payload[0]=*((uint8_t*)data_ptr++);
    payload[1]=*((uint8_t*)data_ptr++);
    payload[2]=*((uint8_t*)data_ptr++);

    std::cout << payload <<std::endl;

    //emit_message(payload, 3, msg_type::position);
}

void ROSUnit_Positioning::receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type){


}
