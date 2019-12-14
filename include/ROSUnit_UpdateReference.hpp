#pragma once
#include "ROSUnit.hpp"
#include "FlightScenarioMessage.hpp"
#include <geometry_msgs/PoseStamped.h>
#include "UserReferenceMessage.hpp"
#include "Vector3D.hpp"

class ROSUnit_UpdateReference :  public ROSUnit{

    private:
        //TODO receive msgs from a service through a callback 
        static ROSUnit_UpdateReference* _instance_ptr;
        static UserReferenceMessage user_msg; 
        ros::Subscriber _sub_setpoint;
        static void callbackSetpoint(const geometry_msgs::PoseStamped& msg);
        void receive_msg_data(DataMessage* t_msg);  

    public:
        ROSUnit_UpdateReference(ros::NodeHandle&);
        ~ROSUnit_UpdateReference();
};