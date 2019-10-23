#pragma once
#include "PositioningSystem.hpp"

class MotionCapture : public PositioningSystem {


    public:
        virtual Vector3D getPosition() = 0;
        

        MotionCapture();
        ~MotionCapture();
};