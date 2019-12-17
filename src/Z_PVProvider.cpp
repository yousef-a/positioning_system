#include "Z_PVProvider.hpp"

Z_PVProvider::Z_PVProvider() {

}

Z_PVProvider::~Z_PVProvider() {

}

Vector3D<float> Z_PVProvider::getProcessVariable(){

    Vector3D<float> t_process_variable;
    t_process_variable.x = this->getPosition().z;
    t_process_variable.y = this->getVelocity().dz;
    t_process_variable.z = this->getAcceleration().ddz;

    return t_process_variable;
    
}