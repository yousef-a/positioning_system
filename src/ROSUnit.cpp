#include "ROSUnit.hpp"

ROSUnit::ROSUnit() {

}

ROSUnit::~ROSUnit() {

}

ros::NodeHandle ROSUnit::init(int argc, char **argv, std::string topic_name){

    ros::init(argc, argv, topic_name);

    ros::NodeHandle n;

    std::cout << "Initializing ROS Node" << std::endl;

    return n; 

}