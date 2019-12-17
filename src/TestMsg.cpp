#include "TestMsg.hpp"

msg_type TestMsg::getType()
{
    return msg_type::TESTMSG;
}

const int TestMsg::getSize()
{
    return sizeof(this);
}