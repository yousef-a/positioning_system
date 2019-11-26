#pragma once
#include "Block.hpp"
#include "msg_receiver.hpp"

class Provider : public Block, public msg_receiver{

private:
    std::string _name; 
    block_type _type;
    
public:

    std::string getName();
    block_type getType();
    void switchIn(DataMessage*);
    DataMessage* switchOut();

    virtual DataMessage* receive_msg_internal(DataMessage*) = 0;
    virtual DataMessage* receive_msg_internal() = 0;
    virtual provider_type getProviderType() = 0;
    virtual void receive_msg_data(DataMessage* t_msg) = 0;
    
    Provider(std::string, block_type);
    ~Provider();
};