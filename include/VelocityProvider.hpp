#pragma once
#include "Provider.hpp"
#include "VelocityMsg.hpp"

class VelocityProvider : public Provider{

public:

    virtual VelocityMsg getVelocity() = 0;
    DataMessage* receive_msg_internal(DataMessage*);
    DataMessage* receive_msg_internal();

    VelocityProvider(std::string, block_type);
    ~VelocityProvider();
};