#pragma once
#include "ROSUnit.hpp"
#include "FlightScenarioMessage.hpp"

class ROSUnit_FlightScenario :  public ROSUnit{

    private:
        //TODO receive msgs from a service through a callback 
        static ROSUnit_FlightScenario* _instance_ptr;
        static FlightScenarioMessage user_msg; 
        //ros::Subscriber _sub_attitude;
        //static void callbackOptitrack(const geometry_msgs::PoseStamped& msg);
        void receive_msg_data(DataMessage* t_msg);  

    public:
        ROSUnit_FlightScenario(ros::NodeHandle&);
        ~ROSUnit_FlightScenario();
};