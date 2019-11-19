#pragma once
#include "DataMessage.hpp"
#include "Block.hpp"

class SwitchMessage : public DataMessage{

private:
    Block* _from;
    Block* _to;
    switcher_msg_type _switcher_type;
    msg_type _type;

public:
    msg_type getType();
    switcher_msg_type getSwitcherType();
    Block* getFromBlock();
    Block* getToBlock();

    SwitchMessage(switcher_msg_type t_switcher_type, Block* t_from, Block* t_to);
    ~SwitchMessage();
};