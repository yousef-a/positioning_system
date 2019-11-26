#pragma once
#include "Vector3D.hpp"
#include "msg_receiver.hpp"
#include "Block.hpp"
#include "Vector3DMessage.hpp"
#include "Provider.hpp"

class PositioningProvider : public Provider{

    private:
        Vector3D _homePos;
        provider_type _provider_type;

    public:
        virtual Vector3D getPosition() = 0;
        void setHomePosition(Vector3D);
        virtual void receive_msg_data(DataMessage* t_msg) = 0;
        Vector3D getRelativePosition();
        
        DataMessage* receive_msg_internal(DataMessage*);
        DataMessage* receive_msg_internal();
        provider_type getProviderType();
        
        PositioningProvider(std::string, block_type);
        ~PositioningProvider();
        
};