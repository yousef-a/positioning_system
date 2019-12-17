#include "ROSUnit_BroadcastData.hpp"
ROSUnit_BroadcastData* ROSUnit_BroadcastData::_instance_ptr = NULL;

ROSUnit_BroadcastData::ROSUnit_BroadcastData(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler){

    _pos_prov_pub = t_main_handler.advertise<geometry_msgs::PointStamped>("body_position", 10);
    _instance_ptr = this;
}

ROSUnit_BroadcastData::~ROSUnit_BroadcastData() {

}


void ROSUnit_BroadcastData::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::ROS){
        ROSMsg* ros_msg = (ROSMsg*)t_msg;

        if(ros_msg->getROSMsgType() == ros_msg_type::POSITION){
            Vector3D<float> pos = ros_msg->getPosition();
            geometry_msgs::PointStamped msg;
            msg.header.seq = ++_seq_pos;
            msg.header.stamp = ros::Time::now();
            msg.header.frame_id = "body";
            msg.point.x = pos.x;
            msg.point.y = pos.y;
            msg.point.z = pos.z;
            _pos_prov_pub.publish(msg);

        }else if(ros_msg->getROSMsgType() == ros_msg_type::ORIENTATION){

        }else if(ros_msg->getROSMsgType() == ros_msg_type::X_PV){
            
        }else if(ros_msg->getROSMsgType() == ros_msg_type::Y_PV){
            
        }else if(ros_msg->getROSMsgType() == ros_msg_type::Z_PV){
            
        }else if(ros_msg->getROSMsgType() == ros_msg_type::ROLL_PV){
            
        }else if(ros_msg->getROSMsgType() == ros_msg_type::PITCH_PV){
            
        }else if(ros_msg->getROSMsgType() == ros_msg_type::YAW_PV){
            
        }else if(ros_msg->getROSMsgType() == ros_msg_type::CONTROLSYSTEM){
            
        }else if(ros_msg->getROSMsgType() == ros_msg_type::ACTUATION){
            
        }

    }

}