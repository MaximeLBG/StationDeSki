#include "CV7OEMFR.h"
#include <EEPROM.h>
#define RXD 16
#define TXD 17
#define EEPROM_SIZE 10

int i = 0;        //Déclaration des variables
bool Temp = false, Vit = false;
String static strIdModule;

void setup()
{ 
  Serial.begin(115200);
  Serial2.begin(4800,SERIAL_8N1,RXD,TXD);
  EEPROM.begin(EEPROM_SIZE);

 String yesno;
 strIdModule = EEPROM.read(0);
 int result;
 
 Serial.println("L'ancien module est : " + strIdModule);
 Serial.println("Voulez-vous saisir un nouveau module ? (y/n)");
 
 Serial.setTimeout(10000);
 yesno = Serial.readStringUntil('\n');
 
 if(yesno == "n" || yesno == 0)
 {
    Serial.println("Vous êtes sur le module : " + strIdModule);
 }
 else
 {
  Serial.println("Saisir le nouveau module : ");
  strIdModule = Serial.readStringUntil('\n');
  
  result = strIdModule.toInt();  //converti un string en char
  
  EEPROM.write(0, result);  //deuxième valeur ne doit pas être un string 
  EEPROM.commit();
  Serial.print("Le nouveau module est : "); Serial.println(result);
 }
 delay(5000);
        
}
void loop()
{
      String value=Serial2.readStringUntil('\n');
      Serial.println(value);
      float temp;
      float dirvent;
      float vitesse;
     
      //float idCapteur = 1;

      CV7OEMFR* trame;  //Déclaration d'un pointeur dans la classe CV7OEMFR
      trame = new CV7OEMFR(value);    //Une fois sur deux la trame va prendre soit la valeur du paramètre 1 soit du paramètre 2

      if (trame->getTypeTrame() == 1)        //On appelle la fonction getTypeTrame() pour savoir si la trame est de format "$IIMWV" ou "$WIXDR"
      {
          dirvent = trame->getDirection();      // On sauvegarde les valeurs de getDirection() et getVitesse() dans les variables attendues
          vitesse = trame->getVitesse();
          Vit = true;       //dirVit passe à true quand la trame est de format "$IIMWV"
      }
      if (trame->getTypeTrame() == 2)       //On appelle la fonction getTypeTrame() pour savoir si la trame est de format "$IIMWV" ou "$WIXDR"
      {
          temp = trame->getTemperature();       //On sauvegarde les valeurs de getTemperature() dans la variables attendue
          Temp = true;      //temp passe à true quand la trame est de format "$IWXDR"
      }
        if (Vit == true && Temp == true)      // Quand les deux sont true, sauvegarde les résultats
      {
          Serial.print("La direction est de : ");
          Serial.println(dirvent);
          Serial.print("La vitesse est de : ");
          Serial.println(vitesse);
          Serial.print("la température est de : ");
          Serial.println(temp);
          Vit = false; Temp = false;        // temp et dirVit passe à false et recommance dans la boucle
      }
}
