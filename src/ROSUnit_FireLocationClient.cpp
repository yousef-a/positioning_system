#include "ROSUnit_FireLocationClient.hpp"

ROSUnit_FireLocationClient::ROSUnit_FireLocationClient(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _srv_client = t_main_handler.serviceClient<positioning_system::twoPointLine> ("two_point_line");
    
}

ROSUnit_FireLocationClient::~ROSUnit_FireLocationClient() {

}

void ROSUnit_FireLocationClient::receive_msg_data(DataMessage* t_msg)
{
    if(t_msg->getType() == msg_type::FIRE_LINE_DESC){
        FireLineDescription* t_lineMsg = ((FireLineDescription*)t_msg);
        _point1 = t_lineMsg->point1;
        _point2 = t_lineMsg->point2;

        
        //service call parameters set
        positioning_system::twoPointLine srv;
        srv.request.p1.x = _point1.x;
        srv.request.p1.y = _point1.y;
        srv.request.p1.z = _point1.z;

        srv.request.p2.x = _point2.x;
        srv.request.p2.y = _point2.y;
        srv.request.p2.z = _point2.z;

        _srv_client.call(srv);

        // //recieving from service server
        // _fire_location.x = srv.response.xyz.x;
        // _fire_location.y = srv.response.xyz.y;
        // _fire_location.z = srv.response.xyz.z;
    
        //cout << "collision point x, y, z: " << _fire_location.x << " " << _fire_location.y << " " << _fire_location.z << endl;
    }
}