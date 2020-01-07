#include "detectionAlgo.hpp"

//detectionAlgo* detectionAlgo::_instance_ptr = NULL;
//FireLineDescription detectionAlgo::_fire_line;


// Vector3D<float> detectionAlgo::intersectPoint(Vector3D<float> rayVector, Vector3D<float> rayPoint, Vector3D<float> planeNormal, Vector3D<float> planePoint) {
//         Vector3D<float> diff = rayPoint - planePoint;
//         double prod1 = diff^planeNormal;
//         double prod2 = rayVector^planeNormal;
//         double prod3 = prod1 / prod2;
//         return rayPoint - (rayVector*prod3);
// }


detectionAlgo::detectionAlgo() {

    //_instance_ptr = this;

}

detectionAlgo::~detectionAlgo() {

}

void detectionAlgo::receive_msg_data(DataMessage* t_msg){

    if(t_msg->getType() == msg_type::DARKNET_ROS){
        DarknetMessage* t_DarknetMSG = ((DarknetMessage*)t_msg);
        prob = t_DarknetMSG->probability;
        target_x = (t_DarknetMSG->xmax + t_DarknetMSG->xmin) / 2;
        target_y = (t_DarknetMSG->ymax + t_DarknetMSG->ymin) / 2;
        detection_algo();
    }

    if(t_msg->getType() == msg_type::POSITION){
        PositionMsg* t_pos = ((PositionMsg*)t_msg);

        curr_position.x = t_pos->x; 
        curr_position.y = t_pos->y; 
        curr_position.z = t_pos->z;
    }

    else if (t_msg->getType() == msg_type::HEADING){
        HeadingMsg* t_heading = ((HeadingMsg*)t_msg);
        yaw = t_heading->yaw;
    }

    // else if (t_msg->getType() == msg_type::ATTITUDE){
    //     AttitudeMsg* t_att = ((AttitudeMsg*)t_msg);
    //     roll = t_att->roll;
    //     pitch = t_att->pitch;
    // }

}
void detectionAlgo::detection_algo()
{
    vector<cv::Point2f> in_points(1);
    vector<cv::Point2f> imagePoints(1);
    in_points.at(0).x = target_x;
    in_points.at(0).y = target_y;
    RotationMatrix3by3 rot_matrix;
    undistortPoints(in_points, imagePoints, cameraMatrix, distCoeffs, cv::noArray(), cameraMatrix);
    //cout << "Before distortion (x,y): " << target_x << " " << target_y << endl;
    //cout << "After  distortion (x,y): " << imagePoints.at(0) << endl;


    double pxl_hztl= imagePoints.at(0).x - cam_width/2;
    double pxl_vrtl= imagePoints.at(0).y - cam_height/2;

    double hztl_ratio = tan((hztl_fov/2)*(M_PI/180.));
    double vrtl_ratio = tan((vrtl_fov/2)*(M_PI/180.));

    // //TODO: review directions 
    double x_tmp = atan(hztl_ratio*pxl_hztl/(cam_width/2));
    double z_tmp = atan(vrtl_ratio*pxl_vrtl/(cam_height/2));

    double x_angle = atan(hztl_ratio*pxl_hztl/(cam_width/2)); 
    double z_angle = atan(vrtl_ratio*pxl_vrtl/(cam_height/2));


    cout << "ugv heading: " << (yaw*180/M_PI) << endl;
    cout << "cam  angles: " << x_tmp*180/M_PI << " " << z_tmp*180/M_PI << endl;

    Vector3D<float> angles_vector;
    Vector3D<float> angles_ugv;
    Vector3D<float> angles_stepper;
    Vector3D<float> aux_point;
   
    
    aux_point.x = 1;
    aux_point.y = 0;
    aux_point.z = 0;

    angles_vector.x = z_angle;//pitch;
    angles_vector.y = 0;//roll;
    angles_vector.z = -1*x_angle;//yaw; // todo: move to publisher.
    
    angles_ugv.x = 0;
    angles_ugv.y = 0;
    angles_ugv.z = yaw;

    angles_stepper.x = 0;
    angles_stepper.y = 0;
    angles_stepper.z = 0;   //TODO: angles of stepper motor


    //first  transform (ugv body)
    rot_matrix.Update(angles_ugv); 
    Vector3D<float> tf_point = rot_matrix.TransformVector(aux_point);
    //second transform (stepper motor)
    rot_matrix.Update(angles_stepper);
    Vector3D<float> tf_point2 = rot_matrix.TransformVector(tf_point);
    //third transform (camera angles)
    rot_matrix.Update(angles_vector);
    Vector3D<float> tf_point3 = rot_matrix.TransformVector(tf_point2);

    //translation of point
    Vector3D<float> final_point;
    final_point.x = curr_position.x + tf_point3.x;
    final_point.y = curr_position.y + tf_point3.y;
    final_point.z = curr_position.z + tf_point3.z;

    cout << "current point: " << curr_position.x << " " << curr_position.y << " " << curr_position.z <<endl;
    cout << "2nd tf point: " << tf_point3.x << " " << tf_point3.y << " " << tf_point3.z <<endl;
    cout << "final point:  " << final_point.x << " " << final_point.y << " " << final_point.z <<endl;
    cout << "-----------------------------------------------------------------------" << endl;


    _fire_line.setFireLineMessage(curr_position, tf_point3);
    this->emit_message((DataMessage*) &_fire_line); 

}