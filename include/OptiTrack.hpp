#pragma once
#include "MotionCapture.hpp"
#include "Quaternion.hpp"

class OptiTrack : public MotionCapture {

    private:
        Quaternion _bodyAtt;

    public:
        Quaternion getAttitudeHeading();
        Vector3D getPosition();
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);

        OptiTrack();
        ~OptiTrack();
};