#include <Arduino.h>
#include "robot.h"

Robot::Robot(Stream& stream) : output(stream){
  this->output.println("Robot ready");
}

void Robot::processCommand(char command){
  switch(command){
    case this->COMMAND_FORWARD:
      this->output.println("forward");
      this->chassis.forward();
      break;
    case this->COMMAND_BACKWARD:
      this->output.println("backward");
      this->chassis.backward();
      break;
    case this->COMMAND_TURN_LEFT:
      this->output.println("turn left");
      this->chassis.turn_left();
      break;
    case this->COMMAND_TURN_RIGHT:
      this->output.println("turn right");
      this->chassis.turn_right();
      break;
    default:
      this->output.println("Unknown command");
      break;
  }
}
