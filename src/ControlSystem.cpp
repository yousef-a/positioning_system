#include "ControlSystem.hpp"

ControlSystem::ControlSystem(control_system t_control_system, PVProvider* t_pvprovider, block_frequency t_bf) : TimedBlock(t_bf) {
    _control_system = t_control_system;
    
    controllerSwitcher = new Switcher(switcher_type::controller);
    referenceSwitcher = new Switcher(switcher_type::reference);
    _providerProcessVariable = t_pvprovider;
    _switchers = {controllerSwitcher, referenceSwitcher};
    _frequency = t_bf;
    _dt = 1.0f / (int)_frequency;

    this->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
    this->add_callback_msg_receiver((msg_receiver*)referenceSwitcher);
    referenceSwitcher->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
    controllerSwitcher->add_callback_msg_receiver((msg_receiver*)this);
}

ControlSystem::~ControlSystem() {

}

void ControlSystem::receive_msg_data(DataMessage* t_msg){
    // (2)
    if(t_msg->getType() == msg_type::switcher){

        SwitcherMessage* switcher_msg = (SwitcherMessage*)t_msg;

        m_output_msg.setControlSystemMessage(this->getControlSystemType(), control_system_msg_type::to_system, switcher_msg->getFloatData());

        this->emit_message((DataMessage*) &m_output_msg);

        //Emiting msg to ROSUnit
        m_ros_msg.setControlSystem(switcher_msg->getFloatData(), this->getControlSystemType());
        this->emit_message((DataMessage*) &m_ros_msg);
            
    // (3)
    }else if(t_msg->getType() == msg_type::control_system){

        ControlSystemMessage* control_system_msg = (ControlSystemMessage*)t_msg;
        //TODO make the naming more clear
        if(control_system_msg->getControlSystemMsgType() == control_system_msg_type::to_system){
            m_output_msg.setControlSystemMessage(this->getControlSystemType(), control_system_msg_type::SETREFERENCE, control_system_msg->getData());
            this->emit_message((DataMessage*) &m_output_msg);
        }//TODO add the update parameters msg

    }else if(t_msg->getType() == msg_type::SWITCHBLOCK){

        SwitchBlockMsg* switch_msg = (SwitchBlockMsg*)t_msg;
        this->emit_message((DataMessage*) switch_msg);
    }

}

control_system ControlSystem::getControlSystemType(){
    return _control_system;
}
//TODO remove
void ControlSystem::getStatus(){
    
    for(Switcher* s : _switchers){
        if(s->getActiveBlock() != nullptr){
            std::cout << "For Control System " << static_cast<int>(_control_system) << std::endl;
            std::cout << "For switcher " << (int)(s->getType()) << " the active block is " << (int)(s->getActiveBlock()->getID()) << std::endl;
        }     
    }
}

//TODO Provider msg_emitter, remove loopInternal
//(10)
void ControlSystem::loopInternal(){
    Vector3D<float> data = _providerProcessVariable->getProcessVariable();
    m_provider_data_msg.setControlSystemMessage(this->getControlSystemType(), control_system_msg_type::PROVIDER, data);

    this->emit_message((DataMessage*) &m_provider_data_msg);
}

void ControlSystem::addBlock(Block* t_block){
    m_add_block_msg.setControlSystemMessage(control_system_msg_type::add_block, t_block);

    this->emit_message((DataMessage*) &m_add_block_msg);
}