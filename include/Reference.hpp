#pragma once
#include "common_types.hpp"
#include "Block.hpp"

class Reference : public Block {

    using Block::Block;

    public:
        block_type getType();
        void switchIn();
        void switchOut();
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);

        Reference(string name, block_type type);
        ~Reference();
};