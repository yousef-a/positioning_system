#include "HeatCenterProvider.hpp"

float HeatCenterProvider::getThermalCutoff(void)
{
	return _t_cutoff;
}


void HeatCenterProvider::setDynThermalCutoff(float tmp)
{
	_t_cutoff = tmp;
}

int HeatCenterProvider::getThreshold(float tmp_min, float tmp_max)
{
	_t_threshold = (int) (((255.f)/((float)(tmp_max - tmp_min)))*(_t_cutoff - (float)tmp_min));
	if (_t_threshold < 0)
	{
		_t_threshold = 0;
	}
	return _t_threshold;
}

void HeatCenterProvider::calcFireCenter(cv::Mat tmp, CamSpecs cam)
{
	float* point;
	float my = 0, mry = 0, mx = 0, mrx = 0;
	cv::Mat col_sum, row_sum;
	
	reduce(tmp, col_sum, 0, cv::REDUCE_SUM, CV_32F);
	reduce(tmp, row_sum, 1, cv::REDUCE_SUM, CV_32F);

	point = row_sum.ptr<float>(0);
	for(int i = 0; i<row_sum.rows; i++)
	{
	    my = my + point[i];
	    mry = mry + point[i]*i;
	}

	point = col_sum.ptr<float>(0);
	for(int i = 0; i<col_sum.cols; i++)
	{
	    mx = mx + point[i];
	    mrx = mrx + point[i]*i;
	}

	int y = mry/my;
	int x = mrx/mx;
	calcFireAngles(x, y, cam);
}

void HeatCenterProvider::calcFireAngles(int x,int y, CamSpecs cam)
{
	orientation.yaw = (x-(cam.width/2))*cam.ang_per_px;
	orientation.pitch = ((cam.height/2)-y)*cam.ang_per_py;
}

NozzleOrientationMsg HeatCenterProvider::getHeatCenter(ThermalImageMsg* t_msg)
{
	cv::Mat t_image;
	try
	{
	cvtColor(t_msg->image, t_image, CV_BGR2GRAY);
	}
	catch(cv::Exception& e)
	{
		std::cout<< "ERROR " << std::endl;
	}
	try
	{
	threshold(t_image, t_image, getThreshold(t_msg->temp_min, t_msg->temp_max), 255, 3);
	}
	catch(cv::Exception& e)
	{
		std::cout<< "ERROR2 " << std::endl;
	}
	
	calcFireCenter(t_image, *(t_msg->cam_spec));
	return orientation;
}

DataMessage* HeatCenterProvider::receive_msg_internal(DataMessage*)
{

}

DataMessage* HeatCenterProvider::receive_msg_internal()
{

}

void HeatCenterProvider::receive_msg_data(DataMessage* t_msg)
{
	m_thermal_image = (ThermalImageMsg*) t_msg;
	this->getHeatCenter(m_thermal_image);
}