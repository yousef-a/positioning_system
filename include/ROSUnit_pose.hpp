#pragma once
#include "ros/ros.h"
#include "ROSUnit.hpp"
#include "PositionMsg.hpp"
#include "HeadingMsg.hpp"
#include "AttitudeMsg.hpp"
#include <geometry_msgs/PoseStamped.h>
#include "Vector3D.hpp"


class ROSUnit_pose : public ROSUnit {

private:
    static ROSUnit_pose* _instance_ptr;
    ros::Subscriber _sub_pose;
    static PositionMsg _position_msg;
    static HeadingMsg _heading_msg;
    static AttitudeMsg _att_msg;
    static void callbackPose(const geometry_msgs::PoseStamped::ConstPtr& msg);
    void receive_msg_data(DataMessage* t_msg);  
public:
    ROSUnit_pose(ros::NodeHandle&);
    ~ROSUnit_pose();
};