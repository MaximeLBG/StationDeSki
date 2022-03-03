#include <LoRa.h>
#include "boards.h"
#include <ArduinoJson.h>


int counter = 0;

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

void loop(){

  String output="";
  int i; //var de la boucle for
  char buf[256]; //buffer pour faire apparaitre le texte
  float temperature = 20.4;
  float directionVent = 142.2;
  float vitesseVent = 10.4;
  float capteur = 1;

        StaticJsonDocument<96> doc;
    
        doc["idCapteur"] = capteur;
        doc["vitesse"] = vitesseVent;
        doc["dirvent"] = directionVent;
        doc["temp"] = temperature;
        
        serializeJson(doc, output);

        delay(1000);
        LoRa.beginPacket(); //début de l'envoie des packets
        LoRa.print(output); //envoie du packet
        Serial.println(output); //affichage dans le moniteur série
        LoRa.endPacket(); //fin de l'envoie des packets
        delay(1000);
        
        u8g2->clearBuffer(); // effacement de tout l'affichagen
        snprintf(buf, sizeof(buf), "Capteur: %.f", capteur); //permet de formater les valeurs a l'affichage
        u8g2->drawStr(0, 12, buf);
        snprintf(buf, sizeof(buf), "Vitesse: %.1f", vitesseVent);
        u8g2->drawStr(0, 26, buf);
        snprintf(buf, sizeof(buf), "Direction: %.f", directionVent);
        u8g2->drawStr(0, 40, buf);
        snprintf(buf, sizeof(buf), "Temperature: %.1f", temperature);
        u8g2->drawStr(0, 54, buf);
        u8g2->drawStr(0, 68, "Sender");
        u8g2->sendBuffer(); //permet d'envoyer la compositon a l'écran
        
}
