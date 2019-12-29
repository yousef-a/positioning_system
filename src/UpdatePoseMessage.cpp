#include "UpdatePoseMessage.hpp"

UpdatePoseMessage::UpdatePoseMessage(float t_x, float t_y, float t_z, float t_yaw) {
    _type = msg_type::USERREFERENCE;
    _x = t_x;
    _y = t_y;
    _z = t_z;
    _yaw = t_yaw;
}

UpdatePoseMessage::UpdatePoseMessage() {
    _type = msg_type::USERREFERENCE;
    _ref_type = msg_type_reference::NULL_TYPE;
}

UpdatePoseMessage::~UpdatePoseMessage() {

}

float UpdatePoseMessage::getX(){
    return _x;
}
float UpdatePoseMessage::getY(){
    return _y;
}
float UpdatePoseMessage::getZ(){
    return _z;
}
float UpdatePoseMessage::getYaw(){
    return _yaw;
}
msg_type UpdatePoseMessage::getType(){
    return _type;
}
void UpdatePoseMessage::setPoseMessage(float t_x, float t_y, float t_z, float t_yaw){
    _type = msg_type::USERREFERENCE;
    _x = t_x;
    _y = t_y;
    _z = t_z;
    _yaw = t_yaw;
}

void UpdatePoseMessage::setPoseX(float t_x){
    _ref_type = msg_type_reference::X;
    _x = t_x;
}
void UpdatePoseMessage::setPoseY(float t_y){
    _ref_type = msg_type_reference::Y;
    _y = t_y;
}
void UpdatePoseMessage::setPoseZ(float t_z){
    _ref_type = msg_type_reference::Z;
    _z = t_z;
}
void UpdatePoseMessage::setPoseYaw(float t_yaw){
    _ref_type = msg_type_reference::YAW;
    _yaw = t_yaw;
}

msg_type_reference UpdatePoseMessage::getRefType(){
    return _ref_type;
}

const int UpdatePoseMessage::getSize()
{
    return sizeof(this);
}