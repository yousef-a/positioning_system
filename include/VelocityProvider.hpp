#pragma once
#include "Provider.hpp"
#include "VelocityMsg.hpp"

class VelocityProvider : public Provider{

public:

    virtual VelocityMsg geteVelocity() = 0;
    DataMessage* receive_msg_internal(DataMessage*);
    DataMessage* receive_msg_internal();
    void receive_msg_data(DataMessage* t_msg);

    VelocityProvider(std::string, block_type);
    ~VelocityProvider();
};