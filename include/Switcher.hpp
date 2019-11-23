#pragma once
#include "Block.hpp"
#include <list>
#include "msg_receiver.hpp"
#include "msg_emitter.hpp"
#include "ControlSystemMessage.hpp"
#include <algorithm>

class Switcher : public msg_receiver, public msg_emitter{

    private:
        std::list<Block*> _blocks;
        std::list<Block*>::iterator _it;
        switcher_type _type;
        Block* _active_block;
        string _name;

    public:
        void addBlock(Block* b);
        switcher_type getType();
        Block* getActiveBlock();
        string getName();
        void switchBlock(Block* from, Block* to);
        void receive_msg_data(DataMessage* t_msg);
        void loopInternal();
        //TODO Send a message to Block
        //TODO Receive a message from Block
        Switcher(string t_name, switcher_type t_type);
        ~Switcher();
};