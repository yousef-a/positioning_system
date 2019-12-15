#pragma once
#include "PVProvider.hpp"
#include "HeadingProvider.hpp"
#include "BodyRateProvider.hpp"

class Yaw_PVProvider :  public PVProvider, 
                        public HeadingProvider,
                        public BodyRateProvider{

public:

    Vector3D<float> getProcessVariable();
    virtual HeadingMsg getHeading() = 0;
    //TODO this is only for the Optitrack case, remove later
    virtual Vector3D<float> getBodyRate() = 0;

    Yaw_PVProvider();
    ~Yaw_PVProvider();
};