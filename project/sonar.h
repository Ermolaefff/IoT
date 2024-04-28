#include <Servo.h>
#include <GyverFilters.h>
#include <NewPing.h>

#define ECHO_PIN 37
#define TRIG_PIN 36
#define SERVO_PIN 10

#define DIST_MAX 200    
#define MAX_ANGLE 170   
#define MIN_ANGLE 10    

NewPing sonar(TRIG_PIN, ECHO_PIN, DIST_MAX);
Servo servo; 
GMedian<8, int> filter;

float frame = 7.5 * 1000;
int double_frame = (int) (frame * 2);
int delta = MAX_ANGLE - MIN_ANGLE;

void setup_sonar() {
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN);
}

int get_angle() {
  unsigned long phase = millis() % double_frame;
  float relation = phase / frame; 
  return (int) (phase <= frame) ? (relation * delta + MIN_ANGLE) : (delta * (2 - relation) + MIN_ANGLE);
}

int rotate() {
  int angle = get_angle();
  servo.write(angle);
  return angle;
}

int prev_dist = 0;

int sonar_get_distance(int& angle_to_display, bool is_servo_active) {
  if (is_servo_active)
    angle_to_display = rotate();

  int curr_dist = sonar.ping_cm();

  if (curr_dist == 1000)
    curr_dist = prev_dist;
  if (curr_dist == 0 || curr_dist > DIST_MAX) 
    curr_dist = DIST_MAX;

  prev_dist = filter.filtered(curr_dist);
  return prev_dist;
}