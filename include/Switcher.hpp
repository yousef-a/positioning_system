#pragma once
#include "Block.hpp"
#include <list>
#include "msg_receiver.hpp"
#include "msg_emitter.hpp"
#include "SwitchMessage.hpp"

class Switcher : public msg_receiver, public msg_emitter{

    private:
        std::list<Block*> _blocks;
        std::list<Block*>::iterator _it;
        switcher_type _type;

    public:
        void addBlock(Block* b);
        void getStatus();
        switcher_type getType();
        void switchBlock(Block* from, Block* to);
        void setInitialCondition(Block* b, bool status);
        void receive_msg_data(DataMessage* t_msg);
        
        Switcher(switcher_type t_type);
        ~Switcher();
};