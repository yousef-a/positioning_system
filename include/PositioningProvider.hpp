#pragma once
#include "Vector3D.hpp"
#include "msg_receiver.hpp"
#include "Block.hpp"
#include "Vector3DMessage.hpp"

class PositioningProvider : public msg_receiver, public Block{

    private:
        Vector3D _homePos;
        std::string _name; 
        block_type _type;

    public:
        virtual Vector3D getPosition() = 0;
        void setHomePosition(Vector3D);
        virtual void receive_msg_data(DataMessage* t_msg) = 0;
        Vector3D getRelativePosition();
        
        std::string getName();
        block_type getType();
        void switchIn(DataMessage*);
        DataMessage* switchOut();

        PositioningProvider(std::string, block_type);
};