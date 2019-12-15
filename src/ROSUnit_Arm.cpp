#include "ROSUnit_Arm.hpp"
ROSUnit_Arm* ROSUnit_Arm::_instance_ptr = NULL;
BoolMessage ROSUnit_Arm::_bool_msg;

ROSUnit_Arm::ROSUnit_Arm(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _sub_armed = t_main_handler.subscribe("/armed", 10, callbackArm);
    _instance_ptr = this;
}   

ROSUnit_Arm::~ROSUnit_Arm() {

}

void ROSUnit_Arm::receive_msg_data(DataMessage* t_msg){


}

void ROSUnit_Arm::callbackArm(const std_msgs::Bool::ConstPtr& msg){

    bool data;
    data = msg->data;

    _bool_msg.setBoolMessage(data);
    std::cout << "ESTOU AQUIIIIIIIII %%%%%%%%%%%%%%%%%%%%%%%%%%         " << data <<  std::endl;
    _instance_ptr->emit_message((DataMessage*) &_bool_msg);

}