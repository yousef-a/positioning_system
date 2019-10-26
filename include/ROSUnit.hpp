#pragma once
#include "ros/ros.h"
#include <iostream>
#include <string>

class ROSUnit{

public:
    ros::NodeHandle init(int argc, char **argv, std::string topic_name);
    ROSUnit();
    ~ROSUnit();
};