#include <Servo.h>
#include <Adafruit_MCP3008.h>

int ch[8] ;
int knob = 0 ;
int buttom = 0 ;
int SpeedL = 0 ;
int SpeedR = 0 ;

Adafruit_MCP3008 adc;

Servo sv1; 
Servo sv2; 
Servo sv3; 
Servo sv4; 
Servo sv5; 

void DBS_begin() {

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);

  pinMode(A6, INPUT);
  pinMode(A7, INPUT);

  adc.begin(9, 11, 10, 12);

  sv1.attach(13);
  sv2.attach(A0);
  sv3.attach(A1);
  sv4.attach(A2);
  sv5.attach(A3);

  if (debug) {
    Serial.begin(baud);
  }

}

void Read() {

  for (int CH = 0 ; CH < 8 ; CH++) {
    ch[CH] = adc.readADC(CH);
  }

  buttom = analogRead(A6);
  knob = analogRead(A7);

  if (buttom == 1023) {
    buttom = 1 ;
  }
  else {
    buttom = 0 ;
  }

}

void motor(int L , int R) {

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);

  if (L > 0) {
     SpeedL = map(L, 0, 100, 0, 255);
  }
  else {
     SpeedL = map(L, -0, -100, 0, 255);
  }

  if (R > 0) {
     SpeedR = map(R, 0, 100, 0, 255);
  }
  else {
     SpeedR = map(R, -0, -100, 0, 255);
  }

  analogWrite(3, SpeedL);
  analogWrite(5, SpeedR);

  if (L > 0) {
    digitalWrite(4, 0);
    digitalWrite(2, 1);
  }
  else {
    digitalWrite(4, 1);
    digitalWrite(2, 0);
  }

  if (R > 0) {
    digitalWrite(6, 0);
    digitalWrite(7, 1);
  }
  else {
    digitalWrite(6, 1);
    digitalWrite(7, 0);
  }

}

void motor_stop(){
  analogWrite(3, 255);
  analogWrite(5, 255);
  digitalWrite(4, 1);
  digitalWrite(2, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
}

void servo1(int value){
 sv1.attach(13);
 sv1.write(value);
}

void servo2(int value){
 sv2.attach(A0);
 sv2.write(value);
}

void servo3(int value){
 sv3.attach(A1);
 sv3.write(value);
}

void servo4(int value){
 sv4.attach(A2);
 sv4.write(value);
}

void servo5(int value){
 sv5.attach(A3);
 sv5.write(value);
}