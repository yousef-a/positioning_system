#include "ROSUnit_Attitude.hpp"
#include <iostream>
ROSUnit_Attitude* ROSUnit_Attitude::instance_ptr = NULL;

ROSUnit_Attitude::ROSUnit_Attitude(ros::NodeHandle&) {

    _sub_attitude = main_handler.subscribe("/Robot_1/pose", 10, callbackAttitude);
    instance_ptr = this;
}


ROSUnit_Attitude::~ROSUnit_Attitude(){

}

void ROSUnit_Attitude::callbackAttitude(const geometry_msgs::PoseStamped& msg){

    double data[4];
    data[0] = msg.pose.orientation.x;
    data[1] = msg.pose.orientation.y;
    data[2] = msg.pose.orientation.z;
    data[3] = msg.pose.orientation.w;

    uint8_t serializedData[4 + sizeof(data)]; //TODO send msg_type_optitrack::attitude as the first byte of the serialiazedData
    const int numVariables = sizeof(data) / sizeof(data[0]);
    //instance_ptr is a workaround for accessing non-static function inside static
    //instance_ptr->serializeData(data, numVariables, serializedData);

    std::cout << "Size of msg MAMAMMAMAMAMAM: " << sizeof(msg_type) << std::endl;
    uint8_t* data_ptr=(uint8_t*)&data[0];
    //uint8_t* msg_ptr=(uint8_t*)&msg_type_optitrack::attitude;
    msg_type_optitrack _msg_type_optitrack = msg_type_optitrack::attitude;
    uint8_t* msg_ptr=(uint8_t*)&_msg_type_optitrack;

    serializedData[0] = *msg_ptr++;
    serializedData[1] = *msg_ptr++;
    serializedData[2] = *msg_ptr++;
    serializedData[3] = *msg_ptr++;

    for(int i = 4; i < 4 + numVariables * sizeof(double); i++){
        serializedData[i]=*((uint8_t*)data_ptr++);
    }

    instance_ptr->emit_message(serializedData, 4+sizeof(data), msg_type::optitrack); 
      
}

void ROSUnit_Attitude::receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type){


}
