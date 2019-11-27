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
#include "../include/GeneralStateProvider.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello Easy C++ project!" << std::endl;

    ros::init(argc, argv, "testing_node");

    ros::NodeHandle nh;
    ros::Rate rate(120);

    ROSUnit* myROSOptitrack = new ROSUnit_Optitrack(nh);

    //***********************SETTING PROVIDERS**********************************
    MotionCapture* myOptitrackSystem = new OptiTrack("OptiTrack", block_type::provider);
    PositioningProvider* myPosProvider = (PositioningProvider*)myOptitrackSystem;
    AttitudeProvider* myAttProvider = (AttitudeProvider*)myOptitrackSystem;
    HeadingProvider* myHeadProvider = (HeadingProvider*)myOptitrackSystem;
    
    GeneralStateProvider* my_general_state_provider = new GeneralStateProvider(myAttProvider, myPosProvider, myHeadProvider);

    myROSOptitrack->add_callback_msg_receiver((msg_receiver*)myOptitrackSystem);

    //**************************SETTING BLOCKS**********************************

    Block* PID_x = new PIDController("PID_x", block_type::controller);
    Block* PID_pitch = new PIDController("PID_pitch", block_type::controller);
    Block* PV_Ref_x = new ProcessVariableReference("Ref_x", block_type::reference);
    Block* PV_Ref_pitch = new ProcessVariableReference("Ref_pitch", block_type::reference);
    Block* PID_y = new PIDController("PID_y", block_type::controller);
    Block* PID_roll = new PIDController("PID_roll", block_type::controller);
    Block* PV_Ref_y = new ProcessVariableReference("Ref_y", block_type::reference);
    Block* PV_Ref_roll = new ProcessVariableReference("Ref_roll", block_type::reference);
    Block* PID_z = new PIDController("PID_z", block_type::controller);
    Block* PID_yaw = new PIDController("PID_yaw", block_type::controller);
    Block* PV_Ref_z = new ProcessVariableReference("Ref_z", block_type::reference);
    Block* PV_Ref_yaw = new ProcessVariableReference("Ref_yaw", block_type::reference);

    //***********************SETTING CONTROL SYSTEMS**********************************

    //TODO Expose switcher to the main, add blocks to the switcher, then make connections between switcher, then add them to the Control System
    ControlSystem* X_ControlSystem = new ControlSystem(control_system::x, my_general_state_provider);
    X_ControlSystem->addBlock(PID_x);
    X_ControlSystem->addBlock(PV_Ref_x);
    // X_ControlSystem->switchBlock(nullptr, PID_x);   //TODO Refactor so that the first block becomes the _active_block automatically
    // X_ControlSystem->switchBlock(nullptr, PV_Ref_x);
    X_ControlSystem->getStatus();
    ControlSystem* Pitch_ControlSystem = new ControlSystem(control_system::pitch, my_general_state_provider);
    Pitch_ControlSystem->addBlock(PID_pitch);
    Pitch_ControlSystem->addBlock(PV_Ref_pitch);
    // Pitch_ControlSystem->switchBlock(nullptr, PID_pitch);   //TODO Refactor so that the first block becomes the _active_block automatically
    // Pitch_ControlSystem->switchBlock(nullptr, PV_Ref_pitch);
    Pitch_ControlSystem->getStatus();

    ControlSystem* Y_ControlSystem = new ControlSystem(control_system::y, my_general_state_provider);
    Y_ControlSystem->addBlock(PID_y);
    Y_ControlSystem->addBlock(PV_Ref_y);
    // Y_ControlSystem->switchBlock(nullptr, PID_y);   //TODO Refactor so that the first block becomes the _active_block automatically
    // Y_ControlSystem->switchBlock(nullptr, PV_Ref_y);
    Y_ControlSystem->getStatus();
    ControlSystem* Roll_ControlSystem = new ControlSystem(control_system::roll, my_general_state_provider);
    Roll_ControlSystem->addBlock(PID_roll);
    Roll_ControlSystem->addBlock(PV_Ref_roll);
    // Roll_ControlSystem->switchBlock(nullptr, PID_roll);   //TODO Refactor so that the first block becomes the _active_block automatically
    // Roll_ControlSystem->switchBlock(nullptr, PV_Ref_roll);
    Roll_ControlSystem->getStatus();

    ControlSystem* Z_ControlSystem = new ControlSystem(control_system::z, my_general_state_provider);
    Z_ControlSystem->addBlock(PID_z);
    Z_ControlSystem->addBlock(PV_Ref_z);
    // Z_ControlSystem->switchBlock(nullptr, PID_z);   //TODO Refactor so that the first block becomes the _active_block automatically
    // Z_ControlSystem->switchBlock(nullptr, PV_Ref_z);
    Z_ControlSystem->getStatus();
    ControlSystem* Yaw_ControlSystem = new ControlSystem(control_system::yaw, my_general_state_provider);
    Yaw_ControlSystem->addBlock(PID_yaw);
    Yaw_ControlSystem->addBlock(PV_Ref_yaw);
    // Yaw_ControlSystem->switchBlock(nullptr, PID_yaw);   //TODO Refactor so that the first block becomes the _active_block automatically
    // Yaw_ControlSystem->switchBlock(nullptr, PV_Ref_yaw);
    Yaw_ControlSystem->getStatus();

    ActuationSystem* myActuationSystem = new ActuationSystem();
    msg_emitter* User = new msg_emitter();


    UserMessage* test_user = new UserMessage(123.0, 234.0, 345.0, 1.1234);

    PID_parameters* pid_para_test = new PID_parameters;
    pid_para_test->kp = 5.0;
    pid_para_test->ki = 2.0;
    pid_para_test->kd = 3.0;
    pid_para_test->kdd = 4.0;
    pid_para_test->anti_windup = 0.5;
    pid_para_test->en_pv_derivation = 1;// ActuationSystem* myActuationSystem = new ActuationSystem();
    X_ControlSystem->changePIDSettings(pid_para_test);
    Pitch_ControlSystem->changePIDSettings(pid_para_test);
    Y_ControlSystem->changePIDSettings(pid_para_test);
    Roll_ControlSystem->changePIDSettings(pid_para_test);
    Z_ControlSystem->changePIDSettings(pid_para_test);
    Yaw_ControlSystem->changePIDSettings(pid_para_test);


    User->add_callback_msg_receiver((msg_receiver*)X_ControlSystem);
    User->add_callback_msg_receiver((msg_receiver*)Y_ControlSystem);
    User->add_callback_msg_receiver((msg_receiver*)Z_ControlSystem);
    User->add_callback_msg_receiver((msg_receiver*)Yaw_ControlSystem);

    X_ControlSystem->add_callback_msg_receiver((msg_receiver*)Pitch_ControlSystem);
    Pitch_ControlSystem->add_callback_msg_receiver((msg_receiver*)myActuationSystem);
    
    Y_ControlSystem->add_callback_msg_receiver((msg_receiver*)Roll_ControlSystem);
    Roll_ControlSystem->add_callback_msg_receiver((msg_receiver*)myActuationSystem);

    Z_ControlSystem->add_callback_msg_receiver((msg_receiver*)myActuationSystem);
    Yaw_ControlSystem->add_callback_msg_receiver((msg_receiver*)myActuationSystem);

    
    std::cout << "==============================================" <<std::endl;
    User->emit_message((DataMessage*)test_user);
 
    // X_ControlSystem->loopInternal();
    // Pitch_ControlSystem->loopInternal();
    // Y_ControlSystem->loopInternal();
    // Roll_ControlSystem->loopInternal();
    // Z_ControlSystem->loopInternal();
    // Yaw_ControlSystem->loopInternal();

    // while(ros::ok()){
    //     X_ControlSystem->loopInternal();
    //     Pitch_ControlSystem->loopInternal();
    //     Y_ControlSystem->loopInternal();
    //     Roll_ControlSystem->loopInternal();
    //     Z_ControlSystem->loopInternal();
    //     Yaw_ControlSystem->loopInternal();
    //     ros::spinOnce();
    //     rate.sleep();
    // }
    
     std::cout << "DONE" << std::endl;
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
    
    // while(ros::ok()){
    //     myOptitrackSystem->getPosition();
    //     myOptitrackSystem->getAttitudeHeading();
    //     myOptitrackSystem->getAttitude();
    //     myOptitrackSystem->getHeading();
    //     ros::spinOnce();
    //     rate.sleep();
    // }

    //TODO add tests for implementation of message flow through the control system

    return 0;

}