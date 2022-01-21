#include <LoRa.h>
#include "boards.h"

int counter = 0;

void setup()
{
    initBoard();
    // When the power is turned on, a delay is required.
    delay(1500);

    Serial.println("LedSender");
    LoRa.setPins(RADIO_CS_PIN, RADIO_RST_PIN, RADIO_DI0_PIN);
    if (!LoRa.begin(LoRa_frequency)) {
        Serial.println("Le lora n'a pas démmarer");
        while (1);
    }
}

void loop()
{
    int i; //var de la boucle for
    char buf[256]; //buffer pour faire apparaitre le texte

    while(1)
    {
      for(i=0;i<=1;i++)//boucle pour faire clignoter la led
      {
        LoRa.beginPacket(); //début de l'envoie des packets
        LoRa.print(i); //envoie du packet
        Serial.println(i); //affichage dans le moniteur série
        LoRa.endPacket(); //fin de l'envoie des packets
        delay(1000);
        counter++;
        Serial.println(counter);//affichage dans le moniteur série du nombre d'itération

        u8g2->clearBuffer(); // effacement de tout l'affichage
        u8g2->drawStr(0, 12, "Transmission: OK!"); // affichage d'une string a l'écran
        snprintf(buf, sizeof(buf), "Envoie numero: %d", counter); //permet de formater les valeurs a l'affichage
        u8g2->drawStr(0, 26, buf);
        snprintf(buf, sizeof(buf), "Message: %d", i);
        u8g2->drawStr(0, 40, buf);
        u8g2->sendBuffer(); //permet d'envoyer la compositon a l'écran
      }
    }

}
