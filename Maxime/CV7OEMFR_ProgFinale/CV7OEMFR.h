#define Lorawan    // On décide sur qu'elle système le programme doit fonctionner

#ifdef PC   // On définit une partie du programme qui fonctionnera sous PC
  #include <string>     //On inclut la bibliothèque de string
#endif

using namespace std;

#ifdef Lorawan  // On définit une partie du programme qui fonctionnera sous Lorawan
  #include <Arduino.h>      //On inclut la bibliothèque d'Arduino
  #include "StringSplitter.h"   //On inclut la bibliothèque StringSplitter
#endif
  

class CV7OEMFR                  // Classe de l'anémomètre Ultrasonore
{
private:

    float Vitesse, Temperature, Direction;    // Variables ou ira le resultat demandé
    int typeTrame;                // Variables du type de la trame ("0","1" ou "2")

  #ifdef PC
    string trame;               // Trame récupérée sous PC
    void splitString(string trame, string delim = ",");   // Fonction permettant de séparrer la trame à chaque "," rencontrée sous PC
  #endif

  #ifdef Lorawan
    String trame;               // Trame récupérée sous Lorawan
  #endif

public:

  #ifdef PC
    CV7OEMFR(string trame = "");        // Constructeur de la classe recevant la trame sous PC
  #endif

  #ifdef Lorawan
    CV7OEMFR(String trame = "");        // Constructeur de la classe recevant la trame sous Lorawan
  #endif
    int getTypeTrame();             // Fonction qui renvoie "0","1" ou "2" en fonction de la trame
    
    float getVitesse();             // Fonction qui renvoie la Vitesse (réel)
    float getTemperature();         // Fonction qui renvoie la Temperature (réel)
    float getDirection();           // Fonction qui renvoie la Direction (réel)

};
