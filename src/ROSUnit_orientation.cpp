#include "ROSUnit_orientation.hpp"


ROSUnit_orientation* ROSUnit_orientation::_instance_ptr = NULL;
HeadingMsg ROSUnit_orientation::heading_msg;
AttitudeMsg ROSUnit_orientation::att_msg;

ROSUnit_orientation::ROSUnit_orientation(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler){
    _sub_orientation = t_main_handler.subscribe("/body_orientation", 10, callbackOrient);
    _instance_ptr = this;

}

ROSUnit_orientation::~ROSUnit_orientation() {

}

void ROSUnit_orientation::callbackOrient(const geometry_msgs::PointStamped::ConstPtr& msg)
{
    att_msg.roll = msg->point.x;
    att_msg.pitch = msg->point.y;
    heading_msg.yaw = msg->point.z;

    _instance_ptr->emit_message((DataMessage*) &att_msg); 
    _instance_ptr->emit_message((DataMessage*) &heading_msg); 
}

void ROSUnit_orientation::receive_msg_data(DataMessage* t_msg){
}