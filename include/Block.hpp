#pragma once
#include "common_types.hpp"
#include <iostream>

class Block {

protected: 
    block_type _type;
    bool _status;

public:
    
    block_type getType();
    virtual void switchIn() = 0;
    virtual void switchOut() = 0;
    bool getStatus();
    void setStatus(bool);

    Block(block_type);
    ~Block();
};