#pragma once
#include "ROSUnit.hpp"
#include "FlightScenarioMessage.hpp"

class ROSUnit_FlightScenario :  public ROSUnit{

    private:
        static ROSUnit_FlightScenario* _instance_ptr;
        static ROSUnit_FlightScenario user_msg; 
        void receive_msg_data(DataMessage* t_msg);  
  
    public:
        ROSUnit_FlightScenario(ros::NodeHandle&);
        ~ROSUnit_FlightScenario();
};