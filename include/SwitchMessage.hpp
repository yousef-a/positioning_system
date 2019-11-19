#pragma once
#include "DataMessage.hpp"
#include "Block.hpp"

class SwitchMessage : public DataMessage{

private:
    Block* _from;
    Block* _to;
    msg_type _type;

public:
    msg_type getType();
    Block* getFromBlock();
    Block* getToBlock();

    SwitchMessage(Block* t_from, Block* t_to);
    ~SwitchMessage();
};