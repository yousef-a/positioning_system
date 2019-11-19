#pragma once
#include "ros/ros.h"
#include <geometry_msgs/PoseStamped.h>
#include "ROSUnit.hpp"
#include "Vector3D.hpp"
#include "common_types.hpp"

class ROSUnit_Optitrack : public ROSUnit{

    //Inherit the constructors
    using ROSUnit::ROSUnit;

    private:
        static ROSUnit_Optitrack* _instance_ptr;
        ros::NodeHandle _main_handler;
        ros::Subscriber _sub_attitude;
        static void callbackOptitrack(const geometry_msgs::PoseStamped& msg);
        void receive_msg_data(DataMessage* t_msg);  
        
    public:
        ROSUnit_Optitrack(ros::NodeHandle&);
        ~ROSUnit_Optitrack();

};