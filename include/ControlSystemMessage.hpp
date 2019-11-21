#pragma once
#include "DataMessage.hpp"
#include "Block.hpp"

class ControlSystemMessage : public DataMessage{

private:
    Block* _to_remove;
    Block* _to_add;
    msg_type _type;
    control_system_msg_type _control_system_msg_type;

public:
    msg_type getType();
    Block* getBlockToRemove();
    Block* getBlockToAdd();
    control_system_msg_type getControlSystemMsgType();

    ControlSystemMessage(control_system_msg_type, Block*, Block*);
    ControlSystemMessage(control_system_msg_type, Block*);
    ~ControlSystemMessage();
};