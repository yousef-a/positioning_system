#pragma once
#include "Block.hpp"
#include <list>
//TODO inherit msg tx and rx
class Switcher{

    private:
        std::list<Block*> _blocks;
        std::list<Block*>::iterator _it;

    public:
        void addBlock(Block* b);
        void getStatus();
        void switchBlock(Block* from, Block* to);
        void setStatus(Block* b, bool status);

        Switcher();
        ~Switcher();
};