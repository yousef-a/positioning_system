#include "BoolMessage.hpp"

BoolMessage::BoolMessage() {

}

BoolMessage::~BoolMessage() {

}

msg_type BoolMessage::getType(){
    return _type;
}

const int BoolMessage::getSize()
{
    return sizeof(this);
}

bool BoolMessage::getData(){
    return _data;
}

void BoolMessage::setBoolMessage(bool t_data){
    _type = msg_type::BOOLEAN;
    _data = t_data;
}