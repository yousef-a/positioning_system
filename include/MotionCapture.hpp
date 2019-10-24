#pragma once
#include "PositioningSystem.hpp"
#include "Quaternion.hpp"
#include "AttitudeHeadingProvider.hpp"

class MotionCapture : public PositioningSystem, public AttitudeHeadingProvider{

    public:
        virtual Vector3D getPosition() = 0;
        virtual Quaternion getAttitudeHeading() = 0;

        MotionCapture();
        ~MotionCapture();
};