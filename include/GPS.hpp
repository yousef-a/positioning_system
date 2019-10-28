#pragma once
#include "PositioningSystem.hpp"
#include <string>

class GPS : public PositioningSystem {

    public:

        virtual Vector3D getPosition() = 0;
        void parseNMEA(std::string);
        virtual void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type) = 0;

        GPS();
        ~GPS();
};