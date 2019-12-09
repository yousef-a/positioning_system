#include "TestRec.hpp"

TestRec::TestRec()
{

}

void TestRec::receive_msg_data(DataMessage* t_msg)
{
    if(t_msg->getType() == msg_type::TESTMSG)
    {
        TestMsg t_data = *((TestMsg*) t_msg);
        std::cout << "received data: " << t_data.data << std::endl;
    }
}