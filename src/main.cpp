#include "ros/ros.h"
#include "ROSUnit_dark.hpp"
//#include "ROSUnit_position.hpp"
//#include "ROSUnit_orientation.hpp"
#include "ROSUnit_pose.hpp"
#include "ROSUnit_FireLocationClient.hpp"
#include "detectionAlgo.hpp"

int main(int argc, char **argv){

    ros::init(argc, argv, "fire_localization");
    ros::NodeHandle nh;
    ros::Rate loop_rate(100);

    ROSUnit_dark* ROS_dark = new ROSUnit_dark(nh);
    ROSUnit_pose* ROS_pose = new ROSUnit_pose(nh);
    ROSUnit_FireLocationClient* ROS_fire_loc_client = new ROSUnit_FireLocationClient(nh);
    detectionAlgo* algorithm_block = new detectionAlgo; 
    
    ROS_dark->add_callback_msg_receiver((msg_receiver*) algorithm_block);
    ROS_pose->add_callback_msg_receiver((msg_receiver*) algorithm_block);
    algorithm_block->add_callback_msg_receiver((msg_receiver*) ROS_fire_loc_client);
    

    
    while (ros::ok()){
    
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}