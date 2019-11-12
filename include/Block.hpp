#pragma once
#include "common_types.hpp"
#include <iostream>

class Block { //TODO inherit msg_rx and msg_tx

protected: 
    block_type _type; //TODO remove type from here and add _name to the block
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