#include <LoRa.h>
#include "boards.h"
#include <ArduinoJson.h>

char* input;
size_t inputLength;

void setup()
{
    initBoard();
    // When the power is turned on, a delay is required.
    delay(1500);

    Serial.println("LedReceiver");

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
        
        String recv = "";
        // read packet
        while (LoRa.available()) {
          recv += (char)LoRa.read(); //permet de réceptionner les données reçues
        }
        
          StaticJsonDocument<192> doc;
          DeserializationError error = deserializeJson(doc, recv);
          
          if (error) {
            Serial.print("deserializeJson() failed: ");
            Serial.println(error.c_str());
            return;
          }
          
          JsonObject Capteur = doc["Capteur"];
          const char* Capteur_numero = Capteur["numero"]; // "1"
          const char* Capteur_vitesseVent = Capteur["vitesseVent"]; // "10"
          const char* Capteur_directionVent = Capteur["directionVent"]; // "R"
          const char* Capteur_temperature = Capteur["temperature"]; // "20"

          Serial.print("Capteur numéro : ");
          Serial.println(Capteur_numero);

          Serial.print("Vitesse du vent : ");
          Serial.println(Capteur_vitesseVent);

          Serial.print("Direction du vent : ");
          Serial.println(Capteur_directionVent);
          
          Serial.print("Temperature : ");
          Serial.println(Capteur_temperature);   

          Serial.print("complet : ");
          Serial.println(Capteur);
        
        char buf[256]; //buffer pour faire apparaitre le texte
        
        u8g2->clearBuffer(); // effacement de tout l'affichage
        u8g2->drawStr(0, 12, "Transmission: OK!"); // affichage d'une string a l'écran
        snprintf(buf, sizeof(buf), "Capteur: %s", Capteur_numero); //permet de formater les valeurs a l'affichage
        u8g2->drawStr(0, 26, buf);
        snprintf(buf, sizeof(buf), "Vitesse: %s", Capteur_vitesseVent);
        u8g2->drawStr(0, 40, buf);
        snprintf(buf, sizeof(buf), "Direction: %s", Capteur_directionVent);
        u8g2->drawStr(0, 54, buf);
        snprintf(buf, sizeof(buf), "Temperature: %s", Capteur_temperature);
        u8g2->sendBuffer(); //permet d'envoyer la compositon a l'écran

        }
}
