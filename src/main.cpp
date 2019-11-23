#include <iostream>
#include "../include/PositioningProvider.hpp"
#include "../include/UM8E.hpp"
#include "../include/OptiTrack.hpp"
#include "../include/ROSUnit.hpp"
#include "../include/ROSUnit_Optitrack.hpp"
#include "../include/msg_receiver.hpp"
#include "../include/msg_emitter.hpp"
#include "../include/PIDController.hpp"
#include "../include/Reference.hpp"
#include "../include/ControlSystem.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello Easy C++ project!" << std::endl;

    ros::init(argc, argv, "testing_node");

    ros::NodeHandle nh;
    ros::Rate rate(120);

    ROSUnit* myROSOptitrack = new ROSUnit_Optitrack(nh);

    //PositioningProvider* myPosSystem = new UM8E();
    //myPosSystem->getPosition();
    //Block* myPosSystem = new OptiTrack();

    Block* myPositioningSystem = new OptiTrack("OptiTrack", block_type::provider);
    MotionCapture* myMoCap = (MotionCapture*)myPositioningSystem;
    myMoCap->getAttitudeHeading();
    myMoCap->getPosition();
    Quaternion* quat = new Quaternion();
    myMoCap->getEulerfromQuaternion(*quat);
    Vector3D* euler = new Vector3D();
    myMoCap->getQuaternionfromEuler(*euler);

    myROSOptitrack->add_callback_msg_receiver((msg_receiver*)myMoCap);
    
    Block* myPIDController1 = new PIDController("PID1", block_type::controller);
    Block* myPIDController2 = new PIDController("PID2", block_type::controller);
    Block* myReference1 = new Reference("Ref1", block_type::reference);
    Block* myReference2 = new Reference("Ref2", block_type::reference);
    
    ControlSystem* myControlSystem = new ControlSystem();
    myControlSystem->addBlock(myPIDController1);
    myControlSystem->addBlock(myPIDController2);
    myControlSystem->addBlock(myReference1);
    myControlSystem->addBlock(myReference2);
    myControlSystem->getStatus(); //TODO delete getStatus, just for testing
    myControlSystem->switchBlock(nullptr, myPIDController1); 
    myControlSystem->switchBlock(nullptr, myReference1);
    myControlSystem->getStatus();
    myControlSystem->switchBlock(myPIDController1, myPIDController2);
    myControlSystem->getStatus();
    myControlSystem->switchBlock(myReference1, myReference2);
    myControlSystem->getStatus();
    myControlSystem->switchBlock(myReference2, myPIDController1);
    myControlSystem->getStatus();

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