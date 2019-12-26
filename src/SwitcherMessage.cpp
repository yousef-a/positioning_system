#include "SwitcherMessage.hpp"

SwitcherMessage::SwitcherMessage(){

}

SwitcherMessage::~SwitcherMessage() {

}

void SwitcherMessage::setSwitcherMessage(Vector3D<float> t_vector3Ddata){
    _type = msg_type::switcher;
    _v3D_data = t_vector3Ddata;
}

void SwitcherMessage::setSwitcherMessage(float t_data){
    _type = msg_type::switcher;
    _float_data = t_data;
}

msg_type SwitcherMessage::getType(){
    return _type;
}

const int SwitcherMessage::getSize()
{
    return sizeof(this);
}

Vector3D<float> SwitcherMessage::getVector3DData(){
    return _v3D_data;
}

float SwitcherMessage::getFloatData(){
    return _float_data;
}
