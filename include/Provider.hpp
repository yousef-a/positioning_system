#pragma once
#include "Block.hpp"
#include "MsgReceiver.hpp"

class Provider{ //TODO possibly remove Block

private:
    std::string _name; 
    block_type _type;
    
public:

    Provider(std::string, block_type);
    ~Provider();
};