#pragma once
#include "common_types.hpp"
#include "MsgEmitter.hpp"
#include "MsgReceiver.hpp"
#include "UserMessage.hpp"
#include "FlightScenarioMessage.hpp"

class User : public msg_emitter, public msg_receiver{

private:
    UserMessage _user_msg;

public:

    void receive_msg_data(DataMessage*);
    User();
    ~User();
};