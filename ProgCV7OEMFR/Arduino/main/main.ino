#include "CV7OEMFR.h"
#ifdef PC
    #include <Windows.h>    // Pour la commande "SetConsoleOutputCP(1256)"
    #include <iostream>
#endif

using namespace std;

#ifdef PC
int main()
{
    SetConsoleOutputCP(1256);   // Affichage des caractères spéciaux
    
    string Trame = "$IIMWV,344.0,R,005.9,M,A*31\n";     //Trame Dir/Vit = $IIMWV,344.0,R,005.9,M,A*31; Trame Temp = $WIXDR,C,026.0,C,,*56

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
    Serial.begin(9600);
    
    String trame = "$IIMWV,344.0,R,005.9,M,A*31";
    StringSplitter* splitter;
    splitter = new StringSplitter(trame, ',', 1);

   // if(splitter->getTypeTrame() == 1)
    //{
       Serial.println("La direction est de : " + splitter->getItemAtIndex(1) + "°");
       Serial.println("La vitesse est de : " + splitter->getItemAtIndex(3) + "m/s");
    //}
    //else if(splitter->getTypeTrame() == 2)
    //{
       Serial.println("La temperature est de : " + splitter->getItemAtIndex(2) + "°C");
    //}
   // else
    //{
      Serial.println("Aucune trame trouvée...");
    //}
    
    Serial.end();
}
#endif
