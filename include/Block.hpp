#pragma once
#include "common_types.hpp"

class Block {

protected: 
    block_type _type;
    bool _status;

public:
    
    virtual block_type getType() = 0;
    virtual void switchIn() = 0;
    virtual void switchOut() = 0;
    
    Block(block_type);
    ~Block();
};