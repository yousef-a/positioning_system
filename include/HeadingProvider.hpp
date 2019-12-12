#pragma once
#include "Provider.hpp"
#include "MsgReceiver.hpp"
#include "HeadingMsg.hpp"

class HeadingProvider : public Provider{



    public:

        virtual HeadingMsg getHeading() = 0;
        
         
        
        HeadingProvider(std::string, block_type);
        ~HeadingProvider();

    private:

        HeadingMsg m_heading_msg;
};