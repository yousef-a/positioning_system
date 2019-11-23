#pragma once
#include "DataMessage.hpp"

class FloatMessage : public DataMessage{

private:
    msg_type _type;
    float _data;

public:

    msg_type getType();
    float getData();
    
    FloatMessage(float);
    ~FloatMessage();
};