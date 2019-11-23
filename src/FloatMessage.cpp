#include "FloatMessage.hpp"

FloatMessage::FloatMessage(float t_data) {
    _type = msg_type::float_msg;
    _data = t_data;
}

FloatMessage::~FloatMessage() {

}

msg_type FloatMessage::getType(){
    return _type;
}

float FloatMessage::getData(){
    return _data;
}