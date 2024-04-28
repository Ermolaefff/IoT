#include <AFMotor.h>    

#define LEFT_MOTOR_PIN 1
#define RIGHT_MOTOR_PIN 2

#define MAX_SPEED 255
#define MIN_SPEED 0

AF_DCMotor motorL(LEFT_MOTOR_PIN); 
AF_DCMotor motorR(RIGHT_MOTOR_PIN); 

uint8_t unify_speed(int& speed) {
  uint8_t action;
  
  if (speed > 0) {
    action = FORWARD;
  } else if (speed < 0) {
    action = BACKWARD;
    speed *= -1;
  } else {
    action = RELEASE;
  }

  if (speed > MAX_SPEED)
    speed = MAX_SPEED;
  if (speed < MIN_SPEED)
    speed = MIN_SPEED;

  return action;
}

void left_motor(int speed) {
  uint8_t action = unify_speed(speed);
  motorL.setSpeed(speed);
  motorL.run(action); 
}

void right_motor(int speed) {
  uint8_t action = unify_speed(speed);
  motorR.setSpeed(speed);
  motorR.run(action); 
}

void motors_set_speeds(int speedL, int speedR) {
  left_motor(speedL);
  right_motor(speedR);
}
