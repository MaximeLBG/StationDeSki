#include <TTN_esp32.h>
#include <EEPROM.h>

#include "TTN_CayenneLPP.h"
#include "CV7OEMFR.h"

#define RXD 16
#define TXD 17
#define EEPROM_SIZE 10
/*****************************************************teams*********************
 *  Go to your TTN console register a device then the copy fields
 *  and replace the CHANGE_ME strings below
 ****************************************************************************/
const char* devEui = "70B3D57ED004DF35"; // Change to TTN Device EUI
const char* appEui = "0000000000000000"; // Change to TTN Application EUI
const char* appKey = "94C03928078D7455DD4B7618AFC6C816"; // Chaneg to TTN Application Key

int i = 0;
String static strIdModule;
bool one = false, two = false;

TTN_esp32 ttn ;
TTN_CayenneLPP lpp;

void message(const uint8_t* payload, size_t size, int rssi)
{
    Serial.println("-- MESSAGE");
    Serial.print("Received " + String(size) + " bytes RSSI=" + String(rssi) + "db");
    for (int i = 0; i < size; i++)
    {
        Serial.print(" " + String(payload[i]));
        // Serial.write(payload[i]);
    }

    Serial.println();
}

void setup()
{
    Serial.begin(115200);
    Serial2.begin(4800,SERIAL_8N1,RXD,TXD);
    EEPROM.begin(EEPROM_SIZE);
    
    Serial.println("Starting");
    ttn.begin();
    ttn.onMessage(message); // Declare callback function for handling downlink
                            // messages from server
    ttn.join(devEui, appEui, appKey);
    Serial.print("Joining TTN ");
    while (!ttn.isJoined())
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("\njoined !");
    ttn.showStatus();

    String static yesno;
    strIdModule = EEPROM.read(0);

    Serial.println("L'ancien module est : " + strIdModule);
    Serial.println("Voulez-vous saisir un nouveau module ? (y/n)");
     
    Serial.setTimeout(10000);
    yesno = Serial.readStringUntil('\n');
     
    if(yesno == "n" || yesno == 0)
    { 
     Serial.println("Veuillez attendre 5 secondes ");
    }
    else
    {
     Serial.println("Saisir le nouveau module : ");
     strIdModule = Serial.readStringUntil('\n');
     Serial.println("Vous ??tes sur le module : " + strIdModule);
     Serial.println("Veuillez attendre 5 secondes ");
     
     EEPROM.write(0, strIdModule.toInt());  //deuxi??me valeur ne doit pas ??tre un string 
     EEPROM.commit();
    }
   delay(5000);   
}

void loop()
{
    String value=Serial2.readStringUntil('\n');
    //Serial.print(value);
    float temp, dir, speeds;

    CV7OEMFR* frame;  //D??claration d'un pointeur dans la classe CV7OEMFR
    frame = new CV7OEMFR(value);    //Une fois sur deux la trame va prendre soit la valeur du param??tre 1 soit du param??tre 2

      if (frame->getFrameType() == 1)        //On appelle la fonction getTypeTrame() pour savoir si la trame est de format "$IIMWV" ou "$WIXDR"
      {
          dir = frame->getDirection();      // On sauvegarde les valeurs de getDirection() et getVitesse() dans les variables attendues
          speeds = frame->getSpeed();
          two = true;       //dirVit passe ?? true quand la trame est de format "$IIMWV"
      }
      if (frame->getFrameType() == 2)       //On appelle la fonction getTypeTrame() pour savoir si la trame est de format "$IIMWV" ou "$WIXDR"
      {  
          temp = frame->getTemperature();       //On sauvegarde les valeurs de getTemperature() dans la variables attendue
          one = true;      //temp passe ?? true quand la trame est de format "$IWXDR
      }
        if (two == true && one == true)      // Quand les deux sont true, sauvegarde les r??sultats
      {
          lpp.reset();
          lpp.addTemperature(1, temp);
          lpp.addAnalogInput(2, dir);
          lpp.addAnalogInput(3, speeds);
          lpp.addDigitalInput(4, strIdModule.toInt());
          
          
          two = false; one = false;        // temp et dirVit passe ?? false et recommance dans la boucle
      }
    
    if (ttn.sendBytes(lpp.getBuffer(), lpp.getSize()))
    {
        Serial.printf("\nTemp: %f TTN_CayenneLPP: %d %x %02X%02X\n", temp, lpp.getBuffer()[0], lpp.getBuffer()[1],
            lpp.getBuffer()[2], lpp.getBuffer()[3]);

        Serial.printf("Direction: %f TTN_CayenneLPP: %d %x %02X%02X\n", dir, lpp.getBuffer()[0], lpp.getBuffer()[1],
            lpp.getBuffer()[2], lpp.getBuffer()[3]);

        Serial.printf("Speed: %f TTN_CayenneLPP: %d %x %02X%02X\n", speeds, lpp.getBuffer()[0], lpp.getBuffer()[1],
            lpp.getBuffer()[2], lpp.getBuffer()[3]);

        Serial.printf("Capteur: %i TTN_CayenneLPP: %d %x %02X%02X\n", strIdModule.toInt(), lpp.getBuffer()[0], lpp.getBuffer()[1],
            lpp.getBuffer()[2], lpp.getBuffer()[3]);
    }
}
