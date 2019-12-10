#pragma once

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <std_msgs/Float32.h>

class ImageConverter
{

public:

	ImageConverter(std::string tmp);
	~ImageConverter();
	//passes the input topic
	void getImageTopic(std::string& tmp);
	//change the input topic
	void setImageTopic(std::string tmp);
	//passes the output topic
	bool getImage(cv_bridge::CvImagePtr& tmp);
	void showImage();


       
        
private:

	std::string CV_WINDOW;
	std::string INPUT_TOPIC;
    std::string OUTPUT_TOPIC;

	//ROS 
	ros::NodeHandle _nh;
	cv_bridge::CvImagePtr cv_ptr;
	ros::Publisher chatter_pub;
	image_transport::ImageTransport it_;
	image_transport::Subscriber image_sub_;
	image_transport::Publisher image_pub_;


	// ros <-> OpenCV
	void ros2cv(const sensor_msgs::ImageConstPtr& in_msg);
};
