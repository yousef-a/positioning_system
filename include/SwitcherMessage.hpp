#pragma once
#include "DataMessage.hpp"
#include "Vector3D.hpp"
#include "Quaternion.hpp"

class SwitcherMessage : public DataMessage{

private:
    msg_type _type;
    internal_switcher_type _internal_type;
    Vector3D _v3D_data;
    switcher_type _source, _destination;
    float _float_data;
    
public:

    msg_type getType();
    internal_switcher_type getInternalType();
    Vector3D getVector3DData();
    float getFloatData();
    switcher_type getSource();
    switcher_type getDestination();

    void setSwitcherMessage(switcher_type, switcher_type, internal_switcher_type, Vector3D);
    void setSwitcherMessage(switcher_type, switcher_type, internal_switcher_type, float);
    void setSwitcherMessage(Vector3D);

    SwitcherMessage(switcher_type, switcher_type, internal_switcher_type, Vector3D);
    SwitcherMessage(switcher_type, switcher_type, internal_switcher_type, float);
    SwitcherMessage(Vector3D);
    SwitcherMessage();
    ~SwitcherMessage();
};