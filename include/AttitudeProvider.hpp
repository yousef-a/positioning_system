#pragma once
#include "Vector3D.hpp"

class AttitudeProvider {

    public:

        virtual Vector3D getAttitude() = 0;
        AttitudeProvider();
        ~AttitudeProvider();
};