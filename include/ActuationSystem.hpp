#pragma once

#include "MsgEmitter.hpp"
#include "MsgReceiver.hpp"
#include "ControlSystemMessage.hpp"
#include "actuator.hpp"
#include <vector>

class ActuationSystem : public msg_emitter, public msg_receiver{

public:

    virtual void receive_msg_data(DataMessage* t_msg) = 0;
    
    ActuationSystem(std::vector<Actuator*>) {};
};