#pragma once
#include "ros/ros.h"
#include <iostream>
#include <string>
#include "std_msgs/String.h"

class ROSUnit{

private:
    ros::NodeHandle main_handler;
    

public:
    ros::NodeHandle getNodeHandle();
    ROSUnit(ros::NodeHandle& _main_handler);
    ROSUnit();
    ~ROSUnit();
};