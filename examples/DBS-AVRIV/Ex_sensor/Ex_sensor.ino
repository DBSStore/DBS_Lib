/*- DBS-Lib
- Author : Designed By Sopon
- FB : https://www.facebook.com/SpPCB/
- DBS-Lib is a library board that we created for practice such as C++, algorithms, mathetical, embedded system and robotics.
- This library is constantly evolving and we will do the best. We apologize if there are any mistakes.
*/
bool debug = true ;
uint32_t baud = 115200 ;
#include <DBS_AVRIV.h>
void setup() {
  DBS_begin();
}
void loop() {
  Read();
  Serial.print(" Ch0 : ");
  Serial.print(ch[0]);
  Serial.print(" Ch1 : ");
  Serial.print(ch[1]);
  Serial.print(" Ch2 : ");
  Serial.print(ch[2]);
  Serial.print(" Ch3 : ");
  Serial.print(ch[3]);
  Serial.print(" Ch4 : ");
  Serial.print(ch[4]);
  Serial.print(" Ch5 : ");
  Serial.print(ch[5]);
  Serial.print(" Ch6 : ");
  Serial.print(ch[6]);
  Serial.print(" Ch7 : ");
  Serial.println(ch[7]);
  delay(100);
}
