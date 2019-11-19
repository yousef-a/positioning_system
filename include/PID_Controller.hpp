#pragma once
#include "Block.hpp"

class PID_Controller : public Block{

    private:
        string _name; 
        bool _status;
        block_type _type;

    public:
        void receive_msg_data(DataMessage* t_msg);
        void switchIn(DataMessage*);
        DataMessage* switchOut();
        string getName();
        block_type getType();
        bool getStatus();
        void setStatus(bool);

        PID_Controller(string name, block_type type);
        ~PID_Controller();
};