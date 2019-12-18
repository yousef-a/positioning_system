#include "X_PVProvider.hpp"

X_PVProvider::X_PVProvider() {

}

X_PVProvider::~X_PVProvider() {

}

Vector3D<float> X_PVProvider::getProcessVariable(){

    Vector3D<float> t_process_variable;
    t_process_variable.x = this->getPosition().x;
    t_process_variable.y = this->getVelocity().dx;
    t_process_variable.z = this->getAcceleration().ddx;

    ros_msg.setX_PV(t_process_variable);
    this->PVProvider::emit_message((DataMessage*) &ros_msg);

    ros_msg.setPosition(this->getPosition());
    this->PositioningProvider::emit_message((DataMessage*) &ros_msg);

    return t_process_variable;
    
}