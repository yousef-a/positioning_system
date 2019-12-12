#include "Pitch_PVProvider.hpp"

Pitch_PVProvider::Pitch_PVProvider() {

}

Pitch_PVProvider::~Pitch_PVProvider() {

}

Vector3D<float> Pitch_PVProvider::getProcessVariable(){

    Vector3D<float> t_process_variable;
    t_process_variable.x = this->getAttitude().pitch;
    t_process_variable.y = 0.0; //TODO yaw_dot
    t_process_variable.z = 0.0; //TODO yaw_dot_dot

    return t_process_variable;
    
}