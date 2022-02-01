
#include <LoRa.h>
#include "boards.h"
#include <QueueList.h>
const int ledPin = 25;

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
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // try to parse packet
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        // received a packet
        Serial.print("Packet reçue ");

        String recv = "";
        // read packet
        while (LoRa.available()) {
          
          recv = (char)LoRa.read(); //permet de réceptionner les données reçues
          Serial.print(recv); //affiche les données reçues dans le moniteur série
        }
        
        QueueList<String> vent;
      
        //simu température
        vent.push(recv);
      
        //simu de l'enoie des mesures a un serveur web
         while (!vent.isEmpty ())
         Serial.println (vent.pop());
    }
}
