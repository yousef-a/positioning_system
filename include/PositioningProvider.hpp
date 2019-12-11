#pragma once
#include "Vector3D.hpp"
#include "MsgReceiver.hpp"
#include "Block.hpp"
#include "Vector3DMessage.hpp"
#include "Provider.hpp"
#include "PositionMsg.hpp"

class PositioningProvider : public Provider{

    private:
        Vector3D _homePos;
        PositionMsg m_pos_msg;

    public:
        virtual PositionMsg getPosition() = 0;
        void setHomePosition(Vector3D);
        virtual void receive_msg_data(DataMessage* t_msg) = 0;
        Vector3D getRelativePosition();
        
        DataMessage* receive_msg_internal(DataMessage*);
        DataMessage* receive_msg_internal();
        
        PositioningProvider(std::string, block_type);
        ~PositioningProvider();
        
};