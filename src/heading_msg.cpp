#include "heading_msg.hpp"

msg_type HeadingMsg::getType()
{
	return msg_type::HEADING;
}

const int HeadingMsg::getSize()
{
	return sizeof(HeadingMsg);
}