void setup();
void loop();
void processCommand();
void clearCommand();
void serialEvent();

const char COMMAND_FORWARD = 'f';
const char COMMAND_BACKWARD = 'b';
const char COMMAND_TURN_LEFT = 'l';
const char COMMAND_TURN_RIGHT = 'r';

const int DEFAULT_SPEED = 255;
const int STRAIGTH_MOVE_TIME = 1000;
const int STRAIGHT_TURN_TIME = 700;

const int MOTOR_PIN_ENA = 5;
const int MOTOR_PIN_IN1 = 2;
const int MOTOR_PIN_IN2 = 3;
const int MOTOR_PIN_IN3 = 4;
const int MOTOR_PIN_IN4 = 7;
const int MOTOR_PIN_ENB = 6;
