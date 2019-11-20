#pragma once
#include "DataMessage.hpp"
#include "Block.hpp"

class SwitchMessage : public DataMessage{

private:
    Block* _from;
    Block* _to;
    Block* _block_to_add;
    msg_type _type;
    control_system_msg_type _control_system_msg_type;

public:
    msg_type getType();
    Block* getFromBlock();
    Block* getToBlock();
    Block* getBlockToAdd();
    control_system_msg_type getControlSystemMsgType();

    SwitchMessage(control_system_msg_type t_type, Block* t_from, Block* t_to);
    SwitchMessage(control_system_msg_type t_type, Block* t_block);
    ~SwitchMessage();
};