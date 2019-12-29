#include "ReferenceMessage.hpp"

ReferenceMessage::ReferenceMessage(){
    _type = msg_type::USERREFERENCE;
}

ReferenceMessage::~ReferenceMessage() {

}

void ReferenceMessage::setReferenceMessage(float t_float){
    _type = msg_type::USERREFERENCE;
    _data = t_float;
}

msg_type ReferenceMessage::getType(){
    return _type;
}

const int ReferenceMessage::getSize()
{
    return sizeof(this);
}

float ReferenceMessage::getData(){
    return _data;
}