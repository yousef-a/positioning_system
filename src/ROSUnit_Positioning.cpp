#include "ROSUnit_Positioning.hpp"

ROSUnit_Positioning::ROSUnit_Positioning() {

}

ROSUnit_Positioning::~ROSUnit_Positioning() {

}

void ROSUnit_Positioning::subscribeToTopic(ros::NodeHandle& nh){

    ros::Subscriber sub = nh.subscribe("/Robot_1/pose", 10, ROSUnit_Positioning::callbackPositioning);

}

static void ROSUnit_Positioning::callbackPositioning(const geometry_msgs::PoseStamped& msg){



}

