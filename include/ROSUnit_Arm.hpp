#pragma once
#include "ROSUnit.hpp"
#include "FlightScenarioMessage.hpp"
#include <std_msgs/Bool.h>
#include "BoolMessage.hpp"
#include "Vector3D.hpp"
#include "BoolMessage.hpp"
#include <positioning_system/Arm.h>

class ROSUnit_Arm :  public ROSUnit{

    private:
        //TODO receive msgs from a service through a callback 
        static ROSUnit_Arm* _instance_ptr;
        static BoolMessage _bool_msg; 
        ros::ServiceServer _srv_armed;
        static bool callbackArm(positioning_system::Arm::Request  &req, positioning_system::Arm::Response &res);
        void receive_msg_data(DataMessage* t_msg);  

    public:
        ROSUnit_Arm(ros::NodeHandle&);
        ~ROSUnit_Arm();
};