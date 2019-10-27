#include <iostream>
#include "../include/PositioningSystem.hpp"
#include "../include/UM8E.hpp"
#include "../include/OptiTrack.hpp"
#include "../include/ROSUnit.hpp"
#include "../include/ROSUnit_Positioning.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello Easy C++ project!" << std::endl;

    //myROS->init(argc, argv, "testing_node");
    //myROS->spin();
    ros::init(argc, argv, "testing_node");

    ros::NodeHandle nh;

    ROSUnit* myROSPositioning = new ROSUnit_Positioning(nh);

    myROSPositioning->setSubscribers();

    ros::spin();

    PositioningSystem* myPosSystem = new UM8E();
    myPosSystem->getPosition();

    MotionCapture* myMoCap = new OptiTrack();
    myMoCap->getAttitudeHeading();
    myMoCap->getPosition();
    Quaternion* quat = new Quaternion();
    myMoCap->getEulerfromQuaternion(*quat);
    Vector3D* euler = new Vector3D();
    myMoCap->getQuaternionfromEuler(*euler);

    return 0;

}