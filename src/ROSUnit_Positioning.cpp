#include "ROSUnit_Positioning.hpp"
#include <iostream>
ROSUnit_Positioning* ROSUnit_Positioning::instance_ptr=NULL;

ROSUnit_Positioning::ROSUnit_Positioning() {
    
}


ROSUnit_Positioning::~ROSUnit_Positioning(){

}

void ROSUnit_Positioning::setSubscribers(){

    sub_positioning = main_handler.subscribe("/Robot_1/pose", 10, callbackPositioning);

}


void ROSUnit_Positioning::callbackPositioning(const geometry_msgs::PoseStamped& msg){

    std::cout << msg.pose.position.x << std::endl;
    Vector3D _posXYZ;
 
    double tmp_double[3];
    tmp_double[0] = msg.pose.position.x;
    tmp_double[1] = msg.pose.position.y;
    tmp_double[2] = msg.pose.position.z;

    uint8_t* data_ptr=(uint8_t*)&tmp_double[0];
    uint8_t payload[sizeof(double) * 3];

    for(int i = 0; i < sizeof(double) * 3; i++){
        payload[i]=*((uint8_t*)data_ptr++);
    }
    
    std::cout << payload <<std::endl;

    //Workaround for accessing msg_type inside a static function
    instance_ptr->emit_message(payload, 3, msg_type::position);
    
}

void ROSUnit_Positioning::receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type){


}
