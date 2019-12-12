#include <iostream>
#include <vector>
#include "../include/PositioningProvider.hpp"
#include "../include/UM8E.hpp"
#include "../include/OptiTrack.hpp"
#include "../include/ROSUnit.hpp"
#include "../include/ROSUnit_Optitrack.hpp"
#include "../include/MsgReceiver.hpp"
#include "../include/MsgEmitter.hpp"
#include "../include/PIDController.hpp"
#include "../include/Reference.hpp"
#include "../include/ControlSystem.hpp"
#include "../include/PID_values.hpp"
#include "../include/ProcessVariableReference.hpp"
#include "../include/Controller.hpp"
#include "../include/ActuationSystem.hpp"
#include "../include/PVProvider.hpp"
#include "../include/looper.hpp"
#include "../include/std_logger.hpp"
#include "../include/HexaActuationSystem.hpp"
#include "../include/esc_motor.hpp"
#include "../include/NavioMPU9250Sensor.hpp"
#include "../include/AccGyroAttitudeObserver.hpp"
#include "../include/GyroMagHeadingObserver.hpp"
#include "../include/ComplementaryFilter.hpp"
#include "../include/User.hpp"

void performCalibration(NAVIOMPU9250_sensor*);

int main(int argc, char** argv) {
    // std::cout << "Hello Easy C++ project!" << std::endl;
    //TODO separate files on specific folders
    
    ros::init(argc, argv, "testing_node");

    ros::NodeHandle nh;
    ros::Rate rate(300);

    ROSUnit* myROSOptitrack = new ROSUnit_Optitrack(nh);

    //*****************************LOGGER**********************************
    Logger::assignLogger(new StdLogger());

    //***********************ADDING SENSORS********************************
    // NAVIOMPU9250_sensor* myIMU = new NAVIOMPU9250_sensor();
    // myIMU->setSettings(ACCELEROMETER, FSR, 16);
    // myIMU->setSettings(GYROSCOPE, FSR, 2000);
    // myIMU->setSettings(MAGNETOMETER, FSR, 16);

    //***********************SETTING PROVIDERS**********************************
    MotionCapture* myOptitrackSystem = new OptiTrack();
    PositioningProvider* myPosProvider = (PositioningProvider*)myOptitrackSystem;
    HeadingProvider* myHeadProvider = (HeadingProvider*)myOptitrackSystem;
    VelocityProvider* myVelProvider = (VelocityProvider*)myOptitrackSystem;
    AccelerationProvider* myAccelProvider = (AccelerationProvider*)myOptitrackSystem;
    AttitudeProvider* myAttProvider = (AttitudeProvider*) myOptitrackSystem;
    
    // AccGyroAttitudeObserver myAttObserver("IMU Navio", block_type::provider, 
    //                                      (BodyAccProvider*) myIMU->getAcc(), 
    //                                      (BodyRateProvider*) myIMU->getGyro(),
    //                                      block_frequency::hhz1000);

    
    
    // ComplementaryFilter filter1, filter2, filter3;

    // ComplementaryFilterSettings settings(false, 0.001);

    // myAttObserver.setFilterType(&filter1, &filter2);
    // myAttObserver.updateSettings(&settings, 0.05);

    // AttitudeProvider* myAttProvider = (AttitudeProvider*) &myAttObserver;
    

    PVProvider* my_general_state_provider = new PVProvider( myAttProvider, 
                                                                                myPosProvider, 
                                                                                myHeadProvider,
                                                                                myVelProvider,
                                                                                myAccelProvider);

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

    //***********************SETTING CONTROL SYSTEMS***************************

    //TODO Expose switcher to the main, add blocks to the switcher, then make connections between switcher, then add them to the Control System
    ControlSystem* X_ControlSystem = new ControlSystem(control_system::x, my_general_state_provider, block_frequency::hz100);
    X_ControlSystem->addBlock(PID_x);
    X_ControlSystem->addBlock(PV_Ref_x);
    X_ControlSystem->getStatus();

    ControlSystem* Pitch_ControlSystem = new ControlSystem(control_system::pitch, my_general_state_provider, block_frequency::hz1000);
    Pitch_ControlSystem->addBlock(PID_pitch);
    Pitch_ControlSystem->addBlock(PV_Ref_pitch);
    Pitch_ControlSystem->getStatus();

    ControlSystem* Y_ControlSystem = new ControlSystem(control_system::y, my_general_state_provider, block_frequency::hz100);
    Y_ControlSystem->addBlock(PID_y);
    Y_ControlSystem->addBlock(PV_Ref_y);
    Y_ControlSystem->getStatus();

    ControlSystem* Roll_ControlSystem = new ControlSystem(control_system::roll, my_general_state_provider, block_frequency::hz1000);
    Roll_ControlSystem->addBlock(PID_roll);
    Roll_ControlSystem->addBlock(PV_Ref_roll);
    Roll_ControlSystem->getStatus();

    ControlSystem* Z_ControlSystem = new ControlSystem(control_system::z, my_general_state_provider, block_frequency::hz100);
    Z_ControlSystem->addBlock(PID_z);
    Z_ControlSystem->addBlock(PV_Ref_z);
    Z_ControlSystem->getStatus();

    //Yaw on Optitrack 100Hz
    ControlSystem* Yaw_ControlSystem = new ControlSystem(control_system::yaw, my_general_state_provider, block_frequency::hz100);
    Yaw_ControlSystem->addBlock(PID_yaw);
    Yaw_ControlSystem->addBlock(PV_Ref_yaw);
    Yaw_ControlSystem->getStatus();

    //*********************SETTING ACTUATION SYSTEMS************************

    int freq = 50;
    Actuator* M1 = new ESCMotor(0, freq);
    Actuator* M2 = new ESCMotor(1, freq);
    Actuator* M3 = new ESCMotor(2, freq);
    Actuator* M4 = new ESCMotor(3, freq);
    Actuator* M5 = new ESCMotor(4, freq);
    Actuator* M6 = new ESCMotor(5, freq);

    std::vector<Actuator*> actuators{M1, M2, M3, M4, M5, M6};

    ActuationSystem* myActuationSystem = new HexaActuationSystem(actuators);

    //***********************SETTING USER INPUTS****************************
    User* myUser = new User();

    //Forward is negative pitch, Right is positive roll, CCW is positive yaw, Upwards is positive Z
    UserMessage* test_user = new UserMessage(0, 0, 0, 0);

    //***********************SETTING PID VALUES*****************************

    PID_parameters* pid_para_test = new PID_parameters;
    pid_para_test->kp = 2.0;
    pid_para_test->ki = 0.0;
    pid_para_test->kd = 0.0;
    pid_para_test->kdd = 0.0;
    pid_para_test->anti_windup = 0;
    pid_para_test->en_pv_derivation = 0;
    X_ControlSystem->changePIDSettings(pid_para_test);

    pid_para_test->kp = 2.0;
    pid_para_test->ki = 1.0;
    pid_para_test->kd = 0.0;
    pid_para_test->kdd = 0.0;
    pid_para_test->anti_windup = 0;
    pid_para_test->en_pv_derivation = 0;
    Pitch_ControlSystem->changePIDSettings(pid_para_test);

    pid_para_test->kp = 2.0;
    pid_para_test->ki = 0.0;
    pid_para_test->kd = 0.0;
    pid_para_test->kdd = 0.0;
    pid_para_test->anti_windup = 0;
    pid_para_test->en_pv_derivation = 0;
    Y_ControlSystem->changePIDSettings(pid_para_test);

    pid_para_test->kp = 2.0;
    pid_para_test->ki = 1.0;
    pid_para_test->kd = 0.0;
    pid_para_test->kdd = 0.0;
    pid_para_test->anti_windup = 0;
    pid_para_test->en_pv_derivation = 0;
    Roll_ControlSystem->changePIDSettings(pid_para_test);

    pid_para_test->kp = 2.0;
    pid_para_test->ki = 1.0;
    pid_para_test->kd = 0.0;
    pid_para_test->kdd = 0.0;
    pid_para_test->anti_windup = 0;
    pid_para_test->en_pv_derivation = 0;
    Z_ControlSystem->changePIDSettings(pid_para_test);

    pid_para_test->kp = 2.0;
    pid_para_test->ki = 1.0;
    pid_para_test->kd = 0.0;
    pid_para_test->kdd = 0.0;
    pid_para_test->anti_windup = 0;
    pid_para_test->en_pv_derivation = 0;
    Yaw_ControlSystem->changePIDSettings(pid_para_test);
    

    //***********************SETTING CONNECTIONS****************************
    //========                                                      =============
    //|      |----->X_Control_System----->Roll_Control_System------>|           |
    //| USER |----->Y_Control_System----->Pitch_Control_System----->| Actuation |      
    //|      |----->Z_Control_System------------------------------->|  System   |
    //|      |----->Yaw_Control_System----------------------------->|           |
    //========                                                      =============
    
    myUser->add_callback_msg_receiver((msg_receiver*)X_ControlSystem);
    myUser->add_callback_msg_receiver((msg_receiver*)Y_ControlSystem);
    myUser->add_callback_msg_receiver((msg_receiver*)Z_ControlSystem);
    myUser->add_callback_msg_receiver((msg_receiver*)Yaw_ControlSystem);
    X_ControlSystem->add_callback_msg_receiver((msg_receiver*)Roll_ControlSystem);
    Roll_ControlSystem->add_callback_msg_receiver((msg_receiver*)myActuationSystem);
    Y_ControlSystem->add_callback_msg_receiver((msg_receiver*)Pitch_ControlSystem);
    Pitch_ControlSystem->add_callback_msg_receiver((msg_receiver*)myActuationSystem);
    Z_ControlSystem->add_callback_msg_receiver((msg_receiver*)myActuationSystem);
    Yaw_ControlSystem->add_callback_msg_receiver((msg_receiver*)myActuationSystem);

    myUser->emit_message((DataMessage*)test_user);
    
    //******************************LOOP***********************************
    
    pthread_t loop1khz_func_id, loop100hz_func_id, hwloop1khz_func_id; 
    struct sched_param params;

    Looper* myLoop = new Looper();
    myLoop->addTimedBlock((TimedBlock*)X_ControlSystem);
    myLoop->addTimedBlock((TimedBlock*)Y_ControlSystem);
    myLoop->addTimedBlock((TimedBlock*)Z_ControlSystem);
    myLoop->addTimedBlock((TimedBlock*)Roll_ControlSystem);
    myLoop->addTimedBlock((TimedBlock*)Pitch_ControlSystem);
    myLoop->addTimedBlock((TimedBlock*)Yaw_ControlSystem);
    //myLoop->addTimedBlock((TimedBlock*) &myAttObserver);

    // Creating a new thread 
    pthread_create(&loop1khz_func_id, NULL, &Looper::Loop1KHz, NULL);
    //pthread_create(&hwloop1khz_func_id, NULL, &Looper::hardwareLoop1KHz, NULL);
    pthread_create(&loop100hz_func_id, NULL, &Looper::Loop100Hz, NULL); 

    //Setting priority
    // params.sched_priority = sched_get_priority_max(SCHED_FIFO);
    // int ret = pthread_setschedparam(loop1khz_func_id, SCHED_FIFO, &params);
    // ret += pthread_setschedparam(hwloop1khz_func_id, SCHED_FIFO, &params);

    // params.sched_priority = sched_get_priority_max(SCHED_FIFO) - 1;
    // ret += pthread_setschedparam(loop100hz_func_id, SCHED_FIFO, &params);

    // if (ret != 0) {
    //      // Print the error
    //      std::cout << "Unsuccessful in setting thread realtime prior " << ret << std::endl;
    //      while(1){}
    //  }

    // performCalibration(myIMU);

    while(ros::ok()){

        ros::spinOnce();
        rate.sleep();
    }
    
    return 0;

}

