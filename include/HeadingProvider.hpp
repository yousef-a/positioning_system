#pragma once
#include "Provider.hpp"
#include "MsgReceiver.hpp"
#include "HeadingMsg.hpp"

class HeadingProvider : public Provider{



    public:

        virtual HeadingMsg getHeading() = 0;
        
        DataMessage* receive_msg_internal(DataMessage*);
        DataMessage* receive_msg_internal();
        
        HeadingProvider(std::string, block_type);
        ~HeadingProvider();

    private:

        HeadingMsg m_heading_msg;
};