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
            cout << "\nVitesse : " << trame->getVitesse() << " m/s" << endl;
        }
        else if (trame->getTypeTrame() == 2)
        {
            cout << "\nTemperature : " << trame->getTemperature() << " °C" << endl;
        }
        else
        {
            cout << "\nAucune trame trouvée..." << endl;
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
        splitter = new StringSplitter(trame, ',', 6);
        Serial.println("La direction est de : " + splitter->getItemAtIndex(1) + "°");
        Serial.end();
    }
#endif

