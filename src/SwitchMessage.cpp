#include "SwitchMessage.hpp"

SwitchMessage::SwitchMessage(control_system_msg_type t_type, Block* t_from, Block* t_to) {
    _from = t_from;
    _to = t_to;
    _type = msg_type::control_system;
    _control_system_msg_type = t_type;
}

SwitchMessage::SwitchMessage(control_system_msg_type t_type, Block* t_block) {
    _block_to_add = t_block;
    _type = msg_type::control_system;
    _control_system_msg_type = t_type;
}

SwitchMessage::~SwitchMessage() {

}

msg_type SwitchMessage::getType(){
    return _type;
}
Block* SwitchMessage::getFromBlock(){
    return _from;
}
Block* SwitchMessage::getToBlock(){
    return _to;
}
Block* SwitchMessage::getBlockToAdd(){
    return _block_to_add;
}
control_system_msg_type SwitchMessage::getControlSystemMsgType(){
    return _control_system_msg_type;
}