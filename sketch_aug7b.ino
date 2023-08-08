/*Practica elaborada con arduino uno que controla un servomotor con un potenciometro*/
#include<Servo.h>
Servo myServo;
int const PotPin=A5;
int PotVal;
int angle;
void setup(){
myServo.attach(9);
Serial.begin(9600);
}
void loop(){
PotVal=analogRead(PotPin);
Serial.print("Valor del potenciometro:");
Serial.println(PotVal);
angle=map(PotVal,0,1023,0,179);
Serial.print("angulo = ");
Serial.println (angle);
myServo.write(angle);
delay (100);
}
