#include "ControllerMessage.hpp"

ControllerMessage::ControllerMessage(controller_msg_type t_type, std::vector<double> t_data) {
    _type = msg_type::controller;
    _controller_msg_type = t_type;
    _data = t_data;
}

ControllerMessage::ControllerMessage(controller_msg_type t_type, PID_parameters* t_pid_para) {
    _type = msg_type::controller;
    _controller_msg_type = t_type;
    _pid_para = t_pid_para;
}

ControllerMessage::~ControllerMessage() {

}

std::vector<double> ControllerMessage::getData(){
    return _data;
}
PID_parameters* ControllerMessage::getSettings(){
    return _pid_para;
}
msg_type ControllerMessage::getType(){
    return _type;
}
controller_msg_type ControllerMessage::getControllerMsgType(){
    return _controller_msg_type;
}