#pragma once
#include "ros/ros.h"
#include <geometry_msgs/PoseStamped.h>


class ROSUnit_Positioning {

    private:
        ros::NodeHandle main_handler;
        ros::Subscriber sub_positioning;
        static void callbackPositioning(const geometry_msgs::PoseStamped& msg);

        ROSUnit_Positioning();
        ~ROSUnit_Positioning();
    public:

        ROSUnit_Positioning(ros::NodeHandle&);
};