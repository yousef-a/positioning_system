#include "ControlSystem.hpp"
#include "../include/Switcher.hpp"

ControlSystem::ControlSystem() {

}

ControlSystem::~ControlSystem() {

}

void ControlSystem::receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type){


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