#include <Arduino.h>
#include "main.h"

String command = "";
boolean commandReady = false;

void setup(){
  Serial.begin(9600);
  Serial.println("Robot ready");
  command.reserve(200);
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
  command="";
  commandReady=false;
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char) Serial.read();
    command += inChar;
    if (inChar == '\n') {
      commandReady = true;
    }
  }
}
