#include <Servo.h>

#define Trigger 13
#define Echo 12

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
  myservo.attach(5);

}

void loop() {
  // put your main code here, to run repeatedly:
  long t;
  long d;

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  t=pulseIn(Echo, HIGH);
  d=t/59;

  if(d<10){
    for(int pos=0;pos<180;pos++){
      myservo.write(pos);
      delay(10);
    }
    for(int pos=180;pos<0;pos++){
      myservo.write(pos);
      delay(10);
    }
  }
  delay(1000);

}
