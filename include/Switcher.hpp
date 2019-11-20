#pragma once
#include "Block.hpp"
#include <list>
#include "msg_receiver.hpp"
#include "msg_emitter.hpp"
#include "ControlSystemMessage.hpp"

class Switcher : public msg_receiver, public msg_emitter{

    private:
        std::list<Block*> _blocks;
        std::list<Block*>::iterator _it;
        switcher_type _type;
        Block* _active_block;

    public:
        void addBlock(Block* b);
        switcher_type getType();
        Block* getActiveBlock();
        void switchBlock(Block* from, Block* to);
        void receive_msg_data(DataMessage* t_msg);
        
        Switcher(switcher_type t_type);
        ~Switcher();
};