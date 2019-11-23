#include "SwitcherMessage.hpp"

SwitcherMessage::SwitcherMessage(internal_switcher_type t_internal_type, Vector3D t_vector3Ddata) {
    _type = msg_type::switcher;
    _internal_type = t_internal_type;
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