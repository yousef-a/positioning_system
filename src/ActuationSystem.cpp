#include "ActuationSystem.hpp"

ActuationSystem::ActuationSystem() {

}

ActuationSystem::~ActuationSystem() {

}

void ActuationSystem::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::control_system){
        ControlSystemMessage* control_system_msg = (ControlSystemMessage*)t_msg;
        if(control_system_msg->getControlSystemMsgType() == control_system_msg_type::to_system){
            
            switch (control_system_msg->getSource())
            {
            case control_system::pitch:
            {
                std::cout << "..................ACTUATION SYSTEM RECEIVED THE MESSAGE FROM PITCH" << std::endl; 
                break;
            }
            case control_system::roll:
            {
                std::cout << "..................ACTUATION SYSTEM RECEIVED THE MESSAGE FROM ROLL" << std::endl; 
                break;
            }
            case control_system::yaw:
            {
                std::cout << "..................ACTUATION SYSTEM RECEIVED THE MESSAGE FROM YAW" << std::endl; 
                break;
            }
            case control_system::x:
            {
                std::cout << "..................ACTUATION SYSTEM RECEIVED THE MESSAGE FROM X" << std::endl; 
                break;
            }
            case control_system::y:
            {
                std::cout << "..................ACTUATION SYSTEM RECEIVED THE MESSAGE FROM Y" << std::endl; 
                break;
            }
            case control_system::z:
            {
                std::cout << "..................ACTUATION SYSTEM RECEIVED THE MESSAGE FROM Z" << std::endl; 
                break;
            }
            default:
                break;
            }
            
        }
          
    }
}