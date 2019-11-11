#include "ControlSystem.hpp"
#include "../include/Switcher.hpp"

ControlSystem::ControlSystem() {
    
}

ControlSystem::~ControlSystem() {

}

void ControlSystem::receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type){


}

void ControlSystem::getStatus(){
    for(_it=_switchers.begin(); _it!=_switchers.end(); ++_it){
        (*_it)->getStatus();
    }
}