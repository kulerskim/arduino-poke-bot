#include <Arduino.h>
#include <L298N.h>
#include "main.h"

char command = ' ';
boolean commandReady = false;
L298N wheels(MOTOR_PIN_ENA,
             MOTOR_PIN_IN1,
             MOTOR_PIN_IN2,
             MOTOR_PIN_IN3,
             MOTOR_PIN_IN4,
             MOTOR_PIN_ENB);


void setup(){
  Serial.begin(9600);
  Serial.println("Robot ready");
}

void loop(){
  if(commandReady){
    processCommand();
  }
}

void processCommand(){
  switch(command){
    case COMMAND_FORWARD:
      Serial.println("forward");
      wheels.forward(STRAIGTH_MOVE_TIME);
      break;
    case COMMAND_BACKWARD:
      Serial.println("backward");
      wheels.backward(STRAIGTH_MOVE_TIME);
      break;
    case COMMAND_TURN_LEFT:
      Serial.println("turn left");
      wheels.turn_left(STRAIGHT_TURN_TIME);
      break;
    case COMMAND_TURN_RIGHT:
      Serial.println("turn right");
      wheels.turn_right(STRAIGHT_TURN_TIME);
      break;
    default:
      Serial.println("Unknown command");
      break;
  }
  wheels.stop_motors();
  clearCommand();
}

void clearCommand(){
  command=' ';
  commandReady=false;
}

void serialEvent() {
  while (Serial.available()) {
    command = (char) Serial.read();
    commandReady = true;
  }
}
