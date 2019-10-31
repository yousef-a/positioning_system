#pragma once
#include "AttitudeProvider.hpp"
#include "HeadingProvider.hpp"
#include "Quaternion.hpp"
#include <math.h>

class AttitudeHeadingProvider : public AttitudeProvider, public HeadingProvider{

    private: 
        Quaternion _quat;
        Vector3D _euler;

    public:
        virtual Vector3D getAttitude() = 0; //TODO This implementation has to go to the IMU later 
        virtual double getHeading() = 0; //TODO This implementation has to go to the GPS later
        virtual Quaternion getAttitudeHeading() = 0;

        Vector3D getEulerfromQuaternion(Quaternion);
        Quaternion getQuaternionfromEuler(Vector3D);

        AttitudeHeadingProvider();
        ~AttitudeHeadingProvider();
};