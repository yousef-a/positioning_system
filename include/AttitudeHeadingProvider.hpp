#pragma once
#include "AttitudeProvider.hpp"
#include "HeadingProvider.hpp"
#include "Quaternion.hpp"

class AttitudeHeadingProvider : public AttitudeProvider, public HeadingProvider{

    private: 
        Quaternion _quat;
        Vector3D _euler;

    public:
        Vector3D getAttitude(); //TODO This implementation has to go to the IMU later (make it virtual here)
        double getHeading(); //TODO This implementation has to go to the GPS later (make it virtual here)
        virtual Quaternion getAttitudeHeading() = 0;

        Vector3D getEulerfromQuaternion(Quaternion);
        Quaternion getQuaternionfromEuler(Vector3D);

        AttitudeHeadingProvider();
        ~AttitudeHeadingProvider();
};