#include "ReferenceMessage.hpp"

ReferenceMessage::ReferenceMessage(Vector3D t_v3d){
    _type = msg_type::reference;
    _data = t_v3d.x;
}

ReferenceMessage::ReferenceMessage(float t_float){
    _type = msg_type::reference;
    _data = t_float;
}

ReferenceMessage::~ReferenceMessage() {

}

msg_type ReferenceMessage::getType(){
    return _type;
}
float ReferenceMessage::getData(){
    return _data;
}