#pragma once
#include "ROSUnit.hpp"
#include "ROSMsg.hpp"
#include <geometry_msgs/PointStamped.h>

class ROSUnit_BroadcastData : public ROSUnit{

private:
    ros::Publisher _pos_prov_pub;
    static ROSUnit_BroadcastData* _instance_ptr;
    void receive_msg_data(DataMessage* t_msg); 
    int _seq_pos = 0, _seq_ori = 0, _seq_xpv = 0, _seq_ypv = 0, _seq_zpv = 0;
    int _seq_rollpv = 0, _seq_pitchpv = 0, _seq_yawpv = 0, _seq_cs = 0, _seq_act = 0;

public:
    ROSUnit_BroadcastData(ros::NodeHandle&);
    ~ROSUnit_BroadcastData();
};