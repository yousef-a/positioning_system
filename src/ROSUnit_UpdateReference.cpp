#include "ROSUnit_UpdateReference.hpp"

//TODO rename the topics and class
ROSUnit_UpdateReference* ROSUnit_UpdateReference::_instance_ptr = NULL;
UserMessage ROSUnit_UpdateReference::user_msg;

ROSUnit_UpdateReference::ROSUnit_UpdateReference(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _sub_setpoint = t_main_handler.subscribe("/setpoint_position", 10, callbackSetpoint);
    _instance_ptr = this;
}   

ROSUnit_UpdateReference::~ROSUnit_UpdateReference() {

}

void ROSUnit_UpdateReference::receive_msg_data(DataMessage* t_msg){


}

void ROSUnit_UpdateReference::callbackSetpoint(const geometry_msgs::PoseStamped& msg){

    //TODO Send message received to User
    Vector3D<float> pos_data;
    pos_data.x = msg.pose.position.x;
    pos_data.y = msg.pose.position.y;
    pos_data.z = msg.pose.position.z;

    user_msg.setUserMessage(pos_data.x, pos_data.y, pos_data.z, 0);
    _instance_ptr->emit_message((DataMessage*) &user_msg);

}