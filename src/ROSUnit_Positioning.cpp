#include "ROSUnit_Positioning.hpp"
#include <iostream>

ROSUnit_Positioning::ROSUnit_Positioning() {

}

ROSUnit_Positioning::ROSUnit_Positioning(ros::NodeHandle& _main_handler){

    main_handler = _main_handler;

    sub_positioning = main_handler.subscribe("/Robot_1/pose", 10, callbackPositioning);
}

ROSUnit_Positioning::~ROSUnit_Positioning(){

}

void ROSUnit_Positioning::callbackPositioning(const geometry_msgs::PoseStamped& msg){

    std::cout << "CALLBACK POSITION\n";

}

