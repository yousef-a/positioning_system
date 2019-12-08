#include "ControlSystem.hpp"

// ControlSystem::ControlSystem() : TimedBlock(t_bf) {
//     // this->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
//     // this->add_callback_msg_receiver((msg_receiver*)referenceSwitcher);
//     // this->add_callback_msg_receiver((msg_receiver*)providerSwitcher);
//     // providerSwitcher->add_callback_msg_receiver((msg_receiver*)referenceSwitcher);
//     // referenceSwitcher->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
//     // controllerSwitcher->add_callback_msg_receiver((msg_receiver*)this);
    
// }

ControlSystem::ControlSystem(control_system t_control_system, GeneralStateProvider* t_g_s_provider, block_frequency t_bf) : TimedBlock(t_bf) {
    _control_system = t_control_system;
    
    controllerSwitcher = new Switcher("ControlSwitcher", switcher_type::controller, _control_system);
    referenceSwitcher = new Switcher("ReferenceSwitcher", switcher_type::reference, _control_system);
    _providerProcessVariable = t_g_s_provider;
    _switchers = {controllerSwitcher, referenceSwitcher};
    
    this->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
    this->add_callback_msg_receiver((msg_receiver*)referenceSwitcher);
    referenceSwitcher->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
    controllerSwitcher->add_callback_msg_receiver((msg_receiver*)this);
}

ControlSystem::~ControlSystem() {

}

void ControlSystem::receive_msg_data(DataMessage* t_msg){
    // (1)
    if(t_msg->getType() == msg_type::user){
        //TODO if the control_system is equal to the user message getchannel
        UserMessage* user_msg = (UserMessage*)t_msg;
        //TODO add mask to ignore msgs
        if(this->getControlSystemType() == control_system::x){
            ReferenceMessage* user_data_x = new ReferenceMessage(user_msg->getX());
            std::cout << "Msg received from User. Sending to X Control System" << std::endl;
            this->emit_message((DataMessage*)user_data_x);

        }else if(this->getControlSystemType() == control_system::y){
            ReferenceMessage* user_data_y = new ReferenceMessage(user_msg->getY());
            std::cout << "Msg received from User. Sending to Y Control System" << std::endl;
            this->emit_message((DataMessage*)user_data_y);

        }else if(this->getControlSystemType() == control_system::z){
            ReferenceMessage* user_data_z = new ReferenceMessage(user_msg->getZ());
            std::cout << "Msg received from User. Sending to Z Control System" << std::endl;
            this->emit_message((DataMessage*)user_data_z);

        }else if(this->getControlSystemType() == control_system::yaw){
            ReferenceMessage* user_data_yaw = new ReferenceMessage(user_msg->getYaw());
            std::cout << "Msg received from User. Sending to Yaw Control System" << std::endl;
            this->emit_message((DataMessage*)user_data_yaw);

        }
    // (2)
    }else if(t_msg->getType() == msg_type::switcher){

        SwitcherMessage* switcher_msg = (SwitcherMessage*)t_msg;

        ControlSystemMessage* output = new ControlSystemMessage(this->getControlSystemType(), control_system_msg_type::to_system, 
                                                                switcher_msg->getVector3DData());

        this->emit_message((DataMessage*)output);
            
    // (3)
    }else if(t_msg->getType() == msg_type::control_system){

        ControlSystemMessage* control_system_msg = (ControlSystemMessage*)t_msg;

        if(control_system_msg->getControlSystemMsgType() == control_system_msg_type::to_system){
            
            ReferenceMessage* output = new ReferenceMessage(control_system_msg->getV3DData());
            
            this->emit_message((DataMessage*)output);
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

void ControlSystem::loopInternal(){
    Vector3D data = _providerProcessVariable->getProcessVariable(this->getControlSystemType());
    ControlSystemMessage* provider_data_msg = new ControlSystemMessage(this->getControlSystemType(), control_system_msg_type::provider_data, data);

    this->emit_message((DataMessage*)provider_data_msg);
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