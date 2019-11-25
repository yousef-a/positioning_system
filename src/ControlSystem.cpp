#include "ControlSystem.hpp"
#include "../include/Switcher.hpp"

ControlSystem::ControlSystem() {
    // this->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
    // this->add_callback_msg_receiver((msg_receiver*)referenceSwitcher);
    // this->add_callback_msg_receiver((msg_receiver*)providerSwitcher);
    // providerSwitcher->add_callback_msg_receiver((msg_receiver*)referenceSwitcher);
    // referenceSwitcher->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
    // controllerSwitcher->add_callback_msg_receiver((msg_receiver*)this);
    
}

ControlSystem::ControlSystem(control_system t_control_system) {
    _control_system = t_control_system;
    
    controllerSwitcher = new Switcher("ControlSwitcher", switcher_type::controller, _control_system);
    referenceSwitcher = new Switcher("ReferenceSwitcher", switcher_type::reference, _control_system);
    providerSwitcher = new Switcher("ProviderSwitcher", switcher_type::provider, _control_system);
    _switchers = {controllerSwitcher, referenceSwitcher, providerSwitcher};
    
    this->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
    this->add_callback_msg_receiver((msg_receiver*)referenceSwitcher);
    this->add_callback_msg_receiver((msg_receiver*)providerSwitcher);
    providerSwitcher->add_callback_msg_receiver((msg_receiver*)referenceSwitcher);
    referenceSwitcher->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
    controllerSwitcher->add_callback_msg_receiver((msg_receiver*)this);
}

ControlSystem::~ControlSystem() {

}

void ControlSystem::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::user){

        UserMessage* user_msg = (UserMessage*)t_msg;
        //TODO add mask to ignore msgs
        if(this->getControlSystemType() == control_system::x){
            FloatMessage* user_data_x = new FloatMessage(user_msg->getX());
            std::cout << "Msg received from User. Sending to X Control System" << std::endl;
            this->emit_message((DataMessage*)user_data_x);

        }else if(this->getControlSystemType() == control_system::y){
            
        }else if(this->getControlSystemType() == control_system::z){

        }else if(this->getControlSystemType() == control_system::yaw){

        }

    }else if(t_msg->getType() == msg_type::switcher){

        SwitcherMessage* switcher_msg = (SwitcherMessage*)t_msg;

        if(switcher_msg->getSource() == switcher_type::controller
            && switcher_msg->getDestination() == switcher_type::null_type
            && switcher_msg->getInternalType() == internal_switcher_type::controller){
                
                ControlSystemMessage* output = new ControlSystemMessage(this->getControlSystemType(), control_system::pitch, 
                                                                        control_system_msg_type::to_control_system, switcher_msg->getFloatData());

                std::cout << "Message from Controller Switcher to X" << std::endl;

                this->emit_message((DataMessage*)output);

            }
    }else if(t_msg->getType() == msg_type::control_system){

        ControlSystemMessage* control_system_msg = (ControlSystemMessage*)t_msg;

        if(control_system_msg->getSource() == control_system::x
            && control_system_msg->getDestination() == this->getControlSystemType()
            && control_system_msg->getControlSystemMsgType() == control_system_msg_type::to_control_system){
            
            FloatMessage* output_from_x_to_pitch = new FloatMessage(control_system_msg->getData());

            std::cout << "Message from X to Pitch" << std::endl;
            
            this->emit_message((DataMessage*)output_from_x_to_pitch);

        }

    }

}

control_system ControlSystem::getControlSystemType(){
    return _control_system;
}

void ControlSystem::getStatus(){
    
    for(Switcher* s : _switchers){
        if(s->getActiveBlock() != nullptr){
            std::cout << "For Control System " << static_cast<int>(_control_system) << std::endl;
            std::cout << "For switcher " << s->getName() << " the active block is " << s->getActiveBlock()->getName() << std::endl;
        }     
    }
}

Switcher* ControlSystem::getControllerSwitcher(){
    return controllerSwitcher;
}

Switcher* ControlSystem::getReferenceSwitcher(){
    return referenceSwitcher;
}

Switcher* ControlSystem::getProviderSwitcher(){
    return providerSwitcher;
}

void ControlSystem::switchBlock(Block* t_from, Block* t_to){
    ControlSystemMessage* switch_msg = new ControlSystemMessage(control_system_msg_type::switch_in_out, t_from, t_to);
    
    this->emit_message((DataMessage*)switch_msg);
}

void ControlSystem::addBlock(Block* t_block){
    ControlSystemMessage* add_block_msg = new ControlSystemMessage(control_system_msg_type::add_block, t_block);

    this->emit_message((DataMessage*)add_block_msg);

}

void ControlSystem::changePIDSettings(PID_parameters* t_pid_para){ //TODO refactor through receive_msg, a remote msg should change the pid

    ControlSystemMessage* change_PID_msg = new ControlSystemMessage(control_system_msg_type::change_PID_settings, t_pid_para);

    this->emit_message((DataMessage*)change_PID_msg);

}