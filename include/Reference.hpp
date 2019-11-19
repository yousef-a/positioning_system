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
        void switchIn(DataMessage*);
        DataMessage* switchOut();
        void receive_msg_data(DataMessage* t_msg);
        string getName();
        bool getStatus();
        void setStatus(bool);

        Reference(string name, block_type type);
        ~Reference();
};