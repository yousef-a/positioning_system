#pragma once
#include "Block.hpp"
#include "ControllerMessage.hpp"
#include "FloatMessage.hpp"
#include "common_types.hpp"

class Controller : public Block{

private:
    std::string _name; 
    block_type _type;

public:

    void switchIn(DataMessage*);
    DataMessage* switchOut();
    std::string getName();
    block_type getType();
    virtual controller_type getControllerType() = 0;
    virtual DataMessage* receive_msg_internal(DataMessage*) = 0;
    
    Controller(std::string t_name, block_type t_type);
    ~Controller();
};