void performCalibration(NAVIOMPU9250_sensor* t_imu){
    Timer* _calib_timer = new Timer();
    int consumed_time = 0;
    
    //1 second of garbage
    _calib_timer->tick();
    while(consumed_time < 1000){
        consumed_time = _calib_timer->tockMilliSeconds();
        t_imu->getAcc()->getCalibratedData();
        t_imu->getGyro()->getCalibratedData();
    }

    std::cout << "1 Second passed" << std::endl;
    
    t_imu->getAcc()->startCalibration();
    t_imu->getGyro()->startCalibration(); 
    std::cout << "CALIBRATION STARTED..." << std::endl;

    _calib_timer->tick();
    consumed_time = 0;
    std::cout << "CALIBRATION RUNNING....................................................................." << std::endl;
    while(consumed_time < 5000){
        consumed_time = _calib_timer->tockMilliSeconds();     
        t_imu->getAcc()->getCalibratedData();
        t_imu->getGyro()->getCalibratedData(); 
    }


    std::cout << "5 Second passed" << std::endl;
    t_imu->getAcc()->stopCalibration();
    t_imu->getGyro()->stopCalibration();
    std::cout << "CALIBRATION ENDED" << std::endl;

    _calib_timer->tick();
    consumed_time = 0;
    while(consumed_time < 5000){
        consumed_time = _calib_timer->tockMilliSeconds();    
    }

}