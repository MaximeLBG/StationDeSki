#include <EEPROM.h>

#define EEPROM_SIZE 1
void setup() 
{
 Serial.begin(115200);
 EEPROM.begin(EEPROM_SIZE);
 Serial.println(EEPROM.read(0));
}

void loop() {
  // put your main code here, to run repeatedly:

}
