#pragma once
#include "PVProvider.hpp"
#include "AttitudeProvider.hpp"

class Pitch_PVProvider :    public PVProvider, 
                            public AttitudeProvider{

public:

    Vector3D<float> getProcessVariable();
    virtual AttitudeMsg getAttitude() = 0;
    
    Pitch_PVProvider();
    ~Pitch_PVProvider();
};