// #pragma once
// #include "AttitudeProvider.hpp"
// #include "HeadingProvider.hpp"
// #include "Quaternion.hpp"
// #include <math.h>

// class AttitudeHeadingProvider{

//     private: 
//         Quaternion _quat;
//         Vector3D _euler;
//         provider_type _provider_type;

//     public:
//         virtual Vector3D getAttitude() = 0; //TODO This implementation has to go to the IMU later 
//         virtual double getHeading() = 0; //TODO This implementation has to go to the GPS later
//         virtual Quaternion getAttitudeHeading() = 0;

//         DataMessage* receive_msg_internal(DataMessage*);
//         DataMessage* receive_msg_internal();
//         provider_type getProviderType();

//         Vector3D getEulerfromQuaternion(Quaternion);
//         Quaternion getQuaternionfromEuler(Vector3D);

//         AttitudeHeadingProvider();
//         ~AttitudeHeadingProvider();
// };