#pragma once
#include "ActuationSystem.hpp"
#include "ControlSystemMessage.hpp"

// GEOMETRY
//      CW(3) (5)CCW                x
//          \ /                   z ↑
// CCW(2) -- X -- (1)CW            \|
//          / \                     +----→ y
//      CW(6) (4)CCW
//
// For Positive Roll, all motors with negative Y should be increased
// For Positive Pitch, all motors with positive X should be increased
// For Positive Yaw, all motors with CCW should be increased
// Mx = [x, y, direction, thottle]

class HexaActuationSystem : public ActuationSystem {

private:    
    std::vector<Actuator*> _actuators;
    const int _escMin = 1000;
    const int _escMax = 2000;
    float _movements[4]; //[pitch, roll, yaw, throttle]
    float _commands[6];
    float _geometry[6][4] = {{ 0,           1 * -1, -1, 1},
                             { 0,          -1 * -1,  1, 1},
                             { 0.866025, -0.5 * -1, -1, 1},
                             {-0.866025,  0.5 * -1,  1, 1},
                             { 0.866025,  0.5 * -1,  1, 1},
                             {-0.866025, -0.5 * -1, -1, 1}};

public:

    void receive_msg_data(DataMessage* t_msg);
    void initialize();
    void command();
    int constrain(float value, int min_value, int max_value);

    HexaActuationSystem(std::vector<Actuator*>);
    ~HexaActuationSystem();
};