#pragma once

#include "actuator.hpp"
#include <unistd.h>
#include "Navio2/PWM.h"
#include "Navio+/RCOutput_Navio.h"
#include "Navio2/RCOutput_Navio2.h"
#include "Common/Util.h"
#include <unistd.h>
#include <memory>

class esc_motor : public actuator {
private:
    int _pwmPin;
public:
    bool initialize();
    bool applyCommand(int command);
    esc_motor(int pin);
};