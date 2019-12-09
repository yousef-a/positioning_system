#pragma once
#include "DataMessage.hpp"
#include "Vector3D.hpp"

class Vector3DMessage : public DataMessage{

private:
    msg_type _type;
    Vector3D _data;
    provider_type _provider_type;

public:

    msg_type getType();
    Vector3D getData();
    
    Vector3DMessage(Vector3D);
    Vector3DMessage(Vector3D, provider_type);
    Vector3DMessage();
    ~Vector3DMessage();

    void setVector3DMessage(Vector3D);
    void setVector3DMessage(Vector3D, provider_type);
};