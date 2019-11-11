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

    double data[7];
    data[0] = msg.pose.position.x;
    data[1] = msg.pose.position.y;
    data[2] = msg.pose.position.z;
    data[3] = msg.pose.orientation.x;
    data[4] = msg.pose.orientation.y;
    data[5] = msg.pose.orientation.z;
    data[6] = msg.pose.orientation.w;
    uint8_t* data_ptr=(uint8_t*)&data[0];

    int len_data = 56; //56 bytes for 7 double variables
    uint8_t serializedData[len_data];    

    for(int i = 0; i < len_data; i++){
        serializedData[i]=*((uint8_t*)data_ptr++);
    }

    _instance_ptr->emit_message(serializedData, len_data, msg_type::optitrack); 
}

void ROSUnit_Optitrack::receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type){


}