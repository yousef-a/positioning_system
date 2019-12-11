#include "MotionCapture.hpp"

MotionCapture::MotionCapture(std::string t_name, block_type t_type) : PositioningProvider(t_name, t_type),
                                                                      AttitudeProvider(t_name, t_type),
                                                                      HeadingProvider(t_name, t_type),
                                                                      VelocityProvider(t_name, t_type),
                                                                      AccelerationProvider(t_name, t_type){

}

MotionCapture::~MotionCapture() {

}
