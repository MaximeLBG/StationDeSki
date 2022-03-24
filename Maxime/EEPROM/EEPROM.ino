#include <EEPROM.h>

#define EEPROM_SIZE 12

void setup() 
{
 Serial.begin(115200);
 Serial.println("Saisir un Id");
 EEPROM.begin(EEPROM_SIZE);
 char id=0;
 char readId=0;
 int boardId = 1;
 
 //Serial.println(EEPROM.read(boardId));
 
  while(Serial.available()==0)
  {
    while(Serial.available()!=0)
    {
      Serial.println("test");
      id = Serial.read();
      EEPROM.write(boardId,id);
      readId = EEPROM.read(boardId);
      Serial.println(readId);
    }
  }
  
}
void loop()
{
}
