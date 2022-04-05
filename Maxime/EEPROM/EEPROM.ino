#include <EEPROM.h>

#define EEPROM_SIZE 3

void setup() 
{
 Serial.begin(115200);
 EEPROM.begin(EEPROM_SIZE);

 String strIdModule;
 strIdModule = EEPROM.read(0);
 char yesno;
 int result;
 
 Serial.println("L'ancien module est : " + strIdModule);
 Serial.println("Voulez-vous saisir un nouveau module ? (y/n)");
 
 
 while (Serial.available()==0)
 {
   Serial.setTimeout(5000);
   yesno = Serial.read();
   
 }
 
 if(yesno != 'n')
 {
  Serial.println("Saisir le nouveau module : ");
  strIdModule = Serial.readStringUntil('\n');
  
  Serial.println("test2");
  result = strIdModule.toInt();  //converti un string en char
  
  EEPROM.write(0, result);  //deuxième valeur ne doit pas être un string 
  EEPROM.commit();
  Serial.println(result);
 }
 else if(yesno == 'n')
 {
   Serial.println("Vous êtes sur le module : " + strIdModule);
 }
  
}
void loop()
{
}
