#include <Arduino.h>
#include "chassis.h"

class Robot{
  public:
    static const char COMMAND_FORWARD = 'f';
    static const char COMMAND_BACKWARD = 'b';
    static const char COMMAND_TURN_LEFT = 'l';
    static const char COMMAND_TURN_RIGHT = 'r';
    Robot(Stream& stream);
    Chassis chassis;
    void processCommand(char command);
  private:
    Stream& output;
};
