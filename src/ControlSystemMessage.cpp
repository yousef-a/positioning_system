#include "ControlSystemMessage.hpp"

ControlSystemMessage::ControlSystemMessage(control_system_msg_type t_type, Block* t_to_remove, Block* t_to_add) {
    _to_remove = t_to_remove;
    _to_add = t_to_add;
    _type = msg_type::control_system;
    _control_system_msg_type = t_type;
}

ControlSystemMessage::ControlSystemMessage(control_system_msg_type t_type, Block* t_to_add) {
    _to_add = t_to_add;
    _type = msg_type::control_system;
    _control_system_msg_type = t_type;
}

ControlSystemMessage::~ControlSystemMessage() {

}

msg_type ControlSystemMessage::getType(){
    return _type;
}
Block* ControlSystemMessage::getBlockToRemove(){
    return _to_remove;
}
Block* ControlSystemMessage::getBlockToAdd(){
    return _to_add;
}
control_system_msg_type ControlSystemMessage::getControlSystemMsgType(){
    return _control_system_msg_type;
}