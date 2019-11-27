#pragma once
#include "Vector3D.hpp"
#include "common_types.hpp"
#include "AttitudeProvider.hpp"
#include "PositioningProvider.hpp"
#include "HeadingProvider.hpp"

class GeneralStateProvider {

private:
    AttitudeProvider* _attitude_provider;
    PositioningProvider* _position_provider;
    HeadingProvider* _heading_provider;

public:

    Vector3D getProcessVariable(control_system);

    GeneralStateProvider(AttitudeProvider* , PositioningProvider*, HeadingProvider*);
    ~GeneralStateProvider();
};