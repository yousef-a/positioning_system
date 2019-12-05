/*
Motors connected to PWM driver onboard of Navio2 shield for Raspberry Pi.

Connect motor to Navio2's rc output and watch it work.
PWM_OUTPUT = 0 complies to channel number 1, 1 to channel number 2 and so on.
To use full range of your motor correct SERVO_MIN and SERVO_MAX according to it's specification.

To run this example navigate to the directory containing it and run following commands:
make
sudo ./Servo
*/


#include "esc_motor.hpp"

#define freq 400

esc_motor::esc_motor(int pin){

    this->_pwmPin = pin;
    this->initialize();

}

std::unique_ptr <RCOutput> get_rcout(){

        if (get_navio_version() == NAVIO2){
            auto ptr = std::unique_ptr <RCOutput>{ new RCOutput_Navio2() };
            return ptr;
        } 

        else{
            auto ptr = std::unique_ptr <RCOutput>{ new RCOutput_Navio() };
            return ptr;
        }
        
}

auto pwm = get_rcout();

bool esc_motor::initialize(){

    if( !(pwm->initialize(esc_motor::_pwmPin)) ) {
        return 1;
    }

    pwm->set_frequency(esc_motor::_pwmPin, freq);

	if ( !(pwm->enable(esc_motor::_pwmPin)) ) {
	    return 1;
	}


}

bool esc_motor::applyCommand(int command){

    pwm->set_duty_cycle(esc_motor::_pwmPin, command);

}


