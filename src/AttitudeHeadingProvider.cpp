#include "AttitudeHeadingProvider.hpp"
#include <iostream>

AttitudeHeadingProvider::AttitudeHeadingProvider() {

    Vector3D _euler;
    Quaternion _quat;
}

AttitudeHeadingProvider::~AttitudeHeadingProvider() {

}

Vector3D AttitudeHeadingProvider::getEulerfromQuaternion(Quaternion q){

    // roll (x-axis rotation)
    double sinr_cosp = +2.0 * (q.w * q.x + q.y * q.z);
    double cosr_cosp = +1.0 - 2.0 * (q.x * q.x + q.y * q.y);
    _euler.x = atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = +2.0 * (q.w * q.y - q.z * q.x);
    if (fabs(sinp) >= 1)
        _euler.y = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        _euler.y = asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = +2.0 * (q.w * q.z + q.x * q.y);
    double cosy_cosp = +1.0 - 2.0 * (q.y * q.y + q.z * q.z);  
    _euler.z = atan2(siny_cosp, cosy_cosp);

    return _euler;
}

Quaternion AttitudeHeadingProvider::getQuaternionfromEuler(Vector3D data){

    std::cout << "Receive Euler and return Quaternion\n";

    return _quat;
}