#include "ROSUnit_Optitrack.hpp"
#include <iostream>
ROSUnit_Optitrack* ROSUnit_Optitrack::_instance_ptr = NULL;

ROSUnit_Optitrack::ROSUnit_Optitrack(ros::NodeHandle&) {
    _sub_attitude = _main_handler.subscribe("/Robot_1/pose", 10, callbackOptitrack);
    _instance_ptr = this;
}

ROSUnit_Optitrack::~ROSUnit_Optitrack() {

}

void ROSUnit_Optitrack::callbackOptitrack(const geometry_msgs::PoseStamped& msg){

    double pos_data[3];
    pos_data[0] = msg.pose.position.x;
    pos_data[1] = msg.pose.position.y;
    pos_data[2] = msg.pose.position.z;
    double att_data[4];
    att_data[0] = msg.pose.orientation.x;
    att_data[1] = msg.pose.orientation.y;
    att_data[2] = msg.pose.orientation.z;
    att_data[3] = msg.pose.orientation.w;
    uint8_t* pos_data_ptr=(uint8_t*)&pos_data[0];
    uint8_t* att_data_ptr=(uint8_t*)&att_data[0];

    int pos_data_len = 56; //56 bytes for 7 double variables
    uint8_t serializedData[len_data];    

    for(int i = 0; i < len_data; i++){
        serializedData[i]=*((uint8_t*)data_ptr++);
    }

    _instance_ptr->emit_message(serializedData, len_data, msg_type::optitrack); 
}

void ROSUnit_Optitrack::receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type){


}