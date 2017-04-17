#include "Arduino.h"
#include <L298N.h>
#include "chassis.h"

L298N* Chassis::motors = new L298N(Chassis::MOTOR_PIN_ENA,
                                   Chassis::MOTOR_PIN_IN1,
                                   Chassis::MOTOR_PIN_IN2,
                                   Chassis::MOTOR_PIN_IN3,
                                   Chassis::MOTOR_PIN_IN4,
                                   Chassis::MOTOR_PIN_ENB);

Chassis::Chassis(){}

void Chassis::forward(){
  this->motors->forward(this->STRAIGTH_MOVE_TIME);
  this->stop();
};
void Chassis::backward(){
  this->motors->backward(this->STRAIGTH_MOVE_TIME);
  this->stop();
};
void Chassis::turn_left(){
  this->motors->turn_left(this->STRAIGHT_TURN_TIME);
  this->stop();
};
void Chassis::turn_right(){
  this->motors->turn_right(this->STRAIGHT_TURN_TIME);
  this->stop();
};

void Chassis::stop(){
  this->motors->full_stop(0);
}
