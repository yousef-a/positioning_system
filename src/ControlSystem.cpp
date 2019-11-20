#include "ControlSystem.hpp"
#include "../include/Switcher.hpp"

ControlSystem::ControlSystem() {
    this->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
    this->add_callback_msg_receiver((msg_receiver*)referenceSwitcher);
    this->add_callback_msg_receiver((msg_receiver*)providerSwitcher);

}

ControlSystem::~ControlSystem() {

}

void ControlSystem::receive_msg_data(DataMessage* t_msg){


}

void ControlSystem::getStatus(){
    for(Switcher* s : _switchers){
        s->getStatus();
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
    SwitchMessage* switch_msg = new SwitchMessage(control_system_msg_type::switch_in_out, t_from, t_to);

    this->emit_message((DataMessage*)switch_msg);
}

void ControlSystem::addBlock(Block* t_block){
    SwitchMessage* add_block_msg = new SwitchMessage(control_system_msg_type::add_block, t_block);

    this->emit_message((DataMessage*)add_block_msg);

}