#pragma once
#include "MotionCapture.hpp"
#include "Quaternion.hpp"

class OptiTrack : public MotionCapture {

    private:
        Quaternion _bodyAtt;

    public:
        Quaternion getAttitude();
        Vector3D getPosition();

        OptiTrack();
        ~OptiTrack();
};