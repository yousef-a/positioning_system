#pragma once
#include "common_types.hpp"
#include "Block.hpp"

class Reference : public Block {

    private:
        std::string _name; 
        block_type _type;

    public:
        block_type getType();
        void switchIn(DataMessage*);
        DataMessage* switchOut();
        void receive_msg_data(DataMessage* t_msg);
        std::string getName();

        Reference(std::string name, block_type type);
        ~Reference();
};