#pragma once
#include "MsgEmitter.hpp"
#include "MsgReceiver.hpp"
#include "ControlSystemMessage.hpp"

class ActuationSystem : public msg_emitter, public msg_receiver{

public:

    void receive_msg_data(DataMessage* t_msg);
    
    ActuationSystem();
    ~ActuationSystem();
};