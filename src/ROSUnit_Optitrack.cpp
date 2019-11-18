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
    
    uint8_t* pos_data_ptr=(uint8_t*)&pos_data[0];

    msg_type_optitrack _msg_type_position = msg_type_optitrack::position;
    uint8_t* msg_ptr_pos=(uint8_t*)&_msg_type_position;

    int pos_data_len = 28; //4 bytes for msg_type + 24 bytes for 3 double variables
    uint8_t serializedDataPos[pos_data_len];    

    serializedDataPos[0] = *msg_ptr_pos++;
    serializedDataPos[1] = *msg_ptr_pos++;
    serializedDataPos[2] = *msg_ptr_pos++;
    serializedDataPos[3] = *msg_ptr_pos++;
    for(int i = 4; i < pos_data_len; i++){
        serializedDataPos[i]=*((uint8_t*)msg_ptr_pos++);
    }

    _instance_ptr->emit_message(serializedDataPos, pos_data_len, msg_type::optitrack); 

    double att_data[4];
    att_data[0] = msg.pose.orientation.x;
    att_data[1] = msg.pose.orientation.y;
    att_data[2] = msg.pose.orientation.z;
    att_data[3] = msg.pose.orientation.w;

    uint8_t* att_data_ptr=(uint8_t*)&att_data[0];
    msg_type_optitrack _msg_type_attitude = msg_type_optitrack::attitude;
    uint8_t* msg_ptr_att=(uint8_t*)&_msg_type_attitude;

    int att_data_len = 36; //4 bytes for msg_type + 32 bytes for 4 double variables
    uint8_t serializedDataAtt[att_data_len];    

    serializedDataAtt[0] = *msg_ptr_att++;
    serializedDataAtt[1] = *msg_ptr_att++;
    serializedDataAtt[2] = *msg_ptr_att++;
    serializedDataAtt[3] = *msg_ptr_att++;
    for(int i = 4; i < att_data_len; i++){
        serializedDataAtt[i]=*((uint8_t*)msg_ptr_att++);
    }

    _instance_ptr->emit_message(serializedDataAtt, att_data_len, msg_type::optitrack); 

}

void ROSUnit_Optitrack::receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type){


}