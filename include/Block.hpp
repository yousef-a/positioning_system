#pragma once
#include "common_types.hpp"
#include <iostream>
#include "msg_emitter.hpp"
#include "msg_receiver.hpp"

class Block : public msg_emitter, public msg_receiver{ 

protected: 
    string _name; 
    bool _status;
    block_type _type;

public:
    
    string getName();
    block_type getType();
    virtual void switchIn() = 0;
    virtual void switchOut() = 0;
    bool getStatus();
    void setStatus(bool);
    void receive_msg_data(uint8_t data[], std::size_t len, msg_type _msg_type);

    Block(string name, block_type type);
    Block();
    ~Block();
};