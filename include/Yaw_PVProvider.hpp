#pragma once
#include "PVProvider.hpp"
#include "HeadingProvider.hpp"

class Yaw_PVProvider :  public PVProvider, 
                        public HeadingProvider{

public:

    Vector3D<float> getProcessVariable();
    virtual HeadingMsg getHeading() = 0;
    
    Yaw_PVProvider();
    ~Yaw_PVProvider();
};