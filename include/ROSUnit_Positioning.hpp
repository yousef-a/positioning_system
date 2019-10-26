#pragma once
#include "ros/ros.h"
#include <geometry_msgs/PoseStamped.h>

class ROSUnit_Positioning {

public:

    void subscribeToTopic(ros::NodeHandle&);
    static void callbackPositioning(const geometry_msgs::PoseStamped& msg);

    ROSUnit_Positioning();
    ~ROSUnit_Positioning();
};