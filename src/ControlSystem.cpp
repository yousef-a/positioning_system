#include "ControlSystem.hpp"
#include "../include/Switcher.hpp"

ControlSystem::ControlSystem() {
    this->add_callback_msg_receiver((msg_receiver*)controllerSwitcher);
    this->add_callback_msg_receiver((msg_receiver*)referenceSwitcher);
    this->add_callback_msg_receiver((msg_receiver*)providerSwitcher);
    //TODO add the connections between the Switchers
}

ControlSystem::~ControlSystem() {

}

void ControlSystem::receive_msg_data(DataMessage* t_msg){


}

void ControlSystem::getStatus(){
    
    for(Switcher* s : _switchers){
        if(s->getActiveBlock() != nullptr){
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