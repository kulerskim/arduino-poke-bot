#ifndef CHASSIS_h
#define CHASSIS_h

#include "Arduino.h"
#include <L298N.h>

class Chassis
{
  public:
    static const int DEFAULT_SPEED = 255;
    static const int STRAIGTH_MOVE_TIME = 1000;
    static const int STRAIGHT_TURN_TIME = 700;
    static const int MOTOR_PIN_ENA = 5;
    static const int MOTOR_PIN_IN1 = 2;
    static const int MOTOR_PIN_IN2 = 3;
    static const int MOTOR_PIN_IN3 = 4;
    static const int MOTOR_PIN_IN4 = 7;
    static const int MOTOR_PIN_ENB = 6;
    Chassis();
    void forward();
    void backward();
    void turn_left();
    void turn_right();
  private:
    static L298N* motors;
    void stop();
};

#endif
