#pragma once
#include "common_types.hpp"
#include <iostream>
#include "DataMessage.hpp"

class Block{   

    public:
        
        virtual std::string getName() = 0;
        virtual block_type getType() = 0;
        virtual void switchIn(DataMessage*) = 0;
        virtual DataMessage* switchOut() = 0;
        virtual DataMessage* receive_msg_internal() = 0;
    
        Block();
        ~Block();
};