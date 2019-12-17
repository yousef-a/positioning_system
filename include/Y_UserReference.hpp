#pragma once
#include "UserReference.hpp"
#include "ControlSystemMessage.hpp"

class Y_UserReference : public UserReference{

private:
    ControlSystemMessage m_output_msg;

public:

    void receive_msg_data(DataMessage*);
    
    Y_UserReference();
    ~Y_UserReference();
};