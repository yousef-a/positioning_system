#include <iostream>
#include "../include/PositioningSystem.hpp"
#include "../include/UM8E.hpp"
#include "../include/OptiTrack.hpp"
#include "../include/ROSUnit.hpp"
#include "../include/ROSUnit_Optitrack.hpp"
#include "../include/msg_receiver.hpp"
#include "../include/msg_emitter.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello Easy C++ project!" << std::endl;


    //myROS->init(argc, argv, "testing_node");
    //myROS->spin();
    ros::init(argc, argv, "testing_node");

    ros::NodeHandle nh;
    ros::Rate rate(120);

    ROSUnit* myROSOptitrack = new ROSUnit_Optitrack(nh);

    //myROSPositioning->setSubscribers();

    PositioningSystem* myPosSystem = new UM8E();
    myPosSystem->getPosition();

    MotionCapture* myMoCap = new OptiTrack();
    myMoCap->getAttitudeHeading();
    myMoCap->getPosition();
    Quaternion* quat = new Quaternion();
    myMoCap->getEulerfromQuaternion(*quat);
    Vector3D* euler = new Vector3D();
    myMoCap->getQuaternionfromEuler(*euler);

    myROSOptitrack->add_callback_msg_receiver((msg_receiver*)myMoCap);

    while(ros::ok()){
        myMoCap->getPosition();
        myMoCap->getAttitudeHeading();
        myMoCap->getAttitude();
        myMoCap->getHeading();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;

}