#pragma once
#include "PositioningProvider.hpp"
#include "Quaternion.hpp"
#include "AttitudeProvider.hpp"
#include "HeadingProvider.hpp"
#include "VelocityProvider.hpp"
#include "AccelerationProvider.hpp"
#include "X_PVProvider.hpp"
#include "Yaw_PVProvider.hpp"

class MotionCapture :   public msg_receiver, 
                        public X_PVProvider,
                        public Yaw_PVProvider{

    public:
        virtual PositionMsg getPosition() = 0;
        virtual VelocityMsg getVelocity() = 0;
        virtual AccelerationMsg getAcceleration() = 0;
        virtual HeadingMsg getHeading() = 0;

        virtual void receive_msg_data(DataMessage* t_msg) = 0;

        MotionCapture();
        ~MotionCapture();
};