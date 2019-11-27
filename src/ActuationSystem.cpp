#include "ActuationSystem.hpp"

ActuationSystem::ActuationSystem() {

}

ActuationSystem::~ActuationSystem() {

}

void ActuationSystem::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::control_system){
        ControlSystemMessage* control_system_msg = (ControlSystemMessage*)t_msg;
        if(control_system_msg->getControlSystemMsgType() == control_system_msg_type::to_system){
            if(control_system_msg->getSource() == control_system::pitch){
             std::cout << "..................ACTUATION SYSTEM RECEIVED THE MESSAGE FROM PITCH" << std::endl;  
            }
        }
          
    }
}