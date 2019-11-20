#pragma once
#include "Block.hpp"

class PIDController : public Block{

    private:
        string _name; 
        block_type _type;

    public:
        void receive_msg_data(DataMessage* t_msg);
        void switchIn(DataMessage*);
        DataMessage* switchOut();
        string getName();
        block_type getType();

        PIDController(string name, block_type type);
        ~PIDController();
};