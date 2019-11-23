#pragma once
#include "MotionCapture.hpp"
#include "Quaternion.hpp"
#include "OptitrackMessage.hpp"

class OptiTrack : public MotionCapture {

    private:
        Quaternion _bodyAtt;
        Vector3D _bodyPos;
        
    public:
        Quaternion getAttitudeHeading(); 
        Vector3D getPosition();
        Vector3D getAttitude(); 
        double getHeading(); 
        void receive_msg_data(DataMessage* t_msg);

        OptiTrack(std::string, block_type);
        ~OptiTrack();
};