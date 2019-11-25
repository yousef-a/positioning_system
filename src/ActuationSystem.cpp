#include "ActuationSystem.hpp"

ActuationSystem::ActuationSystem() {

}

ActuationSystem::~ActuationSystem() {

}

void ActuationSystem::receive_msg_data(DataMessage* t_msg){

    std::cout << "ACTUATION SYSTEM RECEIVED THE MESSAGE" << std::endl;
}