#include <AmperkaStepper.h>
#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN_1  23
#define ECHO_PIN_1     25
#define TRIGGER_PIN_2  27
#define ECHO_PIN_2     29
#define TRIGGER_PIN_3  31
#define ECHO_PIN_3     33
#define TRIGGER_PIN_4  35
#define ECHO_PIN_4     37
#define MAX_DISTANCE 400
#define SERVO_PIN_1 9
#define SERVO_PIN_2 10
#define SPEED_1 5
#define DIR_1 4
int edr = 60;
int edl = 50;

NewPing sonar_1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar_2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar_3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
NewPing sonar_4(TRIGGER_PIN_4, ECHO_PIN_4, MAX_DISTANCE);
Servo servo_1;
int s_out_1 = 90;
float dist_1 = 0;
float dist_2 = 0;
float dist_3 = 0;
float dist_4 = 0;




void setup() {
  servo_1.attach(SERVO_PIN_1);
  pinMode(SPEED_1, OUTPUT);
  pinMode(DIR_1, OUTPUT);
  delay(5000);
}

void loop() {
  digitalWrite(DIR_1, LOW);
  analogWrite(SPEED_1, 75);
  while (1){
    dist_1 = sonar_1.ping_cm();
    dist_2 = sonar_2.ping_cm();
    Serial.println(dist_1);
    if (dist_1 > edr){
      s_out_1 = 100;
    }
    if (dist_1 < edr){
      s_out_1 = 110;
    }
    servo_1.write(s_out_1);
    if ((dist_2 <= 60)and(dist_2>10)){
      break;    
    }
    delay(50);
  }
  servo_1.write(180);
  analogWrite(SPEED_1, 200);
  delay(2000);
  servo_1.write(100);
  analogWrite(SPEED_1, 75);
  while (1){
    dist_1 = sonar_1.ping_cm();
    dist_2 = sonar_2.ping_cm();
    Serial.println(dist_1);
    if (dist_1 > edr){
      s_out_1 = 100;
    }
    if (dist_1 < edr){
      s_out_1 = 110;
    }
    servo_1.write(s_out_1);
    if ((dist_2 <= 60)and(dist_2>10)){
      break;    
    }
    delay(50);
  }
  digitalWrite(DIR_1, HIGH);
  analogWrite(SPEED_1, 180);
  delay(2000);
  analogWrite(SPEED_1, 0);
  delay(10000);
}
//int reg_right(int edr,float dist_1,int s_out_1) {
//  if (dist_1 > edr){
//    s_out_1 = 70;
//  }
//  else if (dist_1 < edr){
//    s_out_1 = 180;
//  }
//  else{
//    s_out_1 = 110;
//  }
//  return s_out_1;
//}
//int reg_left(int edl,float dist_3,int s_out_1) {
//  if (dist_3 > edl){
//    s_out_1 = 180;
//  }
//  else if (dist_3 < edl){
//    s_out_1 = 70;
//  }
//  else{
//    s_out_1 = 110;
//  }
//  return s_out_1;
//}
