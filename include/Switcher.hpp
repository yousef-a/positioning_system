#pragma once
#include "Block.hpp"
#include <list>
#include "msg_receiver.hpp"
#include "msg_emitter.hpp"

class Switcher : public msg_receiver, public msg_emitter{

    private:
        std::list<Block*> _blocks;
        std::list<Block*>::iterator _it;

    public:
        void addBlock(Block* b);
        void getStatus();
        void switchBlock(Block* from, Block* to);
        void setInitialCondition(Block* b, bool status);
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);
        
        Switcher();
        ~Switcher();
};