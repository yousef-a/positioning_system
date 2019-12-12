#pragma once
#include "MotionCapture.hpp"
#include "Quaternion.hpp"
#include "OptitrackMessage.hpp"
#include <math.h>

class OptiTrack : public MotionCapture {

    private:
        Quaternion _bodyAtt;
        Vector3D<float> _bodyPos, _bodyVel, _bodyAcc;
        Vector3D<float> _prev_pos, _prev_vel; 
        Vector3D<float> _euler;
        Quaternion _quat;
        int j = 0;
        double _time, _prev_time;

    public:
        PositionMsg getPosition();
        AttitudeMsg getAttitude(); 
        HeadingMsg getHeading(); 
        VelocityMsg getVelocity();
        AccelerationMsg getAcceleration();

        void updateVelocity(double);
        void updateAcceleration(double);
        
        void receive_msg_data(DataMessage* t_msg);
        Vector3D<float> getEulerfromQuaternion(Quaternion);
        Quaternion getQuaternionfromEuler(Vector3D<float>);
        Quaternion getAttitudeHeading(); 

        OptiTrack();
        ~OptiTrack();
};