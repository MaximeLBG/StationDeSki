#include <LoRa.h>
#include "boards.h"
#include <ArduinoJson.h>
#include "CV7OEMFR.h"

int counter = 0;
int i = 0;
bool Temp=false, Vit=false;

void setup() {
  
    initBoard();
    // When the power is turned on, a delay is required.
    delay(1500);

    Serial.println("JsonSender");
    LoRa.setPins(RADIO_CS_PIN, RADIO_RST_PIN, RADIO_DI0_PIN);
    if (!LoRa.begin(LoRa_frequency)) {
        Serial.println("Le lora n'a pas démmarer");
        while (1);
    }
}

void affichage(int idCapteur,float dirvent,float vitesse,float temp)
{
    char buf[256]; //buffer pour faire apparaitre le texte
    
        u8g2->clearBuffer(); // effacement de tout l'affichagen
        snprintf(buf, sizeof(buf), "Capteur: %i", idCapteur); //permet de formater les valeurs a l'affichage
        u8g2->drawStr(0, 12, buf);
        snprintf(buf, sizeof(buf), "Vitesse: %.1f", vitesse);
        u8g2->drawStr(0, 26, buf);
        snprintf(buf, sizeof(buf), "Direction: %.f", dirvent);
        u8g2->drawStr(0, 40, buf);
        snprintf(buf, sizeof(buf), "Temperature: %.1f", temp);
        u8g2->drawStr(0, 54, buf);
        u8g2->drawStr(0, 68, "Sender");
        u8g2->sendBuffer(); //permet d'envoyer la compositon a l'écran
}

void sendLoRa(String strJson)
{
        delay(1000);
        LoRa.beginPacket(); //début de l'envoie des packets
        LoRa.print(strJson); //envoie du packet
        Serial.println(strJson); //affichage dans le moniteur série
        LoRa.endPacket(); //fin de l'envoie des packets
        delay(1000);
}

void loop(){

        String output="";
        String test[2]={"$IIMWV,128.0,R,057.9,M,A*37","$WIXDR,C,023.2,C,,*56"};
        float temp;
        float dirvent;
        float vitesse;
        float idCapteur = 1;
     
   
        CV7OEMFR* trame;
        trame = new CV7OEMFR(test[i%2]);

        if(trame->getTypeTrame() == 1)
        {
          dirvent = trame->getDirection();
          vitesse = trame->getVitesse();
          Vit=true;
        }
        if(trame->getTypeTrame() == 2)
        {
          temp= trame->getTemperature();
          Temp=true;
        }
        if(Vit==true && Temp==true)
        {
            Serial.println("test");
        
           StaticJsonDocument<96> doc;

           doc["idCapteur"] = idCapteur;
           doc["vitesse"] = vitesse;
           doc["dirvent"] = dirvent;
           doc["temp"] = temp;

           serializeJson(doc, output);

           sendLoRa(output);
           Vit=false;
           Temp=false;
           delay(10000);
        }
         


        
        affichage(idCapteur,dirvent,vitesse,temp);
        i++;    
        delay(100);
}
