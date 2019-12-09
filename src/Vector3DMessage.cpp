#include "Vector3DMessage.hpp"

Vector3DMessage::Vector3DMessage(Vector3D t_data) {
    _type = msg_type::vector3D_msg;
    _data = t_data;
}

Vector3DMessage::Vector3DMessage(Vector3D t_data, provider_type t_provider_type) {
    _type = msg_type::vector3D_msg;
    _provider_type = t_provider_type;
    _data = t_data;
}

Vector3DMessage::Vector3DMessage() {
}

Vector3DMessage::~Vector3DMessage() {

}

msg_type Vector3DMessage::getType(){
    return _type;
}

const int Vector3DMessage::getSize()
{
    return sizeof(this);
}

Vector3D Vector3DMessage::getData(){
    return _data;
}

void Vector3DMessage::setVector3DMessage(Vector3D t_data) {
    _type = msg_type::vector3D_msg;
    _data = t_data;
}

void Vector3DMessage::setVector3DMessage(Vector3D t_data, provider_type t_provider_type) {
    _type = msg_type::vector3D_msg;
    _provider_type = t_provider_type;
    _data = t_data;
}