#pragma once
#include "ROSUnit.hpp"
#include "FlightScenarioMessage.hpp"
#include <std_msgs/Bool.h>
#include "BoolMessage.hpp"
#include "Vector3D.hpp"
#include "ResetControllerMessage.hpp"
#include <positioning_system/Reset_Controller.h>

class ROSUnit_ResetController :  public ROSUnit{

    private:
        //TODO receive msgs from a service through a callback 
        static ROSUnit_ResetController* _instance_ptr;
        static ResetControllerMessage _reset_msg; 
        ros::ServiceServer _srv_reset_controller;
        static bool callbackArm(positioning_system::Reset_Controller::Request  &req, positioning_system::Reset_Controller::Response &res);
        void receive_msg_data(DataMessage* t_msg);  

    public:
        ROSUnit_ResetController(ros::NodeHandle&);
        ~ROSUnit_ResetController();
};