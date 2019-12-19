#include "ROSUnit_UpdateReference.hpp"

//TODO rename the topics and class
ROSUnit_UpdateReference* ROSUnit_UpdateReference::_instance_ptr = NULL;
UpdatePoseMessage ROSUnit_UpdateReference::user_msg;

ROSUnit_UpdateReference::ROSUnit_UpdateReference(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _sub_setpoint = t_main_handler.subscribe("/setpoint_position/local", 10, callbackSetpoint);
    _instance_ptr = this;
}   

ROSUnit_UpdateReference::~ROSUnit_UpdateReference() {

}

void ROSUnit_UpdateReference::receive_msg_data(DataMessage* t_msg){


}

void ROSUnit_UpdateReference::callbackSetpoint(const positioning_system::Waypoint& msg){

    float x, y, z, yaw;
    x = msg.x;
    y = msg.y;
    z = msg.z;
    yaw = msg.yaw;

    user_msg.setPoseMessage(x, y, z, yaw);

    _instance_ptr->emit_message((DataMessage*) &user_msg);

}