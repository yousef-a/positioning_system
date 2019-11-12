#pragma once
#include "common_types.hpp"
#include <iostream>
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"

class Block : public msg_emitter, public msg_receiver{   

    public:
        
        virtual string getName() = 0;
        virtual block_type getType() = 0;
        virtual bool getStatus() = 0;
        virtual void switchIn() = 0;
        virtual void switchOut() = 0;
        virtual void setStatus(bool) = 0;
        virtual void receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type) = 0;

        Block();
        ~Block();
};