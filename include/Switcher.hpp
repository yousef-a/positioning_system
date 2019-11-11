#pragma once
#include "Block.hpp"

class Switcher{

    private:
         
    public:
        void addBlock(Block* b);
        void status();
        void switchBlock(Block* from, Block* to);

        Switcher();
        ~Switcher();
};