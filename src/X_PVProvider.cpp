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

    return t_process_variable;
    
}