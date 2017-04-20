#include <Arduino.h>
#include "main.h"
#include "robot/robot.h"

Robot pokebot(Serial);

#ifndef UNIT_TEST
void setup(){
  Serial.begin(9600);
  Serial.setTimeout(50);
}

void loop(){
  if(Serial.available()) {
    pokebot.processCommand((char) Serial.read());
  }
}
#endif
