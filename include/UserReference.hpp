#pragma once
#include "common_types.hpp"
#include "MsgEmitter.hpp"
#include "MsgReceiver.hpp"
#include "UserReferenceMessage.hpp"
#include "FlightScenarioMessage.hpp"

class UserReference : public msg_emitter, public msg_receiver{

private:
    UserReferenceMessage _user_msg;

public:

    virtual void receive_msg_data(DataMessage*) = 0;

    UserReference();
    ~UserReference();
};