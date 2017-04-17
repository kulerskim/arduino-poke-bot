#include <Arduino.h>
#include "main.h"
#include "robot/chassis.h"

char command = ' ';
boolean commandReady = false;

struct Robot{
  Chassis chassis;
} pokebot;

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
      pokebot.chassis.forward();
      break;
    case COMMAND_BACKWARD:
      Serial.println("backward");
      pokebot.chassis.backward();
      break;
    case COMMAND_TURN_LEFT:
      Serial.println("turn left");
      pokebot.chassis.turn_left();
      break;
    case COMMAND_TURN_RIGHT:
      Serial.println("turn right");
      pokebot.chassis.turn_right();
      break;
    default:
      Serial.println("Unknown command");
      break;
  }
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
