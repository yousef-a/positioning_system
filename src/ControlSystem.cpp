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

void ControlSystem::switchAtControllerBlock(Block* t_from, Block* t_to){
    SwitchMessage* switch_msg = new SwitchMessage(switcher_msg_type::controller, t_from, t_to);

    this->emit_message((DataMessage*)switch_msg);
}
void ControlSystem::switchAtReferenceBlock(Block* t_from, Block* t_to){
    SwitchMessage* switch_msg = new SwitchMessage(switcher_msg_type::reference, t_from, t_to);

    this->emit_message((DataMessage*)switch_msg);
}
void ControlSystem::switchAtProviderBlock(Block* t_from, Block* t_to){
    SwitchMessage* switch_msg = new SwitchMessage(switcher_msg_type::provider, t_from, t_to);

    this->emit_message((DataMessage*)switch_msg);
}