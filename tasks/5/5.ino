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
int edr = 23;
int edl = 65;

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
  Serial.begin(9600);
  delay(5000);
}

void loop() {    
  digitalWrite(DIR_1, LOW);
  analogWrite(SPEED_1, 75);
  for (int i = 0;i<50;i++){
    dist_1 = sonar_1.ping_cm();
    dist_2 = sonar_2.ping_cm();
    dist_4 = sonar_4.ping_cm();
    Serial.println(dist_4);
    if (dist_1 > edr){
      s_out_1 = 105;
    }
    if (dist_1 < edr){
      s_out_1 = 110;
    }
    servo_1.write(s_out_1);
    delay(50);
  }
  servo_1.write(125);
  digitalWrite(DIR_1, HIGH);
  analogWrite(SPEED_1, 230);
  delay(3000);
  servo_1.write(90);
  digitalWrite(DIR_1, HIGH);
  analogWrite(SPEED_1, 230);
  delay(3000);
  digitalWrite(DIR_1, LOW);
  analogWrite(SPEED_1, 70);
  delay(2000);
  analogWrite(SPEED_1, 0);
  delay(10000);
}
