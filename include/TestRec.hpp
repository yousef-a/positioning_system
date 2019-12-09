#pragma once

#include <cstdint>
#include "DataMessage.hpp"
#include <iostream>
//#include "serial_data_msg.hpp"
#include "TestMsg.hpp"
#include "MsgReceiver.hpp"

class TestRec : public msg_receiver
{

public:

    TestRec();

    void receive_msg_data(DataMessage* t_msg);

};