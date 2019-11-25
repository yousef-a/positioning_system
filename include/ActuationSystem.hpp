#pragma once
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"
#include "ControlSystemMessage.hpp"

class ActuationSystem : public msg_emitter, public msg_receiver{

public:

    void receive_msg_data(DataMessage* t_msg);
    
    ActuationSystem();
    ~ActuationSystem();
};