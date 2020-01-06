#include "SwitchOutMsg.hpp"

SwitchOutMsg::SwitchOutMsg() {

}

SwitchOutMsg::~SwitchOutMsg() {

}

msg_type SwitchOutMsg::getType()
{
	return msg_type::SWITCHOUT;
}

const int SwitchOutMsg::getSize()
{
	return sizeof(this);
}