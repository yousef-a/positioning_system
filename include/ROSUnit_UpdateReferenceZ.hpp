#pragma once
#include "ROSUnit.hpp"
#include "FlightScenarioMessage.hpp"
#include "UpdatePoseMessage.hpp"
#include <positioning_system/Update_Z_Reference.h>
#include "Vector3D.hpp"

class ROSUnit_UpdateReferenceZ :  public ROSUnit{

    private:
        //TODO receive msgs from a service through a callback 
        static ROSUnit_UpdateReferenceZ* _instance_ptr;
        static UpdatePoseMessage _pose_ref_msg; 
        ros::ServiceServer _srv_setpoint;
        static bool callbackSetpoint(positioning_system::Update_Z_Reference::Request  &req, 
                                     positioning_system::Update_Z_Reference::Response &res);
        void receive_msg_data(DataMessage* t_msg);  

    public:
        ROSUnit_UpdateReferenceZ(ros::NodeHandle&);
        ~ROSUnit_UpdateReferenceZ();
};