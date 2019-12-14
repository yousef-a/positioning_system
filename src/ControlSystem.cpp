#include "ControlSystem.hpp"

ControlSystem::ControlSystem(control_system t_control_system, PVProvider* t_pvprovider, block_frequency t_bf) : TimedBlock(t_bf) {
    _control_system = t_control_system;
    
    controllerSwitcher = new Switcher("ControlSwitcher", switcher_type::controller, _control_system);
    referenceSwitcher = new Switcher("ReferenceSwitcher", switcher_type::reference, _control_system);
    _providerProcessVariable = t_pvprovider;
    _switchers = {controllerSwitcher, referenceSwitcher};
    _frequency = t_bf;
    _dt = 1 / (int)_frequency;
    
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
        UserReferenceMessage* user_msg = (UserReferenceMessage*)t_msg;
        //TODO add mask to ignore msgs
        if(this->getControlSystemType() == control_system::x){
            m_output_msg.setControlSystemMessage(this->getControlSystemType(), control_system_msg_type::SETREFERENCE, user_msg->getX());
            std::cout << "Msg received from User. Sending to X Control System: " << user_msg->getX() << std::endl;
            this->emit_message((DataMessage*) &m_output_msg);

        }else if(this->getControlSystemType() == control_system::y){
            m_output_msg.setControlSystemMessage(this->getControlSystemType(), control_system_msg_type::SETREFERENCE, user_msg->getY());
            std::cout << "Msg received from User. Sending to Y Control System: " << user_msg->getY() << std::endl;
            this->emit_message((DataMessage*) &m_output_msg);

        }else if(this->getControlSystemType() == control_system::z){
            m_output_msg.setControlSystemMessage(this->getControlSystemType(), control_system_msg_type::SETREFERENCE, user_msg->getZ());
            std::cout << "Msg received from User. Sending to Z Control System: " << user_msg->getZ() << std::endl;
            this->emit_message((DataMessage*) &m_output_msg);

        }else if(this->getControlSystemType() == control_system::yaw){
            m_output_msg.setControlSystemMessage(this->getControlSystemType(), control_system_msg_type::SETREFERENCE, user_msg->getYaw());
            std::cout << "Msg received from User. Sending to Yaw Control System: " << user_msg->getYaw() << std::endl;
            this->emit_message((DataMessage*) &m_output_msg);
        }
    // (2)
    }else if(t_msg->getType() == msg_type::switcher){

        SwitcherMessage* switcher_msg = (SwitcherMessage*)t_msg;

        m_output_msg.setControlSystemMessage(this->getControlSystemType(), control_system_msg_type::to_system, switcher_msg->getFloatData());

        this->emit_message((DataMessage*) &m_output_msg);
            
    // (3)
    }else if(t_msg->getType() == msg_type::control_system){

        ControlSystemMessage* control_system_msg = (ControlSystemMessage*)t_msg;

        if(control_system_msg->getControlSystemMsgType() == control_system_msg_type::to_system){
            m_output_msg.setControlSystemMessage(this->getControlSystemType(), control_system_msg_type::SETREFERENCE, control_system_msg->getData());
            this->emit_message((DataMessage*) &m_output_msg);
        }
        
        

    }

}

control_system ControlSystem::getControlSystemType(){
    return _control_system;
}
//TODO remove
void ControlSystem::getStatus(){
    
    for(Switcher* s : _switchers){
        if(s->getActiveBlock() != nullptr){
            // std::cout << "For Control System " << static_cast<int>(_control_system) << std::endl;
            // std::cout << "For switcher " << s->getName() << " the active block is " << s->getActiveBlock()->getName() << std::endl;
        }     
    }
}

Switcher* ControlSystem::getControllerSwitcher(){
    return controllerSwitcher;
}

Switcher* ControlSystem::getReferenceSwitcher(){
    return referenceSwitcher;
}

//TODO Provider msg_emitter, remove loopInternal
//(10)
void ControlSystem::loopInternal(){
    //UNDER MAINTENANCE
    Vector3D<float> data = _providerProcessVariable->getProcessVariable();
    m_provider_data_msg.setControlSystemMessage(this->getControlSystemType(), control_system_msg_type::provider_data, data);

    this->emit_message((DataMessage*) &m_provider_data_msg);
}

void ControlSystem::switchBlock(Block* t_from, Block* t_to){
    m_switch_msg.setControlSystemMessage(control_system_msg_type::switch_in_out, t_from, t_to);
    
    this->emit_message((DataMessage*) &m_switch_msg);
}

void ControlSystem::addBlock(Block* t_block){
    m_add_block_msg.setControlSystemMessage(control_system_msg_type::add_block, t_block);

    this->emit_message((DataMessage*) &m_add_block_msg);
}

void ControlSystem::changePIDSettings(PID_parameters* t_pid_para){ //TODO refactor through receive_msg, a remote msg should change the pid

    t_pid_para->dt = _dt;
    m_change_PID_msg.setControlSystemMessage(control_system_msg_type::change_PID_settings, t_pid_para);

    this->emit_message((DataMessage*) &m_change_PID_msg);
}