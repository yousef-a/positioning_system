#pragma once
#include "PVProvider.hpp"
#include "PositioningProvider.hpp"
#include "VelocityProvider.hpp"
#include "AccelerationProvider.hpp"
#include "ROSMsg.hpp"

class Z_PVProvider :    public PVProvider, 
                        public PositioningProvider, 
                        public VelocityProvider, 
                        public AccelerationProvider{

public:

    Vector3D<float> getProcessVariable();
    virtual PositionMsg getPosition() = 0;
    virtual VelocityMsg getVelocity() = 0;
    virtual AccelerationMsg getAcceleration() = 0;
    ROSMsg ros_msg;
    
    Z_PVProvider();
    ~Z_PVProvider();
};