#include "OptitrackMessage.hpp"

OptitrackMessage::OptitrackMessage(Vector3D t_position, Quaternion t_att_head) {

    _attitude_heading = t_att_head;
    _position = t_position;
    _type = msg_type::optitrack;
}

OptitrackMessage::OptitrackMessage() {
}

OptitrackMessage::~OptitrackMessage() {

}

msg_type OptitrackMessage::getType(){
    return _type;
}
    
Vector3D OptitrackMessage::getPosition(){
    return _position;
}

Quaternion OptitrackMessage::getAttitudeHeading(){
    return _attitude_heading;
}

void OptitrackMessage::setOptitrackMessage(Vector3D t_position, Quaternion t_att_head) {

    _attitude_heading = t_att_head;
    _position = t_position;
    _type = msg_type::optitrack;
}