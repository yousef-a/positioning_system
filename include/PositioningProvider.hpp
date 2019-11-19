#pragma once
#include "Vector3D.hpp"
#include "msg_receiver.hpp"

class PositioningProvider : public msg_receiver{

    private:
        Vector3D _homePos;
    public:
        virtual Vector3D getPosition() = 0;
        void setHomePosition(Vector3D);
        virtual void receive_msg_data(DataMessage* t_msg) = 0;

        Vector3D getRelativePosition();
        
        PositioningProvider();
};