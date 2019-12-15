#pragma once
#include "ROSUnit.hpp"
#include "FlightScenarioMessage.hpp"
#include <geometry_msgs/PoseStamped.h>
#include "UserReferenceMessage.hpp"
#include "Vector3D.hpp"
#include "PID_values.hpp"
#include <positioning_system/PID_param.h>

class ROSUnit_UpdateController :  public ROSUnit{

    private:
        static ROSUnit_UpdateController* _instance_ptr;
        static PID_parameters _update_controller_msg; 
        ros::Subscriber _sub_update_controller_X;
        ros::Subscriber _sub_update_controller_Y;
        ros::Subscriber _sub_update_controller_Z;
        ros::Subscriber _sub_update_controller_Roll;
        ros::Subscriber _sub_update_controller_Pitch;
        ros::Subscriber _sub_update_controller_Yaw;
        static void callbackUpdateController_X(const positioning_system::PID_param& msg);
        static void callbackUpdateController_Y(const positioning_system::PID_param& msg);
        static void callbackUpdateController_Z(const positioning_system::PID_param& msg);
        static void callbackUpdateController_Roll(const positioning_system::PID_param& msg);
        static void callbackUpdateController_Pitch(const positioning_system::PID_param& msg);
        static void callbackUpdateController_Yaw(const positioning_system::PID_param& msg);
        void receive_msg_data(DataMessage* t_msg);  

    public:
        ROSUnit_UpdateController(ros::NodeHandle&, std::string);
        ~ROSUnit_UpdateController();
};