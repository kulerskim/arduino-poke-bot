#include <Arduino.h>
#include "main.h"

char command = ' ';
boolean commandReady = false;

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
  Serial.println("Processing: " + command);
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
