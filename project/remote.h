#include "./interface.h"
#define LED_PIN 13

void setup_remote() {
  RemoteXY_Init(); 
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);   
}

void remote_input() {
  RemoteXY_Handler();
}

bool remote_is_servo_active() {
  return RemoteXY.servo_switcher == 1;
}

void remote_handle_connection() {
  sprintf(RemoteXY.text, (RemoteXY.connect_flag == 0) ? "DISCONNECT" : "CONNECTED");
  // dtostrf(val, 0, 2, RemoteXY.text); 
}

int normalize_speed(int speed) {
  if (speed > 100) return 100;
  if (speed < -100) return -100;
  return speed;
}

void remote_get_speeds(int& left_speed, int& right_speed) {
  if (RemoteXY.connect_flag == 0) {
    left_speed = right_speed = 0;
    return;
  } 
  left_speed = normalize_speed(RemoteXY.joystick_y + RemoteXY.joystick_x) * 2.55;
  right_speed = normalize_speed(RemoteXY.joystick_y - RemoteXY.joystick_x) * 2.55;
}

void remote_handle_distance(int angle, int distance) {
  RemoteXY.online_graph = (float) distance;
  RemoteXY.circular_bar = 180 - angle;
}

