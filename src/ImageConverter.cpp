#include "ImageConverter.hpp"

//#include <ros/ros.h>
ImageConverter::ImageConverter(std::string tmp) : it_(_nh)
{
    CV_WINDOW = "CV Image ";
    INPUT_TOPIC = tmp;
    OUTPUT_TOPIC = INPUT_TOPIC + "_output";
	image_sub_ = it_.subscribe(INPUT_TOPIC, 1, &ImageConverter::ros2cv, this);
    image_pub_ = it_.advertise(OUTPUT_TOPIC, 1);
    cv::namedWindow(CV_WINDOW, cv::WINDOW_NORMAL);
}

ImageConverter::~ImageConverter()
{
	cv::destroyWindow(CV_WINDOW);
}

void ImageConverter::getImageTopic(std::string& tmp)
{
    tmp = INPUT_TOPIC;
}

void ImageConverter::setImageTopic(std::string tmp)
{
    INPUT_TOPIC = tmp;
   image_sub_ = it_.subscribe(INPUT_TOPIC, 1, &ImageConverter::ros2cv, this);

}

void ImageConverter::ros2cv(const sensor_msgs::ImageConstPtr& in_msg)
{
	try
    {
      cv_ptr = cv_bridge::toCvCopy(in_msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
}

bool ImageConverter::getImage(cv_bridge::CvImagePtr& tmp)
{
	std::cout << "1s" << std::endl;
    if(cv_ptr != NULL)
    {
		std::cout << "2s" << std::endl;
        tmp = cv_ptr;
        return true;
    }
    else
    {
		std::cout << "3s" << std::endl;
        return false;
	}
}

void ImageConverter::showImage()
{
    // Update GUI Window
    std::cout << "1" << std::endl;
    cv::imshow(CV_WINDOW, cv_ptr->image);
    cv::waitKey(3);
    // Output modified video stream
    image_pub_.publish(cv_ptr->toImageMsg());
}

