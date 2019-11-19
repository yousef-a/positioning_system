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
    msg_type_optitrack _msg_type_optitrack = msg_type_optitrack::position;
    uint8_t* pos_msg_ptr=(uint8_t*)&_msg_type_optitrack;
    int pos_len_data = 28; //4 bytes for msg_type + 24 bytes for 3 double variables
    uint8_t serializedDataPos[pos_len_data];    

    serializedDataPos[0] = *pos_msg_ptr++;
    serializedDataPos[1] = *pos_msg_ptr++;
    serializedDataPos[2] = *pos_msg_ptr++;
    serializedDataPos[3] = *pos_msg_ptr++;

    for(int i = 4; i < pos_len_data; i++){
        serializedDataPos[i]=*((uint8_t*)pos_data_ptr++);
    }

    _instance_ptr->emit_message(serializedDataPos, pos_len_data, msg_type::optitrack);   

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
        serializedDataAtt[i]=*((uint8_t*)att_data_ptr++);
    }

    _instance_ptr->emit_message(serializedDataAtt, att_data_len, msg_type::optitrack); 

}

void ROSUnit_Optitrack::receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type){


}