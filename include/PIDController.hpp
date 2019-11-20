#pragma once
#include "Block.hpp"

class PIDController : public Block{

    private:
        string _name; 
        bool _status;
        block_type _type;

    public:
        void receive_msg_data(DataMessage* t_msg);
        void switchIn(DataMessage*);
        void switchIn();
        DataMessage* switchOut();
        string getName();
        block_type getType();
        bool getStatus();
        void setStatus(bool);

        PIDController(string name, block_type type);
        ~PIDController();
};