#include "CV7OEMFR.h"   // Inclure le fichier "CV7OEMFR.h"
#ifdef PC
#include <Windows.h>    // Pour la commande "SetConsoleOutputCP(1256)"
#include <iostream>     // Entrée/Sortie (Bibiothéque standard C++)

using namespace std;    

int main()
{
    SetConsoleOutputCP(1256);   // Affichage des caractères spéciaux

    string Trame = "$IIMWV,344.0,R,005.9,M,A*31";     //Trame Dir/Vit = $IIMWV,344.0,R,005.9,M,A*31; Trame Temp = $WIXDR,C,026.0,C,,*56
    CV7OEMFR* trame;
    trame = new CV7OEMFR(Trame);

    if (trame->getTypeTrame() == 1)
    {
        cout << "Direction : " << trame->getDirection() << " °" << endl;
        cout << "Vitesse : " << trame->getVitesse() << " m/s" << endl;
    }
    else if (trame->getTypeTrame() == 2)
    {
        cout << "Temperature : " << trame->getTemperature() << " °C" << endl;
    }
    else
    {
        cout << "Aucune trame trouvée..." << endl;
    }

    return 0;
}
#endif 

#ifdef Lorawan
void setup()
{
    Serial.begin(115200);
    String trame = "$WIXDR,C,026.0,C,,*56";       //$WIXDR,C,026.0,C,,*56 et $IIMWV,348.0,R,005.3,M,A*37
    CV7OEMFR* Trame;
    Trame = new CV7OEMFR(trame);
    StringSplitter* splitter;
    splitter = new StringSplitter(trame, ',', 6);

    Serial.println(Trame->getTypeTrame());

    if (Trame->getTypeTrame() == 1)
    {
        Serial.println("Direction: " + splitter->getItemAtIndex(1) + " °");
        Serial.println("Vitesse: " + splitter->getItemAtIndex(3) + " m/s");
    }
    else if (Trame->getTypeTrame() == 2)
    {
        Serial.println("Température: " + splitter->getItemAtIndex(2) + " °C");
    }
    else
    {
        Serial.println("Aucune trame de type 'IIMWV' ou 'WIXDR' à été trouvée...");
    }

}
void loop()
{

}
#endif