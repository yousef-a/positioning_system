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
        virtual DataMessage* receive_msg_internal(DataMessage*) = 0;
        virtual DataMessage* receive_msg_internal() = 0;
        virtual reference_type getReferenceType() = 0;

        Reference(std::string t_name, block_type t_type);
        ~Reference();
};