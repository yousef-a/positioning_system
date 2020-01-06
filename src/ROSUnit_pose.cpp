#include "ROSUnit_pose.hpp"


ROSUnit_pose* ROSUnit_pose::_instance_ptr = NULL;
PositionMsg ROSUnit_pose::_position_msg;
AttitudeMsg ROSUnit_pose::_att_msg;
HeadingMsg ROSUnit_pose::_heading_msg;

ROSUnit_pose::ROSUnit_pose(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler){
    _sub_pose = t_main_handler.subscribe("/Transformed_Pose/OptitrackPose", 10, callbackPose);
    _instance_ptr = this;
}

ROSUnit_pose::~ROSUnit_pose() {

}

void ROSUnit_pose::callbackPose(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
    _position_msg.x = msg->pose.position.x;
    _position_msg.y = msg->pose.position.y;
    _position_msg.z = msg->pose.position.z;

    _att_msg.roll = msg->pose.orientation.y;
    _att_msg.pitch = msg->pose.orientation.x;

    _heading_msg.yaw = msg->pose.orientation.z;

    _instance_ptr->emit_message((DataMessage*) &_position_msg); 
    _instance_ptr->emit_message((DataMessage*) &_att_msg); 
    _instance_ptr->emit_message((DataMessage*) &_heading_msg); 
}

void ROSUnit_pose::receive_msg_data(DataMessage* t_msg)
{

};  