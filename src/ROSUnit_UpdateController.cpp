#include "ROSUnit_UpdateController.hpp"

//TODO rename the topics and class
ROSUnit_UpdateController* ROSUnit_UpdateController::_instance_ptr = NULL;
PID_parameters ROSUnit_UpdateController::_update_controller_msg;

ROSUnit_UpdateController::ROSUnit_UpdateController(ros::NodeHandle& t_main_handler, std::string t_name) : ROSUnit(t_main_handler) {
    _sub_update_controller_X = t_main_handler.subscribe("/X_CS/update_controller", 10, callbackUpdateController_X);
    _sub_update_controller_Y = t_main_handler.subscribe("/Y_CS/update_controller", 10, callbackUpdateController_Y);
    _sub_update_controller_Z = t_main_handler.subscribe("/Z_CS/update_controller", 10, callbackUpdateController_Z);
    _sub_update_controller_Roll = t_main_handler.subscribe("/Roll_CS/update_controller", 10, callbackUpdateController_Roll);
    _sub_update_controller_Pitch = t_main_handler.subscribe("/Pitch_CS/update_controller", 10, callbackUpdateController_Pitch);
    _sub_update_controller_Yaw = t_main_handler.subscribe("/Yaw_CS/update_controller", 10, callbackUpdateController_Yaw);
   
    _instance_ptr = this;
}   

ROSUnit_UpdateController::~ROSUnit_UpdateController() {

}

void ROSUnit_UpdateController::receive_msg_data(DataMessage* t_msg){


}

void ROSUnit_UpdateController::callbackUpdateController_X(const positioning_system::PID_param& msg){

    //TODO Send message received to User
    PID_parameters data;
    data.kp = msg.kp;
    data.ki = msg.ki;
    data.kd = msg.kd;
    data.kdd = msg.kdd;
    data.anti_windup = msg.anti_windup;
    data.en_pv_derivation = msg.en_pv_derivation;

    //user_msg.setUserMessage(pos_data.x, pos_data.y, pos_data.z, 0);
    //std::cout << "ESTOU AQUIIIIIIIII %%%%%%%%%%%%%%%%%%%%%%%%%%         " << pos_data.x <<  std::endl;
    //_instance_ptr->emit_message((DataMessage*) &user_msg);

}

void ROSUnit_UpdateController::callbackUpdateController_Y(const positioning_system::PID_param& msg){

}
void ROSUnit_UpdateController::callbackUpdateController_Z(const positioning_system::PID_param& msg){

}
void ROSUnit_UpdateController::callbackUpdateController_Roll(const positioning_system::PID_param& msg){

}
void ROSUnit_UpdateController::callbackUpdateController_Pitch(const positioning_system::PID_param& msg){

}
void ROSUnit_UpdateController::callbackUpdateController_Yaw(const positioning_system::PID_param& msg){

}