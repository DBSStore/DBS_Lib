/*- DBS-Lib
- Author : Designed By Sopon
- FB : https://www.facebook.com/SpPCB/
- DBS-Lib is a library board that we created for practice such as C++, algorithms, mathetical, embedded system and robotics.
- This library is constantly evolving and we will do the best. We apologize if there are any mistakes.
*/
#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;
#define PWMA  5  
#define AIN1  2
#define AIN2  3
#define PWMB  6  
#define BIN1  4
#define BIN2  7
uint8_t Unit_sensor = 8;
uint16_t sensor_pin[8];
uint16_t Black_sensor_values[] = {369, 158, 190, 190, 263, 205, 280, 110};
uint16_t White_sensor_values[] = {995, 905, 944, 896, 984, 985, 985, 700};
uint32_t Last_Position;
float kp, ki, kd, p, i, d, fl, m1, m2 ;
int error, last, sumerror, power;
int position(){
  readADC();
  bool In_line = true;
  long Average = 0, sum = 0;
  for (uint8_t i = 0; i < Unit_sensor ; i++){
    long value = map(long(sensor_pin[i]), Black_sensor_values[i], White_sensor_values[i], 1000, 0);
    if (value > 200){
      In_line = true;
    }
    if (value > 50){
      Average += (long)value * (i * 1000);
      sum += value;
    }
  }
  if (!In_line){
    if (Last_Position < (Unit_sensor - 1) * 1000 / 2){
      return 0;
    }
    else{
      return (Unit_sensor - 1) * 1000;
    }
  }
  Last_Position = Average / sum;
  return Last_Position;
}
void setup(){
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}
void loop(){ 
  if (fl > 0){
    m2 = (power );
    m1 = (power - fl);
    if (fl > 40)
    {
      m2 = 100;
    }
  }
  else if (fl < 0){
    m2 = (power + fl);
    m1 = (power );
    if (fl < -40){
      m1 = 100;
    }
  }
  motorA(m1);  motorB(m2);
  ///////////////////////////////
  power = 60;
  ///////////////////////////////
  if (fl > -15 && fl < 15){
    kp = 0.7;
    ki = 0.0004;
    kd = 3.2;
  }
  else{
    kp = 0.9;
    ki = 0.0001;
    kd = 16;
  }
  error = position() - 3500;
  error = error / 35;
  p = error * kp;
  sumerror = error + sumerror;
  i = sumerror * ki;
  d = (error - last) * kd;
  if (error > -15 && error < 15)i = 0;
  fl = p + i + d;
  last = error;
  if (fl > power) fl = power;
  else if (fl < -power)fl = -power;
}
void readADC(){
  adc.begin(13, 11, 12, 10);
  sensor_pin[0] = adc.readADC(0);
  sensor_pin[1] = adc.readADC(1);
  sensor_pin[2] = adc.readADC(2);
  sensor_pin[3] = adc.readADC(3);
  sensor_pin[4] = adc.readADC(4);
  sensor_pin[5] = adc.readADC(5);
  sensor_pin[6] = adc.readADC(6);
  sensor_pin[7] = adc.readADC(7);
}
void motorA(int speed){
  speed = speed * 2.55;
  if (speed >= 255){
    speed = 255;
  }
  else if (speed <= -255){
    speed = -255;
  }
  boolean inPin1;
  boolean inPin2;
  if (speed >= 0){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  else if (speed < 0){
    inPin1 = LOW;
    inPin2 = HIGH;
    speed = speed * -1;
  }
  digitalWrite(AIN1, inPin1);
  digitalWrite(AIN2, inPin2);
  analogWrite(PWMA, speed);
}
void motorB(int speed){
  speed = speed * 2.55;
  if (speed >= 255){
    speed = 255;
  }
  else if (speed <= -255){
    speed = -255;
  }
  boolean inPin1;
  boolean inPin2;
  if (speed >= 0){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  else if (speed < 0){
    inPin1 = LOW;
    inPin2 = HIGH;
    speed = speed * -1;
  }
  digitalWrite(BIN1, inPin1);
  digitalWrite(BIN2, inPin2);
  analogWrite(PWMB, speed);
}
