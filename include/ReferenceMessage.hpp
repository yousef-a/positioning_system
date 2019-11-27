#pragma once
#include "DataMessage.hpp"
#include "Vector3D.hpp"

class ReferenceMessage : public DataMessage {

private:
    msg_type _type;
    float _data;

public:

    msg_type getType();
    float getData();
    
    ReferenceMessage(Vector3D);
    ReferenceMessage(float);
    ~ReferenceMessage();
};