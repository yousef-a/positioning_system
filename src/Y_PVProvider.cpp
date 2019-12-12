#include "Y_PVProvider.hpp"

Y_PVProvider::Y_PVProvider() {

}

Y_PVProvider::~Y_PVProvider() {

}

Vector3D<float> Y_PVProvider::getProcessVariable(){

    Vector3D<float> t_process_variable;
    t_process_variable.x = this->getPosition().y;
    t_process_variable.y = this->getVelocity().dy;
    t_process_variable.z = this->getAcceleration().ddy;

    return t_process_variable;
    
}