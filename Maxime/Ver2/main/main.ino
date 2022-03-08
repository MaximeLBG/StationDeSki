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
    
    CV7OEMFR Trame("$IIMWV,348.0,R,005.3,M,A*37");       //$WIXDR,C,026.0,C,,*56 et $IIMWV,348.0,R,005.3,M,A*37
    StringSplitter splitter(Trame);

    Trame.partage(& splitter);
    
    Serial.println(trame->getTypeTrame());
    
    Serial.print("Direction: "); Serial.println(trame.StringSplitter()->getDirection());
     Serial.print("Vitesse: "); Serial.println(trame.StringSplitter()->getVitesse());
      Serial.print("Temperature: "); Serial.println(trame.StringSplitter()->getTemperature());

}
void loop()
{

}
#endif
