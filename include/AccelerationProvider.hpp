#pragma once
#include "Provider.hpp"
#include "AccelerationMsg.hpp"

class AccelerationProvider : public Provider{

public:

    virtual AccelerationMsg getAcceleration() = 0;
    DataMessage* receive_msg_internal(DataMessage*);
    DataMessage* receive_msg_internal();
    
    AccelerationProvider(std::string, block_type);
    ~AccelerationProvider();
};