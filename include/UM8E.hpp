#pragma once
#include "GPS.hpp"
#include <iostream>

class UM8E : public GPS {

    public:
        Vector3D getPosition();
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);

        UM8E();
        ~UM8E();
};