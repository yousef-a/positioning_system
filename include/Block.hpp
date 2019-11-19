#pragma once
#include "common_types.hpp"
#include <iostream>
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"
#include "DataMessage.hpp"

class Block : public msg_emitter, public msg_receiver{   

    public:
        
        virtual string getName() = 0;
        virtual block_type getType() = 0;
        virtual bool getStatus() = 0;
        virtual void switchIn(DataMessage*) = 0;
        virtual DataMessage* switchOut() = 0;
        virtual void setStatus(bool) = 0;
        virtual void receive_msg_data(DataMessage* t_msg) = 0;

        Block();
        ~Block();
};