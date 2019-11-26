#pragma once
#include "PositioningProvider.hpp"
#include "Quaternion.hpp"
#include "AttitudeHeadingProvider.hpp"

class MotionCapture : public PositioningProvider, public AttitudeProvider, public HeadingProvider{

    public:
        virtual Vector3D getPosition() = 0;
        virtual Quaternion getAttitudeHeading() = 0;
        virtual Vector3D getAttitude() = 0; 
        virtual double getHeading() = 0; 
        virtual void receive_msg_data(DataMessage* t_msg) = 0;

        MotionCapture(std::string, block_type);
        ~MotionCapture();
};