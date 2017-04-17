#include <Arduino.h>
#include "main.h"
#include "robot/robot.h"

char command = ' ';
boolean commandReady = false;
Robot pokebot(Serial);

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(commandReady){
    pokebot.processCommand(command);
    clearCommand();
  }
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
