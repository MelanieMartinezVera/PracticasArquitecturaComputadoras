/*Melanie Arianna Martinez Vera
y Oscar Luna Perez
Practica 1 con Arduino
Sensor ultrasónico que muestra la distancia en centimetros y metros en el monitor serial*/

//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>

const int Trig = 2;
const int Echo = 4;

//LiquidCrystal_I2C lcd (0x3F, 16, 2);

//Define sound speed in cm/us
#define SOUND_SPEED 0.034
#define CM_TO_MT 0.01

//Definir variables
long duracion;
float distanciaCm;
float distanciaMetros;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  //lcd.init();
  //lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  //lcd.setCursor(0, 1);
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  duration = pulseIn(Echo, HIGH);

  distanciaCm = duracion * SOUND_SPEED/2;

  distanciaMetros = (distanciaCm * 1)/100;

  Serial.print("Distancia en (cm): ");
  Serial.println(distanciaCm);

  Serial.print("Distancia en (mt): ");
  Serial.println(distanciaMetros);

  delay(1000);

}
