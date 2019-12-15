#include "ResetControllerMessage.hpp"

ResetControllerMessage::ResetControllerMessage() {

}

ResetControllerMessage::~ResetControllerMessage() {

}

msg_type ResetControllerMessage::getType(){
    return _type;
}

const int ResetControllerMessage::getSize()
{
    return sizeof(this);
}

int ResetControllerMessage::getData(){
    return _data;
}

void ResetControllerMessage::setResetControllerMessage(int t_data){
    _type = msg_type::RESETCONTROLLER;
    _data = t_data;
}