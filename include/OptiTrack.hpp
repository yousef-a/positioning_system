#pragma once
#include "MotionCapture.hpp"
#include "Quaternion.hpp"
#include "OptitrackMessage.hpp"
#include <math.h>

class OptiTrack : public MotionCapture {

    private:
        Quaternion _bodyAtt;
        Vector3D _bodyPos;
        Vector3D _euler;
        Quaternion _quat;
        
    public:
        Quaternion getAttitudeHeading(); 
        PositionMsg getPosition();
        AttitudeMsg getAttitude(); 
        HeadingMsg getHeading(); 

        void receive_msg_data(DataMessage* t_msg);
        Vector3D getEulerfromQuaternion(Quaternion);
        Quaternion getQuaternionfromEuler(Vector3D);
    

        OptiTrack(std::string, block_type);
        ~OptiTrack();
};