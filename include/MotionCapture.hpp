#pragma once
#include "PositioningProvider.hpp"
#include "Quaternion.hpp"
#include "AttitudeProvider.hpp"
#include "HeadingProvider.hpp"

class MotionCapture : public msg_receiver, public PositioningProvider, public AttitudeProvider, public HeadingProvider{

    public:
        virtual PositionMsg getPosition() = 0;
        virtual Quaternion getAttitudeHeading() = 0;
        virtual AttitudeMsg getAttitude() = 0; 
        virtual HeadingMsg getHeading() = 0; 

        virtual void receive_msg_data(DataMessage* t_msg) = 0;

        MotionCapture(std::string, block_type);
        ~MotionCapture();
};