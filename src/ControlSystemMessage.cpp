#include "ControlSystemMessage.hpp"

ControlSystemMessage::ControlSystemMessage(control_system_msg_type t_type, Block* t_from, Block* t_to) {
    _from = t_from;
    _to = t_to;
    _type = msg_type::control_system;
    _control_system_msg_type = t_type;
}

ControlSystemMessage::ControlSystemMessage(control_system_msg_type t_type, Block* t_block) {
    _block_to_add = t_block;
    _type = msg_type::control_system;
    _control_system_msg_type = t_type;
}

ControlSystemMessage::~ControlSystemMessage() {

}

msg_type ControlSystemMessage::getType(){
    return _type;
}
Block* ControlSystemMessage::getFromBlock(){
    return _from;
}
Block* ControlSystemMessage::getToBlock(){
    return _to;
}
Block* ControlSystemMessage::getBlockToAdd(){
    return _block_to_add;
}
control_system_msg_type ControlSystemMessage::getControlSystemMsgType(){
    return _control_system_msg_type;
}