#include <LoRa.h>

int valeur = 0;
byte SerialOk=0;

void setup()
{
Serial.begin(115200);
Serial.print("Veuillez saisir une valeur");
  while(SerialOk==0) 
  {  
    if (Serial.available() > 0) 
    {
      valeur = Serial.read();
      
      if(incomingByte=='A') 
      {
        Serial.println("Bonne combinaison !");
        SerialOk=1;
      }
     }
   }
}

void loop()
{   
   if(millis()>=10000)
   {
      
   }
}
