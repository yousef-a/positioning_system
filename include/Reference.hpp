#pragma once
#include "common_types.hpp"
#include "Block.hpp"

class Reference : public Block {

    private:
        string _name; 
        bool _status;
        block_type _type;

    public:
        block_type getType();
        void switchIn();
        void switchOut();
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);
        string getName();
        bool getStatus();
        void setStatus(bool);

        Reference(string name, block_type type);
        ~Reference();
};