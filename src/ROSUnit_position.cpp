#include "ROSUnit_position.hpp"


ROSUnit_position* ROSUnit_position::_instance_ptr = NULL;
PositionMsg ROSUnit_position::position_msg;

ROSUnit_position::ROSUnit_position(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler){
    _sub_position = t_main_handler.subscribe("/body_position", 10, callbackPosition);
    _instance_ptr = this;
}

ROSUnit_position::~ROSUnit_position() {

}

void ROSUnit_position::callbackPosition(const geometry_msgs::PointStamped::ConstPtr& msg)
{
    position_msg.x = msg->point.x;
    position_msg.y = msg->point.y;
    position_msg.z = msg->point.z;

    _instance_ptr->emit_message((DataMessage*) &position_msg); 
}
 
void ROSUnit_position::receive_msg_data(DataMessage* t_msg){
}