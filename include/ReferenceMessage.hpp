#pragma once
#include "DataMessage.hpp"
#include "Vector3D.hpp"

class ReferenceMessage : public DataMessage {

private:
    msg_type _type;
    float _data;
    msg_type_reference _ref_type;

public:

    msg_type getType();
    const int getSize();
    float getData();
    
    ReferenceMessage();

    void setReferenceMessage(float);

    ~ReferenceMessage();
};