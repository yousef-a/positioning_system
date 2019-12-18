#pragma once
#include "PVProvider.hpp"
#include "AttitudeProvider.hpp"
#include "BodyRateProvider.hpp"
#include <math.h>

class Pitch_PVProvider :public PVProvider, 
                        public AttitudeProvider{

public:

    Vector3D<float> getProcessVariable();
    virtual AttitudeMsg getAttitude() = 0;
    virtual BodyRateProvider* getBodyRateProvider() = 0;
    
    Pitch_PVProvider();
    ~Pitch_PVProvider();
};