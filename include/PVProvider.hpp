#pragma once
#include "Vector3DMessage.hpp"
#include "common_types.hpp"
#include "AttitudeProvider.hpp"
#include "PositioningProvider.hpp"
#include "HeadingProvider.hpp"
#include "VelocityProvider.hpp"
#include "AccelerationProvider.hpp"

class PVProvider : public Provider, public Vector3DMessage{

private:
    // AttitudeProvider* _attitude_provider;
    // PositioningProvider* _position_provider;
    // HeadingProvider* _heading_provider;
    // VelocityProvider* _velocity_provider;
    // AccelerationProvider* _acceleration_provider;

public:

    virtual Vector3D<float> getProcessVariable() = 0;

    // PVProvider(AttitudeProvider* , PositioningProvider*, HeadingProvider*, VelocityProvider*, AccelerationProvider*);
    PVProvider() {};
    // ~PVProvider();
};