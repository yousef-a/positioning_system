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
    
    Vector3D pos_data;
    pos_data.x = msg.pose.position.x;
    pos_data.y = msg.pose.position.y;
    pos_data.z = msg.pose.position.z;
    Quaternion att_data;
    att_data.x = msg.pose.orientation.x;
    att_data.y = msg.pose.orientation.y;
    att_data.z = msg.pose.orientation.z;
    att_data.w = msg.pose.orientation.w;

    OptitrackMessage* optitrack_msg = new OptitrackMessage(pos_data, att_data);

    _instance_ptr->emit_message((DataMessage*) optitrack_msg);   
}

void ROSUnit_Optitrack::receive_msg_data(DataMessage* t_msg){


}