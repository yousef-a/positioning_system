#pragma once
#include "DataMessage.hpp"
#include "Vector3D.hpp"
#include "Quaternion.hpp"

class OptitrackMessage : public DataMessage{

private:
    Vector3D _position;
    Quaternion _attitude_heading; 
    msg_type _type;

public:

    msg_type getType();
    Vector3D getPosition();
    Quaternion getAttitudeHeading();


    OptitrackMessage(Vector3D, Quaternion);
    ~OptitrackMessage();
};