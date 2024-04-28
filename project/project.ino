#include "./dependencies.h"

#include "MPU9250.h"

MPU9250 mpu; // You can also use MPU9255 as is

void setup() 
{
  setup_sonar();
  setup_remote();
}

int current_sonar_angle;
int current_right_speed;
int current_left_speed;

void loop() 
{ 
  remote_input();

  remote_handle_connection();
  remote_get_speeds(current_left_speed, current_right_speed);

  motors_set_speeds(current_left_speed, current_right_speed);

  int distance = sonar_get_distance(current_sonar_angle, remote_is_servo_active());
  remote_handle_distance(current_sonar_angle, distance);
}

