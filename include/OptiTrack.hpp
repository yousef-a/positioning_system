#pragma once
#include "MotionCapture.hpp"
#include "Quaternion.hpp"

class OptiTrack : public MotionCapture {

    private:
        Quaternion _bodyAtt;

    public:
        Quaternion getAttitudeHeading();
        Vector3D getPosition();

        OptiTrack();
        ~OptiTrack();
};