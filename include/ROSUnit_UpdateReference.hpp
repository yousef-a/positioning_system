#pragma once
#include "ROSUnit.hpp"
#include "FlightScenarioMessage.hpp"
#include "UpdatePoseMessage.hpp"
#include <positioning_system/Waypoint.h>
#include "Vector3D.hpp"

class ROSUnit_UpdateReference :  public ROSUnit{

    private:
        //TODO receive msgs from a service through a callback 
        static ROSUnit_UpdateReference* _instance_ptr;
        static UpdatePoseMessage user_msg; 
        ros::Subscriber _sub_setpoint;
        static void callbackSetpoint(const positioning_system::Waypoint& msg);
        void receive_msg_data(DataMessage* t_msg);  

    public:
        ROSUnit_UpdateReference(ros::NodeHandle&);
        ~ROSUnit_UpdateReference();
};