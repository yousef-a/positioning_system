#pragma once
#include "UserReference.hpp"
#include "ControlSystemMessage.hpp"

class Z_UserReference : public UserReference{

private:
    ControlSystemMessage m_output_msg;

public:

    void receive_msg_data(DataMessage*);
    
    Z_UserReference();
    ~Z_UserReference();
};