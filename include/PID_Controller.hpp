#pragma once
#include "Block.hpp"

class PID_Controller : public Block{

    private:
        string _name; 
        bool _status;
        block_type _type;

    public:
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);
        void switchIn(DataMessage*);
        DataMessage* switchOut();
        string getName();
        block_type getType();
        bool getStatus();
        void setStatus(bool);

        PID_Controller(string name, block_type type);
        ~PID_Controller();
};