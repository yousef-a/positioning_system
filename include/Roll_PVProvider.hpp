#pragma once
#include "PVProvider.hpp"
#include "AttitudeProvider.hpp"
#include "BodyRateProvider.hpp"
#include <math.h>

class Roll_PVProvider : public PVProvider, 
                        public AttitudeProvider{

public:

    Vector3D<float> getProcessVariable();
    virtual AttitudeMsg getAttitude() = 0;
    virtual BodyRateProvider* getBodyRateProvider() = 0;
    Roll_PVProvider();
    ~Roll_PVProvider();
};