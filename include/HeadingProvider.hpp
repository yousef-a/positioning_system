#pragma once
#include "Provider.hpp"
#include "msg_receiver.hpp"

class HeadingProvider : public Provider{

     private:
        provider_type _provider_type;

    public:

        virtual double getHeading() = 0;
        virtual void receive_msg_data(DataMessage* t_msg) = 0;
        
        DataMessage* receive_msg_internal(DataMessage*);
        DataMessage* receive_msg_internal();
        provider_type getProviderType();
        
        HeadingProvider(std::string, block_type);
        ~HeadingProvider();
};