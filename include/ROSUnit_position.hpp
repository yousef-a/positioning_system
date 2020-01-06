#pragma once
#include "ros/ros.h"
#include "ROSUnit.hpp"
#include "PositionMsg.hpp"
#include <geometry_msgs/PointStamped.h>
#include "Vector3D.hpp"

class ROSUnit_position : public ROSUnit {


private:
    static ROSUnit_position* _instance_ptr;
    ros::Subscriber _sub_position;
    static PositionMsg position_msg;
    static void callbackPosition(const geometry_msgs::PointStamped::ConstPtr& msg);
    void receive_msg_data(DataMessage* t_msg);  

public:
    ROSUnit_position(ros::NodeHandle&);
    ~ROSUnit_position();
};