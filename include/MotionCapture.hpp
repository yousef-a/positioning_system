#pragma once
#include "PositioningProvider.hpp"
#include "Quaternion.hpp"
#include "AttitudeProvider.hpp"
#include "HeadingProvider.hpp"
#include "VelocityProvider.hpp"
#include "AccelerationProvider.hpp"

class MotionCapture : public msg_receiver, public PositioningProvider, public AttitudeProvider, 
                      public HeadingProvider, public VelocityProvider, public AccelerationProvider{

    public:
        virtual PositionMsg getPosition() = 0;
        virtual Quaternion getAttitudeHeading() = 0;
        virtual AttitudeMsg getAttitude() = 0; 
        virtual HeadingMsg getHeading() = 0; 
        virtual VelocityMsg getVelocity() = 0;
        virtual AccelerationMsg getAcceleration() = 0;

        virtual void receive_msg_data(DataMessage* t_msg) = 0;

        MotionCapture();
        ~MotionCapture();
};