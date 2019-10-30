#pragma once
#include "ros/ros.h"
#include <iostream>
#include <string>
#include "std_msgs/String.h"
#include "msg_receiver.hpp"
#include "msg_emitter.hpp"


class ROSUnit : public msg_emitter, public msg_receiver{

    private:
        ros::NodeHandle main_handler;

    public:
        ros::NodeHandle getNodeHandle();
        virtual void setSubscribers() = 0;
        virtual void receive_msg_data(uint8_t data[],std::size_t len, msg_type _msg_type) = 0;
        //template<typename T>
        void serializeData(double data[], int len, uint8_t wtv[]); // member template
        
        ROSUnit(ros::NodeHandle& _main_handler);
        ROSUnit();
        ~ROSUnit();        
    protected:
        
        
};