#include "ROSUnit_Positioning.hpp"
#include <iostream>
ROSUnit_Positioning* ROSUnit_Positioning::instance_ptr = NULL;

ROSUnit_Positioning::ROSUnit_Positioning() {
    
}


ROSUnit_Positioning::~ROSUnit_Positioning(){

}

void ROSUnit_Positioning::setSubscribers(){

    sub_positioning = main_handler.subscribe("/Robot_1/pose", 10, callbackPositioning);
    instance_ptr = this;
}


void ROSUnit_Positioning::callbackPositioning(const geometry_msgs::PoseStamped& msg){

    double data[3];
    data[0] = msg.pose.position.x;
    data[1] = msg.pose.position.y;
    data[2] = msg.pose.position.z;
/*
    uint8_t* data_ptr=(uint8_t*)&tmp_double[0];
    uint8_t payload[sizeof(double) * 3];


    for(int i = 0; i < sizeof(double) * 3; i++){
        payload[i]=*((uint8_t*)data_ptr++);
    }
 */   
    //std::cout << sizeof(data) << std::endl;
    uint8_t serializedData[sizeof(data)];
    int numVariables = sizeof(data) / sizeof(data[0]);

    //instance_ptr is a workaround for accessing non-static function inside static
    instance_ptr->serializeData(data, numVariables, serializedData);
    instance_ptr->emit_message(serializedData, 24, msg_type::position);    
}

void ROSUnit_Positioning::receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type){


}
