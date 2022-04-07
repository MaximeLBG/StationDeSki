#include <EEPROM.h>

#define EEPROM_SIZE 10

void setup() 
{
 Serial.begin(115200);
 EEPROM.begin(EEPROM_SIZE);

 String strIdModule, yesno;
 strIdModule = EEPROM.read(0);
 int result;
 
 Serial.println("L'ancien module est : " + strIdModule);
 Serial.println("Voulez-vous saisir un nouveau module ? (y/n)");
 
 Serial.setTimeout(5000);
 yesno = Serial.readStringUntil('\n');
 
 if(yesno == "n" || yesno == 0)
 {
    Serial.println("Vous êtes sur le module : " + strIdModule);
 }
 else
 {
  Serial.println("Saisir le nouveau module : ");
  strIdModule = Serial.readString();
  
  result = strIdModule.toInt();  //converti un string en char
  
  EEPROM.write(0, result);  //deuxième valeur ne doit pas être un string 
  EEPROM.commit();
  Serial.print("Le nouveau module est : "); Serial.println(result);
 }
}
void loop()
{
}
