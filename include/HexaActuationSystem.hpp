#pragma once
#include "ActuationSystem.hpp"
#include "ControlSystemMessage.hpp"

class HexaActuationSystem : public ActuationSystem {

private:    
    std::list<Actuator*> _actuators;

public:

    void receive_msg_data(DataMessage* t_msg);
    
    HexaActuationSystem(std::list<Actuator*>);
    ~HexaActuationSystem();
};