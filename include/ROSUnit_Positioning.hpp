#pragma once
#include "ros/ros.h"
#include <geometry_msgs/PoseStamped.h>
#include "ROSUnit.hpp"

class ROSUnit_Positioning : public ROSUnit{

    //Inherit the constructors
    using ROSUnit::ROSUnit;

    private:
        ros::NodeHandle main_handler;
        ros::Subscriber sub_positioning;
        static void callbackPositioning(const geometry_msgs::PoseStamped& msg);
        

        ROSUnit_Positioning();
        ~ROSUnit_Positioning();
    public:
        void setSubscribers();
        //ROSUnit_Positioning(ros::NodeHandle&);
};