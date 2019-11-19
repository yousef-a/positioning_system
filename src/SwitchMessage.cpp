#include "SwitchMessage.hpp"

SwitchMessage::SwitchMessage(switcher_msg_type t_switcher_type, Block* t_from, Block* t_to) {
    _from = t_from;
    _to = t_to;
    _switcher_type = t_switcher_type;
    _type = msg_type::switcher;
}

SwitchMessage::~SwitchMessage() {

}

msg_type SwitchMessage::getType(){
    return _type;
}
switcher_msg_type SwitchMessage::getSwitcherType(){
    return _switcher_type;
}
Block* SwitchMessage::getFromBlock(){
    return _from;
}
Block* SwitchMessage::getToBlock(){
    return _to;
}