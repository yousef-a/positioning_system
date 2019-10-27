#include "ROSUnit_Positioning.hpp"
#include <iostream>

ROSUnit_Positioning::ROSUnit_Positioning() {

}


ROSUnit_Positioning::~ROSUnit_Positioning(){

}

void ROSUnit_Positioning::setSubscribers(){

    sub_positioning = main_handler.subscribe("/Robot_1/pose", 10, callbackPositioning);

}


void ROSUnit_Positioning::callbackPositioning(const geometry_msgs::PoseStamped& msg){

    std::cout << msg;
}

