#pragma once
#include "PositioningSystem.hpp"
#include "Quaternion.hpp"
#include "AttitudeHeadingProvider.hpp"

class MotionCapture : public PositioningSystem, public AttitudeHeadingProvider{

    public:
        virtual Vector3D getPosition() = 0;
        virtual Quaternion getAttitudeHeading() = 0;
        virtual Vector3D getAttitude() = 0; 
        virtual double getHeading() = 0; 
        virtual void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type) = 0;

        MotionCapture();
        ~MotionCapture();
};