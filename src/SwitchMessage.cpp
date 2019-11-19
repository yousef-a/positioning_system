#include "SwitchMessage.hpp"

SwitchMessage::SwitchMessage(Block* t_from, Block* t_to) {
    _from = t_from;
    _to = t_to;
    _type = msg_type::switcher;
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