#pragma once
#include "Block.hpp"

class PID_Controller : public Block{

    using Block::Block; 

    private:
        
    public:

        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);
        void switchIn();
        void switchOut();

        PID_Controller(string name, block_type type);
        ~PID_Controller();
};