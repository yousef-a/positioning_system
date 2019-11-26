#pragma once
#include "Vector3D.hpp"
#include "Provider.hpp"

class AttitudeProvider : public Provider{

    private:
        provider_type _provider_type;

    public:

        virtual Vector3D getAttitude() = 0;
        virtual void receive_msg_data(DataMessage* t_msg) = 0;
        
        DataMessage* receive_msg_internal(DataMessage*);
        DataMessage* receive_msg_internal();
        provider_type getProviderType();
        
        AttitudeProvider(std::string, block_type);
        ~AttitudeProvider();
};