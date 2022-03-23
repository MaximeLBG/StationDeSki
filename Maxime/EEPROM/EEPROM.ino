#include <Preferences.h>
Preferences preferences;

char id;

void setup() 
{
 Serial.begin(115200);
 Serial.println("Saisir un Id");
 char id;
 int boardId = 1;
  while(Serial.available()>0)
  {
   id = Serial.read();
    Serial.println(id);
  }
   preferences.putUInt("boardId", boardId);
   preferences.putChar("id", id);
}
void setup() 
{
   preferences.begin("myfile", false);
   
   unsigned int readBoardId = preferences.getUInt("boardId", 0); // get boardId or if key doesn't exist set variable to 0
   Serial.print("Read Id = ");
   Serial.println(readBoardId);
   
   float readId = preferences.getChar("id", 0); //
   Serial.print("Read id = ");
   Serial.println(readId);

void loop()
{
}
