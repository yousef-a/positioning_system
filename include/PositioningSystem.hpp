#pragma once
#include "Vector3D.hpp"
#include "msg_receiver.hpp"

class PositioningSystem : public msg_receiver{

    private:
        Vector3D _homePos;
    public:
        virtual Vector3D getPosition() = 0;
        void setHomePosition(Vector3D);
        virtual void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type) = 0;

        Vector3D getRelativePosition();
        
        PositioningSystem();
};