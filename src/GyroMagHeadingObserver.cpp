#include "GyroMagHeadingObserver.hpp"

GyroMagHeadingObserver::GyroMagHeadingObserver(AttitudeProvider* t_att_provider, BodyRateProvider* t_rate_provider, CompassProvider* t_compass)
{
    m_att_provider = t_att_provider;
    m_rate_provider = t_rate_provider;
    m_compass = t_compass;
}

void GyroMagHeadingObserver::setSettings(FilterSettings* t_settings)
{
    heading_filter->setFilterSettings(t_settings);
}

HeadingMsg GyroMagHeadingObserver::getHeading()
{
    HeadingMsg mag_heading;
    AttitudeMsg m_att_data;
    m_mag_data = m_compass->GetCompass();
    m_gyro_data = m_rate_provider->getBodyRate();
    m_att_data = m_att_provider->getAttitude();
    m_mag_heading = getMagHeading(m_att_data);
    filtered_heading.yaw = heading_filter->getFilteredData(mag_heading.yaw, m_gyro_data.z);
    return filtered_heading;    
}

HeadingMsg GyroMagHeadingObserver::getMagHeading(AttitudeMsg t_att_data)
{
    HeadingMsg tmp_mag_heading;
    float Bx, By;
    Bx = ((float)m_mag_data.x)*cos(t_att_data.roll) + ((float)m_mag_data.z)*sin(t_att_data.roll);
	By = ((float)m_mag_data.x)*sin(t_att_data.roll)*sin(t_att_data.pitch) + ((float)m_mag_data.y)*cos(t_att_data.pitch) - ((float)m_mag_data.z)*sin(t_att_data.pitch)*cos(t_att_data.roll);
    return tmp_mag_heading;
}