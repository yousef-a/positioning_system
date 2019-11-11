#include "ROSUnit_Positioning.hpp"
#include <iostream>
ROSUnit_Positioning* ROSUnit_Positioning::instance_ptr = NULL;

ROSUnit_Positioning::ROSUnit_Positioning(ros::NodeHandle&) {

    sub_positioning = _main_handler.subscribe("/Robot_1/pose", 10, callbackPositioning);
    instance_ptr = this;
}


ROSUnit_Positioning::~ROSUnit_Positioning(){

}

void ROSUnit_Positioning::callbackPositioning(const geometry_msgs::PoseStamped& msg){ 

    double data[3];
    data[0] = msg.pose.position.x;
    data[1] = msg.pose.position.y;
    data[2] = msg.pose.position.z;
    uint8_t* data_ptr=(uint8_t*)&data[0];
    msg_type_optitrack _msg_type_optitrack = msg_type_optitrack::position;
    uint8_t* msg_ptr=(uint8_t*)&_msg_type_optitrack;
    int len_data = 28; //4 bytes for msg_type + 24 bytes for 3 double variables
    uint8_t serializedData[len_data];    

    serializedData[0] = *msg_ptr++;
    serializedData[1] = *msg_ptr++;
    serializedData[2] = *msg_ptr++;
    serializedData[3] = *msg_ptr++;

    for(int i = 4; i < len_data; i++){
        serializedData[i]=*((uint8_t*)data_ptr++);
    }

    instance_ptr->emit_message(serializedData, len_data, msg_type::optitrack);   
}

void ROSUnit_Positioning::receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type){


}
