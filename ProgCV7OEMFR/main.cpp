#include "CV7OEMFR.h"   // Inclure le fichier "CV7OEMFR.h"
#ifdef PC
    #include <Windows.h>    // Pour la commande "SetConsoleOutputCP(1256)"
    #include <iostream>     // Entrée/Sortie (Bibiothéque standard C++)
    using namespace std; 
#endif
#ifdef Lorawan
    #include <LoRa.h>       //Bibliothèque pour la connexion Lora
    #include "boards.h"     //Bibliothèque pour la gestion de l'écran de l'ESP32 Lorawan
    #include <ArduinoJson.h>    //Bibliotthèque permettant de créer de Jason
#endif

    

#ifdef PC
  int main()
  {
      SetConsoleOutputCP(1256);   // Affichage des caractères spéciaux

      float direction, vitesse, temperature;    //Déclaration des variables 
      bool dirVit = false, temp = false;
      int i = 0;

      do
      {
          string Trame[2] = { "$IIMWV,344.0,R,005.9,M,A*31" , "$WIXDR,C,026.0,C,,*56"};  //Deux trames rentrée en paramètre pour recevoir la direction, vitesse et la temperature
          CV7OEMFR* trame;     //Déclaration d'un pointeur dans la classe CV7OEMFR
          trame = new CV7OEMFR(Trame[i%2]);     //Une fois sur deux la trame va prendre soit la valeur du paramètre 1 soit du paramètre 2

          if (trame->getTypeTrame() == 1)       //On appelle la fonction getTypeTrame() pour savoir si la trame est de format "$IIMWV" ou "$WIXDR"
          {
              direction = trame->getDirection();    // On sauvegarde les valeurs de getDirection() et getVitesse() dans les variables attendues
              vitesse = trame->getVitesse();
              dirVit = true;        //dirVit passe à true quand la trame est de format "$IIMWV"
          }
          if (trame->getTypeTrame() == 2)       //On appelle la fonction getTypeTrame() pour savoir si la trame est de format "$IIMWV" ou "$WIXDR"
          {
              temperature = trame->getTemperature();
              temp = true;      //temp passe à true quand la trame est de format "$IWXDR"
          }
          if (dirVit == true && temp == true)       // Quand les deux sont true, on affiche le resultat
          {
              cout << "Direction : " << direction << endl;
              cout << "Vitesse : " << vitesse << endl;
              cout << "Temperature : " << temperature << endl;

              temp = false; dirVit = false;     // temp et dirVit passe à false et recommance dans la boucle

              Sleep(10000);     //On attent 10 secondes pour permettre d'avoir un meilleur flux des données
          }
          i++; // i s'incrémente de 1, cela sert à changer de trame

      } while(1);  //Boucle permettant de sauvegarder et d'afficher les valeurs en même temps 
  
      return 0;     // Renvoi 0, fin du programme
  }
#endif 
#ifdef Lorawan

  int i = 0;        //Déclaration des variables
  bool Temp = false, Vit = false;

  void setup()
  {
      initBoard();  //Initialisation de la carte
      delay(1500);  //On attend 1,5 seconde

      Serial.println("JsonSender");     //On affiche sur le Moniteur Série
      LoRa.setPins(RADIO_CS_PIN, RADIO_RST_PIN, RADIO_DI0_PIN);     //Activation de l'antènne

      if (!LoRa.begin(LoRa_frequency))  // Si le lancement c'est mal effectué
      {
          Serial.println("Le lora n'a pas démmarer");   // On affiche sur le Moniteur Série
          while (1);
      }
  }

  void affichage(int idCapteur, float dirvent, float vitesse, float temp)   //Fonction d'affichage
  {
      char buf[256]; //buffer pour faire apparaitre le texte

      u8g2->clearBuffer(); // effaçage de tout l'affichage
      snprintf(buf, sizeof(buf), "Capteur: %i", idCapteur); //permet de formater les valeurs à l'affichage
      u8g2->drawStr(0, 12, buf);
      snprintf(buf, sizeof(buf), "Vitesse: %.1f", vitesse);
      u8g2->drawStr(0, 26, buf);
      snprintf(buf, sizeof(buf), "Direction: %.f", dirvent);
      u8g2->drawStr(0, 40, buf);
      snprintf(buf, sizeof(buf), "Temperature: %.1f", temp);
      u8g2->drawStr(0, 54, buf);
      u8g2->drawStr(0, 68, "Sender");
      u8g2->sendBuffer(); //permet d'envoyer la compositon à l'écran
  }

  void sendLoRa(String strJson) //Fonction permettant l'envoi des paquets
  {
      delay(1000);  //Attendre 1 seconde
      LoRa.beginPacket(); //début de l'envoie des packets
      LoRa.print(strJson); //envoie du packet
      Serial.println(strJson); //affichage dans le moniteur série
      LoRa.endPacket(); //fin de l'envoie des packets
      delay(1000);  //Attendre 1 seconde
  }

  void loop() {

      String output = "";   //Déclaration des variables
      String test[2] = { "$IIMWV,128.0,R,057.9,M,A*37","$WIXDR,C,023.2,C,,*56" };   //Deux trames rentrée en paramètre pour recevoir la direction, vitesse et la temperature
      float temp;
      float dirvent;
      float vitesse;
      float idCapteur = 1;

      CV7OEMFR* trame;  //Déclaration d'un pointeur dans la classe CV7OEMFR
      trame = new CV7OEMFR(test[i % 2]);    //Une fois sur deux la trame va prendre soit la valeur du paramètre 1 soit du paramètre 2

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
          StaticJsonDocument<96> doc;   //Déclaration de varible pour créer le Jason

          doc["idCapteur"] = idCapteur;
          doc["vitesse"] = vitesse;
          doc["dirvent"] = dirvent;
          doc["temp"] = temp;

          serializeJson(doc, output);   // prendre les valeurs pour les concaténer en Jason

          sendLoRa(output);     //Fonction permettant d'envoyer les valeurs
          Vit = false; Temp = false;        // temp et dirVit passe à false et recommance dans la boucle
          delay(10000);     // On attend 10 secondes
        }

      affichage(idCapteur, dirvent, vitesse, temp);     //On passe apr une fonction affichage pour afficher les resultats
      i++;  // i s'incrémente de 1, cela sert à changer de trame
      delay(100);   // On attend 100 millisecondes
}
#endif
