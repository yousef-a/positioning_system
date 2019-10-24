#include "AttitudeHeadingProvider.hpp"
#include <iostream>

AttitudeHeadingProvider::AttitudeHeadingProvider() {

    Vector3D _euler;
    Quaternion _quat;
}

AttitudeHeadingProvider::~AttitudeHeadingProvider() {

}

//TODO Remove these from here and send to the specific sensors
Vector3D AttitudeHeadingProvider::getAttitude(){
    return _euler;
}
double AttitudeHeadingProvider::getHeading(){
    return 0;
}
//------------------------------------------------------------

Vector3D AttitudeHeadingProvider::getEulerfromQuaternion(Quaternion data){

    std::cout << "Receive Quaternion and return Euler\n";

    return _euler;
}

Quaternion AttitudeHeadingProvider::getQuaternionfromEuler(Vector3D data){

    std::cout << "Receive Euler and return Quaternion\n";

    return _quat;
}