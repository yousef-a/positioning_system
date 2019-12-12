#pragma once
#include "PVProvider.hpp"

class X_PVProvider : public PVProvider{

public:

    Vector3D<float> getProcessVariable() {};

    X_PVProvider();
    ~X_PVProvider();
};