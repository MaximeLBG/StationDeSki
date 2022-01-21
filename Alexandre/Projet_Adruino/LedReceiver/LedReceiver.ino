
#include <LoRa.h>
#include "boards.h"

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
  
          if(recv == "0") //éteind la led si la valeur recue est de 0
          {
            digitalWrite(ledPin, LOW);
            Serial.print(" (off)");
          }
          if(recv == "1") //éteind la led si la valeur recue est de 1
          {
            digitalWrite(ledPin, HIGH);
            Serial.print(" (on)");
          }    
        }

        Serial.print(" avec RSSI ");
        Serial.println(LoRa.packetRssi());
        
            u8g2->clearBuffer();
            char buf[256];
            u8g2->drawStr(0, 12, "Reception OK!");
            u8g2->drawStr(0, 26, recv.c_str()); //affichage donées reçue
            snprintf(buf, sizeof(buf), "Msg reçue:",recv.c_str());
            snprintf(buf, sizeof(buf), "RSSI:%i", LoRa.packetRssi());
            u8g2->drawStr(0, 40, buf);
            snprintf(buf, sizeof(buf), "SNR:%.1f", LoRa.packetSnr());
            u8g2->drawStr(0, 56, buf);
            u8g2->sendBuffer();
    }
}
