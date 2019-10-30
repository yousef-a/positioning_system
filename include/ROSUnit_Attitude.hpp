#pragma once
#include "ros/ros.h"
#include <geometry_msgs/PoseStamped.h>
#include "ROSUnit.hpp"
#include "Vector3D.hpp"
#include "common_types.hpp"

class ROSUnit_Attitude : public ROSUnit{

    //Inherit the constructors
    using ROSUnit::ROSUnit;

    private:
        static ROSUnit_Attitude* instance_ptr;
        ros::NodeHandle main_handler;
        ros::Subscriber _sub_attitude;
        static void callbackAttitude(const geometry_msgs::PoseStamped& msg);
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);  
        
    public:
        ROSUnit_Attitude(ros::NodeHandle&);
        ~ROSUnit_Attitude();
        
};