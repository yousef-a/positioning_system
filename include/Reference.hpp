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
        DataMessage* receive_msg_internal(DataMessage*);
        DataMessage* receive_msg_internal();
        virtual reference_type getReferenceType() = 0;

        Reference(std::string t_name, block_type t_type);
        ~Reference();
};