/*- DBS-Lib
- Author : Designed By Sopon
- FB : https://www.facebook.com/SpPCB/
- DBS-Lib is a library board that we created for practice such as C++, algorithms, mathetical, embedded system and robotics.
- This library is constantly evolving and we will do the best. We apologize if there are any mistakes.
*/
bool debug = true ;
uint32_t baud = 115200 ;
#include <DBS_AVRIII.h>
void setup() {
  DBS_begin();
}
void loop() {
  servo1(0);
  servo2(0);
  servo3(0);
  servo4(0);
  servo5(0);
  delay(1000);
  servo1(180);
  servo2(180);
  servo3(180);
  servo4(180);
  servo5(180);
  delay(1000);
}
