#pragma once
#include "DataMessage.hpp"
#include "Vector3D.hpp"

class ROSMsg : public DataMessage {

private:
    msg_type _type;
    ros_msg_type _ros_type;
    Vector3D<float> _position;
    Vector3D<float> _orientation;
    Vector3D<float> _x_pv;
    Vector3D<float> _y_pv;
    Vector3D<float> _z_pv;
    Vector3D<float> _roll_pv;
    Vector3D<float> _pitch_pv;
    Vector3D<float> _yaw_pv;
    float _control_system;
    control_system _source;
    float* _actuation;

public:
    msg_type getType();
    ros_msg_type getROSMsgType();
    const int getSize();
    void setPosition(Vector3D<float>);
    void setOrientation(Vector3D<float>);
    void setX_PV(Vector3D<float>);
    void setY_PV(Vector3D<float>);
    void setZ_PV(Vector3D<float>);
    void setRoll_PV(Vector3D<float>);
    void setPitch_PV(Vector3D<float>);
    void setYaw_PV(Vector3D<float>);
    void setControlSystem(float, control_system);
    void setActuation(float*);
    void setSource(control_system);
    Vector3D<float> getPosition() { return _position; }
    Vector3D<float> getOrientation() { return _orientation; }
    Vector3D<float> getX_PV() { return _x_pv; }
    Vector3D<float> getY_PV() { return _y_pv; }
    Vector3D<float> getZ_PV() { return _z_pv; }
    Vector3D<float> getRoll_PV() { return _roll_pv; }
    Vector3D<float> getPitch_PV() { return _pitch_pv; }
    Vector3D<float> getYaw_PV() { return _yaw_pv; }
    float getControlSystem() { return _control_system; }
    float* getActuation() { return _actuation; }
    control_system getSource() { return _source; }
    

    ROSMsg();
    ~ROSMsg();
};