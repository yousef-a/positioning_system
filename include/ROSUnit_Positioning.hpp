#pragma once
#include "ros/ros.h"
#include <geometry_msgs/PoseStamped.h>
#include "ROSUnit.hpp"
#include "Vector3D.hpp"
#include "common_types.hpp"

class ROSUnit_Positioning : public ROSUnit{

    //Inherit the constructors
    using ROSUnit::ROSUnit;

    private:
        static ROSUnit_Positioning* instance_ptr;
        ros::NodeHandle _main_handler;
        ros::Subscriber sub_positioning;
        static void callbackPositioning(const geometry_msgs::PoseStamped& msg);
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);  
        
    public:
        ROSUnit_Positioning(ros::NodeHandle&);
        ~ROSUnit_Positioning();
        
};