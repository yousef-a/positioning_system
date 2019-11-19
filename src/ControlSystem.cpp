#include "ControlSystem.hpp"
#include "../include/Switcher.hpp"

ControlSystem::ControlSystem() {

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

Switcher* ControlSystem::getObserverSwitcher(){
    return observerSwitcher;
}