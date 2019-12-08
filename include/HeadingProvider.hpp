#pragma once
#include "Provider.hpp"
#include "msg_receiver.hpp"
#include "heading_msg.hpp"

class HeadingProvider : public Provider{

     private:
        provider_type _provider_type;

    public:

        virtual HeadingMsg getHeading() = 0;
        
        DataMessage* receive_msg_internal(DataMessage*);
        DataMessage* receive_msg_internal();
        
        HeadingProvider(std::string, block_type);
        ~HeadingProvider();
};