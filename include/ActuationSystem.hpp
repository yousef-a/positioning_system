#pragma once
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"
#include "DataMessage.hpp"
#include "actuator.hpp"
#include <vector>

class ActuationSystem : public msg_emitter, public msg_receiver{

public:

    virtual void receive_msg_data(DataMessage* t_msg) = 0;
    
    ActuationSystem(std::vector<Actuator*>) {};
};