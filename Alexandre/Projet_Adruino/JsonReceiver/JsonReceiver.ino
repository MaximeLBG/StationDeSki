#include <LoRa.h>
#include "boards.h"
#include <ArduinoJson.h>

size_t inputLength;

void setup(){
  
    initBoard();
    // When the power is turned on, a delay is required.
    delay(1500);

    Serial.println("JsonReceiver");

    LoRa.setPins(RADIO_CS_PIN, RADIO_RST_PIN, RADIO_DI0_PIN);
    if (!LoRa.begin(LoRa_frequency)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
}

void loop()
{
    // try to parse packet
    int packetSize = LoRa.parsePacket();
     
    if (packetSize) {
        
        String recv ;
        // read packet
        while (LoRa.available()) {
          recv += (char)LoRa.read(); //permet de réceptionner les données reçues
        }
          Serial.println(recv);

        StaticJsonDocument<192> doc;
        
        DeserializationError error = deserializeJson(doc, recv);

        if (error) {
          Serial.print("deserializeJson() failed: ");
          Serial.println(error.c_str());
          return;
        }
        
        int capteur = doc["capteur"]; // "1"
        float vitesseVent = doc["vitesseVent"]; // "10"
        float directionVent = doc["directionVent"]; // "N"
        float temperature = doc["temperature"]; // "20"  
        
        char buf[256]; //buffer pour faire apparaitre le texte

        u8g2->clearBuffer(); // effacement de tout l'affichage
        snprintf(buf, sizeof(buf), "Capteur: %i", capteur); //permet de formater les valeurs a l'affichage
        u8g2->drawStr(0, 12, buf);
        snprintf(buf, sizeof(buf), "Vitesse: %.1f", vitesseVent);
        u8g2->drawStr(0, 26, buf);
        snprintf(buf, sizeof(buf), "Direction: %.f", directionVent);
        u8g2->drawStr(0, 40, buf);
        snprintf(buf, sizeof(buf), "Temperature: %.1f", temperature);
        u8g2->drawStr(0, 54, buf);
        u8g2->drawStr(0, 68, "Reciver");
        u8g2->sendBuffer(); //permet d'envoyer la compositon a l'écran

        }
        
}
