#pragma once
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"
#include "Block.hpp"
#include "common_types.hpp"
//TODO Delete Controller
class Controller : public msg_emitter, public msg_receiver, public Block {

    protected:
        double _states[];
        double _error[];

    public:
        void switchIn();
        void switchOut();
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);
        
        Controller();
        ~Controller();
};