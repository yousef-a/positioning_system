#include "Roll_PVProvider.hpp"

Roll_PVProvider::Roll_PVProvider() {

}

Roll_PVProvider::~Roll_PVProvider() {

}

Vector3D<float> Roll_PVProvider::getProcessVariable(){

    Vector3D<float> t_process_variable;
    t_process_variable.x = this->getAttitude().roll;
    t_process_variable.y = 0.0; //TODO roll_dot
    t_process_variable.z = 0.0; //TODO roll_dot_dot

    return t_process_variable;
    
}