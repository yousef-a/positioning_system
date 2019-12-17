#include "UserReferenceMessage.hpp"

UserReferenceMessage::UserReferenceMessage(float t_x, float t_y, float t_z, float t_yaw) {
    _type = msg_type::user;
    _x = t_x;
    _y = t_y;
    _z = t_z;
    _yaw = t_yaw;
}

UserReferenceMessage::UserReferenceMessage() {
    _type = msg_type::user;
}

UserReferenceMessage::~UserReferenceMessage() {

}

float UserReferenceMessage::getX(){
    return _x;
}
float UserReferenceMessage::getY(){
    return _y;
}
float UserReferenceMessage::getZ(){
    return _z;
}
float UserReferenceMessage::getYaw(){
    return _yaw;
}
msg_type UserReferenceMessage::getType(){
    return _type;
}
void UserReferenceMessage::setUserMessage(float t_x, float t_y, float t_z, float t_yaw){
    _type = msg_type::user;
    _x = t_x;
    _y = t_y;
    _z = t_z;
    _yaw = t_yaw;
}

const int UserReferenceMessage::getSize()
{
    return sizeof(this);
}