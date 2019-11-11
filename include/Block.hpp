#pragma once
#include "common_types.hpp"

class Block {

public:
    
    virtual block_type getType() = 0;
    virtual void switchIn() = 0;
    virtual void swtichOut() = 0;

    Block();
    ~Block();
};