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
#include "../include/PID_values.hpp"
#include "../include/ProcessVariableReference.hpp"
#include "../include/Controller.hpp"
#include "../include/ActuationSystem.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello Easy C++ project!" << std::endl;

    ros::init(argc, argv, "testing_node");

    ros::NodeHandle nh;
    ros::Rate rate(120);

    ROSUnit* myROSOptitrack = new ROSUnit_Optitrack(nh);

    //PositioningProvider* myPosSystem = new UM8E();
    //myPosSystem->getPosition();
    //Block* myPosSystem = new OptiTrack();

    Block* myOptitrackSystem = new OptiTrack("OptiTrack", block_type::provider);
    MotionCapture* myMoCap = (MotionCapture*)myOptitrackSystem;
    myMoCap->getAttitudeHeading();
    myMoCap->getPosition();
    Quaternion* quat = new Quaternion();
    myMoCap->getEulerfromQuaternion(*quat);
    Vector3D* euler = new Vector3D();
    myMoCap->getQuaternionfromEuler(*euler);

    myROSOptitrack->add_callback_msg_receiver((msg_receiver*)myMoCap);
    
    Block* PID_x = new PIDController("PID_x", block_type::controller);
    Block* PID_pitch = new PIDController("PID_pitch", block_type::controller);
    Block* PV_Ref_x = new ProcessVariableReference("Ref_x", block_type::reference);
    Block* PV_Ref_pitch = new ProcessVariableReference("Ref_pitch", block_type::reference);
    

    ControlSystem* X_ControlSystem = new ControlSystem(control_system::x);
    X_ControlSystem->addBlock(PID_x);
    X_ControlSystem->addBlock(PV_Ref_x);
    X_ControlSystem->addBlock(myOptitrackSystem);
    X_ControlSystem->switchBlock(nullptr, PID_x);   //TODO Refactor so that the first block becomes the _active_block automatically
    X_ControlSystem->switchBlock(nullptr, PV_Ref_x);
    X_ControlSystem->switchBlock(nullptr, myOptitrackSystem);
    X_ControlSystem->getStatus();
    ControlSystem* Pitch_ControlSystem = new ControlSystem(control_system::pitch);
    Pitch_ControlSystem->addBlock(PID_pitch);
    Pitch_ControlSystem->addBlock(PV_Ref_pitch);
    Pitch_ControlSystem->addBlock(myOptitrackSystem);
    Pitch_ControlSystem->switchBlock(nullptr, PID_pitch);   //TODO Refactor so that the first block becomes the _active_block automatically
    Pitch_ControlSystem->switchBlock(nullptr, PV_Ref_pitch);
    Pitch_ControlSystem->switchBlock(nullptr, myOptitrackSystem);
    Pitch_ControlSystem->getStatus();

    ActuationSystem* myActuationSystem = new ActuationSystem();
    msg_emitter* User = new msg_emitter();

    User->add_callback_msg_receiver((msg_receiver*)X_ControlSystem);
    X_ControlSystem->add_callback_msg_receiver((msg_receiver*)Pitch_ControlSystem);
    Pitch_ControlSystem->add_callback_msg_receiver((msg_receiver*)myActuationSystem);

    UserMessage* test_user = new UserMessage(1.0, 2.0, 3.0, 0.0);

    PID_parameters* pid_para_test = new PID_parameters;
    pid_para_test->kp = 5.0;
    pid_para_test->ki = 2.0;
    pid_para_test->kd = 3.0;
    pid_para_test->kdd = 4.0;
    pid_para_test->anti_windup = 0.5;
    pid_para_test->en_pv_derivation = 1;
    X_ControlSystem->changePIDSettings(pid_para_test);
    Pitch_ControlSystem->changePIDSettings(pid_para_test);

    User->emit_message((DataMessage*)test_user);
    X_ControlSystem->getProviderSwitcher()->loopInternal();
    Pitch_ControlSystem->getProviderSwitcher()->loopInternal();
    // Pitch_ControlSystem->getProviderSwitcher()->loopInternal();
    // Pitch_ControlSystem->getProviderSwitcher()->loopInternal();
    // //myControlSystem->addBlock(myReference2);
    // myControlSystem->addBlock(myPositioningSystem);
    // myControlSystem->getStatus(); //TODO delete getStatus, just for testing
    // myControlSystem->switchBlock(nullptr, myPIDController1); 
    // myControlSystem->switchBlock(nullptr, myReference1);
    // myControlSystem->switchBlock(nullptr, myPositioningSystem);
    // myControlSystem->getStatus();
    // myControlSystem->switchBlock(myPIDController1, myPIDController2);
    // myControlSystem->getStatus();
    // myControlSystem->switchBlock(myReference1, myReference2);
    // myControlSystem->getStatus();
    // myControlSystem->switchBlock(myReference2, myPIDController1);
    // myControlSystem->getStatus();

    
    // myControlSystem->getProviderSwitcher()->loopInternal(); // TODO refactor to send through msg
    // std::cout << "DONE" << std::endl;

    // //TODO add a Provider class between Block and the providers

    // while(ros::ok()){
    //     myControlSystem->getProviderSwitcher()->loopInternal();
    //     std::cout << "DONE" << std::endl;
    //     ros::spinOnce();
    //     rate.sleep();
    // }
    
    while(ros::ok()){
        myMoCap->getPosition();
        myMoCap->getAttitudeHeading();
        myMoCap->getAttitude();
        myMoCap->getHeading();
        ros::spinOnce();
        rate.sleep();
    }

    //TODO add tests for implementation of message flow through the control system

    return 0;

}