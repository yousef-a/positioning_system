#include "ROSUnit.hpp"

ROSUnit::ROSUnit() {

}

ROSUnit::~ROSUnit() {

}
/*
void ROSUnit::init(int argc, char **argv, std::string node_name){

    ros::init(argc, argv, node_name);

    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(10);


    std::cout << "Initializing ROS Node" << std::endl;

}

void ROSUnit::spin(){

    while(ros::ok()){

        std::cout << "Node Running... \n";

        ros::spin();
    }
}
*/