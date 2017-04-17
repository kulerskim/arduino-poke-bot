/*
  L298N.h - Library for L298N motor driver
  Created by Yohendry Hurtado, 28 dec 2014
  Released into the public domain.
*/
#ifndef L298N_h
#define L298N_h

#include "Arduino.h"

class L298N
{
  public:
    static const int MOTOR_A = 0;
    static const int MOTOR_B = 1;
    static const int DEFAULT_SPEED = 255;
    L298N(int ena, int in1, int in2, int in3, int in4, int enb);
    void set_motor_speed(int motor_index, int speed);
    int get_motor_speed(int motor_index);
    void drive_motors();
    void drive_motor(int motor_index);
    void stop_motors();
    void stop_motor(int motor_index);
    void setup_motors(int state1, int state2, int state3, int state4);
    void setup_motor(int motor_index, int state1, int state2);
    void forward(int delay_time);
    void full_stop(int delay_time);
    void turn_right(int delay_time);
    void turn_left(int delay_time);
    void backward(int delay_time);
  private:
    struct Motor;
    int _ena;
    int _in1;
    int _in2;
    int _in3;
    int _in4;
    int _enb;
};

#endif
