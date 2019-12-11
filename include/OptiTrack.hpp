#pragma once
#include "MotionCapture.hpp"
#include "Quaternion.hpp"
#include "OptitrackMessage.hpp"
#include <math.h>

class OptiTrack : public MotionCapture {

    private:
        Quaternion _bodyAtt;
        Vector3D _bodyPos, _bodyVel, _bodyAcc;
        Vector3D _prev_pos, _prev_vel; 
        Vector3D _euler;
        Quaternion _quat;
        int j = 0;
        double _time, _prev_time;

    public:
        Quaternion getAttitudeHeading(); 
        PositionMsg getPosition();
        AttitudeMsg getAttitude(); 
        HeadingMsg getHeading(); 
        void updateVelocity(double);
        void updateAcceleration(double);
        VelocityMsg getVelocity();
        AccelerationMsg getAcceleration();

        void receive_msg_data(DataMessage* t_msg);
        Vector3D getEulerfromQuaternion(Quaternion);
        Quaternion getQuaternionfromEuler(Vector3D);
    

        OptiTrack(std::string, block_type);
        ~OptiTrack();
};