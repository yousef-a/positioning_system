#pragma once
#include "PositioningSystem.hpp"
#include <string>

class GPS : public PositioningSystem {

    public:

        virtual Vector3D getPosition() = 0;
        void parseNMEA(std::string);

        GPS();
        ~GPS();
};