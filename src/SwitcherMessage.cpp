#include "SwitcherMessage.hpp"

SwitcherMessage::SwitcherMessage(switcher_type t_source, switcher_type t_destination, internal_switcher_type t_internal_type, Vector3D t_vector3Ddata) {
    _type = msg_type::switcher;
    _internal_type = t_internal_type;
    _v3D_data = t_vector3Ddata;
    _source = t_source;
    _destination = t_destination;
}

SwitcherMessage::SwitcherMessage(switcher_type t_source, switcher_type t_destination, internal_switcher_type t_internal_type, float t_float_data){
    _type = msg_type::switcher;
    _internal_type = t_internal_type;
    _float_data = t_float_data;
    _source = t_source;
    _destination = t_destination;
}

SwitcherMessage::SwitcherMessage(Vector3D t_vector3Ddata){
    _type = msg_type::switcher;
    _v3D_data = t_vector3Ddata;
}

SwitcherMessage::SwitcherMessage(){
}

void SwitcherMessage::setSwitcherMessage(switcher_type t_source, switcher_type t_destination, internal_switcher_type t_internal_type, Vector3D t_vector3Ddata) {
    _type = msg_type::switcher;
    _internal_type = t_internal_type;
    _v3D_data = t_vector3Ddata;
    _source = t_source;
    _destination = t_destination;
}

void SwitcherMessage::setSwitcherMessage(switcher_type t_source, switcher_type t_destination, internal_switcher_type t_internal_type, float t_float_data){
    _type = msg_type::switcher;
    _internal_type = t_internal_type;
    _float_data = t_float_data;
    _source = t_source;
    _destination = t_destination;
}

void SwitcherMessage::setSwitcherMessage(Vector3D t_vector3Ddata){
    _type = msg_type::switcher;
    _v3D_data = t_vector3Ddata;
}

SwitcherMessage::~SwitcherMessage() {

}

msg_type SwitcherMessage::getType(){
    return _type;
}

internal_switcher_type SwitcherMessage::getInternalType(){
    return _internal_type;
}

Vector3D SwitcherMessage::getVector3DData(){
    return _v3D_data;
}

float SwitcherMessage::getFloatData(){
    return _float_data;
}

switcher_type SwitcherMessage::getSource(){
    return _source;
}

switcher_type SwitcherMessage:: getDestination(){
    return _destination;
}