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
        ros::NodeHandle main_handler;
        ros::Subscriber sub_positioning;
        static void callbackPositioning(const geometry_msgs::PoseStamped& msg);
        void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type);

        ROSUnit_Positioning();
        ~ROSUnit_Positioning();
    public:
        void setSubscribers();
        
};