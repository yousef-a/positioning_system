#include "ROSUnit_Arm.hpp"
ROSUnit_Arm* ROSUnit_Arm::_instance_ptr = NULL;
BoolMessage ROSUnit_Arm::_bool_msg;
//TODO change to a Service
ROSUnit_Arm::ROSUnit_Arm(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _srv_armed = t_main_handler.advertiseService("arm", callbackArm);
    _instance_ptr = this;
}   

ROSUnit_Arm::~ROSUnit_Arm() {

}

void ROSUnit_Arm::receive_msg_data(DataMessage* t_msg){


}

bool ROSUnit_Arm::callbackArm(positioning_system::Arm::Request &req, positioning_system::Arm::Response &res){

    bool data;
    data = req.armed;

    _bool_msg.setBoolMessage(data);
    _instance_ptr->emit_message((DataMessage*) &_bool_msg);
    
    return true;
}