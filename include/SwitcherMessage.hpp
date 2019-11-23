#pragma once
#include "DataMessage.hpp"
#include "Vector3D.hpp"
#include "Quaternion.hpp"

class SwitcherMessage : public DataMessage{

private:
    msg_type _type;
    internal_switcher_type _internal_type;
    Vector3D _v3D_data;

public:

    msg_type getType();
    internal_switcher_type getInternalType();
    Vector3D getVector3DData();
    
    SwitcherMessage(internal_switcher_type, Vector3D);
    ~SwitcherMessage();
};