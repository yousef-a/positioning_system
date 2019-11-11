#pragma once
#include "common_types.hpp"
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"
#include "Block.hpp"

class Reference : public msg_emitter, public msg_receiver, public Block {

    public:
        block_type getType();
        void switchIn();
        void switchOut();
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);

        Reference();
        ~Reference();
};