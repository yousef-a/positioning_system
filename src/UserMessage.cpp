#include "UserMessage.hpp"

UserMessage::UserMessage(float t_x, float t_y, float t_z, float t_yaw) {
    _type = msg_type::user;
    _x = t_x;
    _y = t_y;
    _z = t_z;
    _yaw = t_yaw;
}

UserMessage::~UserMessage() {

}

float UserMessage::getX(){
    return _x;
}
float UserMessage::getY(){
    return _y;
}
float UserMessage::getZ(){
    return _z;
}
float UserMessage::getYaw(){
    return _yaw;
}
msg_type UserMessage::getType(){
    return _type;
}

const int UserMessage::getSize()
{
    return sizeof(this);
}