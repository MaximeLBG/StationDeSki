#include <EEPROM.h>

#define EEPROM_SIZE 1
void setup() 
{
  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);
  
  EEPROM.write(0,15);
  EEPROM.commit();
}

void loop() {
 

}
