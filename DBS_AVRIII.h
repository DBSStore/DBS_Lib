#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;
bool Debug = true ;
void DBS_begin() {
  Serial.begin(115200);
  adc.begin(9, 11, 10, 12);
}
void Sensor(byte CH){
  for (int chan = 0 ; chan < CH ; chan++) {
    Serial.print(adc.readADC(chan));
    Serial.print("\t");
  }
  Serial.println("");
}
