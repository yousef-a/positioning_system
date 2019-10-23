#pragma once
#include "PositioningSystem.hpp"
#include "Quaternion.hpp"

class MotionCapture : public PositioningSystem {

    public:
        virtual Vector3D getPosition() = 0;
        virtual Quaternion getAttitude() = 0;

        MotionCapture();
        ~MotionCapture();
};