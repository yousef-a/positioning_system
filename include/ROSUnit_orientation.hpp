#pragma once
#include "ros/ros.h"
#include "ROSUnit.hpp"
#include "AttitudeMsg.hpp"
#include "HeadingMsg.hpp"
#include <geometry_msgs/PointStamped.h>
#include "Vector3D.hpp"

class ROSUnit_orientation : public ROSUnit{

private:
    static ROSUnit_orientation* _instance_ptr;
    ros::Subscriber _sub_orientation;
    static HeadingMsg heading_msg;
    static AttitudeMsg att_msg;
    static void callbackOrient(const geometry_msgs::PointStamped::ConstPtr& msg);
    void receive_msg_data(DataMessage* t_msg);  

public:
    ROSUnit_orientation(ros::NodeHandle&);
    ~ROSUnit_orientation();
};