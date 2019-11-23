#pragma once
#include "DataMessage.hpp"
#include "Block.hpp"
#include "PID_values.hpp"

class ControlSystemMessage : public DataMessage{

private:
    Block* _to_remove;
    Block* _to_add;
    msg_type _type;
    control_system_msg_type _control_system_msg_type;
    PID_parameters* _pid_para;

public:
    msg_type getType();
    Block* getBlockToRemove();
    Block* getBlockToAdd();
    control_system_msg_type getControlSystemMsgType();
    PID_parameters* getSettings();

    ControlSystemMessage(control_system_msg_type, Block*, Block*);
    ControlSystemMessage(control_system_msg_type, Block*);
    ControlSystemMessage(control_system_msg_type, PID_parameters*);
    ~ControlSystemMessage();
};