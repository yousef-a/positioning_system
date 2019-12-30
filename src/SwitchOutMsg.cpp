#include "SwitchOutMsg.hpp"

SwitchOutMsg::SwitchOutMsg() {
	_type = msg_type::SWITCHOUT;

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

void SwitchOutMsg::setSwitchOutMsg(float t_data){
	_data = t_data;
}

float SwitchOutMsg::getSwitchOutMsg(){
	return _data;
}