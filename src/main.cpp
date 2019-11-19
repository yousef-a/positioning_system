#include <iostream>
#include "../include/PositioningProvider.hpp"
#include "../include/UM8E.hpp"
#include "../include/OptiTrack.hpp"
#include "../include/ROSUnit.hpp"
#include "../include/ROSUnit_Optitrack.hpp"
#include "../include/msg_receiver.hpp"
#include "../include/msg_emitter.hpp"
#include "../include/PID_Controller.hpp"
#include "../include/Reference.hpp"
#include "../include/ControlSystem.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello Easy C++ project!" << std::endl;


    //myROS->init(argc, argv, "testing_node");
    //myROS->spin();
    ros::init(argc, argv, "testing_node");

    ros::NodeHandle nh;
    ros::Rate rate(120);

    ROSUnit* myROSOptitrack = new ROSUnit_Optitrack(nh);

    //myROSPositioning->setsubscribers();

    PositioningProvider* myPosSystem = new UM8E();
    myPosSystem->getPosition();

    MotionCapture* myMoCap = new OptiTrack();
    myMoCap->getAttitudeHeading();
    myMoCap->getPosition();
    Quaternion* quat = new Quaternion();
    myMoCap->getEulerfromQuaternion(*quat);
    Vector3D* euler = new Vector3D();
    myMoCap->getQuaternionfromEuler(*euler);

    myROSOptitrack->add_callback_msg_receiver((msg_receiver*)myMoCap);
    
    Block* myPIDController1 = new PID_Controller("PID1", block_type::controller);
    Block* myPIDController2 = new PID_Controller("PID2", block_type::controller);
    Block* myReference = new Reference("Ref", block_type::reference);

    ControlSystem* myControlSystem = new ControlSystem();
        std::cout << "CONTROL SYSTEM 1" << std::endl;

    myControlSystem->getControllerSwitcher()->addBlock(myPIDController1);
        std::cout << "CONTROL SYSTEM 2" << std::endl;

    myControlSystem->getControllerSwitcher()->addBlock(myPIDController2);
        std::cout << "CONTROL SYSTEM 3" << std::endl;

    myControlSystem->getReferenceSwitcher()->addBlock(myReference);
        std::cout << "CONTROL SYSTEM 4" << std::endl;

    //myControlSystem->getStatus(); //TODO delete getStatus, just for testing
        std::cout << "CONTROL SYSTEM 5" << std::endl;

    myControlSystem->getControllerSwitcher()->setInitialCondition(myPIDController1, true); //TODO switchIn to activate controller
    //myControlSystem->getStatus();
    myControlSystem->switchAtControllerBlock(myPIDController1, myPIDController2);
    //myControlSystem->getStatus();
    std::cout << "CONTROL SYSTEM 5.1" << std::endl;

    // while(ros::ok()){
    //     myMoCap->getPosition();
    //     myMoCap->getAttitudeHeading();
    //     myMoCap->getAttitude();
    //     myMoCap->getHeading();
    //     ros::spinOnce();
    //     rate.sleep();
    // }

    return 0;

}