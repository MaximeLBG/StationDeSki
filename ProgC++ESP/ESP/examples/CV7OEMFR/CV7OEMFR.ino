#include "CV7OEMFR.h"

#ifdef PC
    #include <Windows.h>    // Pour la commande "SetConsoleOutputCP(1256)"
    #include <iostream>
    using namespace std;
#endif

    int main()
    {
#ifdef PC
        SetConsoleOutputCP(1256);   // Affichage des caractères spéciaux

        string Direction = "$IIMWV,344.0,R,005.9,M,A*31<CR><LF>";
        string Vitesse = "$IIMWV,344.0,R,005.9,M,A*31<CR><LF>";
        string Temperature = "WIXDR,C,026.0,C,,*56<CR><LF>";
#endif

#ifdef ESP
        String Direction = "$IIMWV,344.0,R,005.9,M,A*31<CR><LF>";
        String Vitesse = "$IIMWV,344.0,R,005.9,M,A*31<CR><LF>";
        String Temperature = "WIXDR,C,026.0,C,,*56<CR><LF>";
#endif

        CV7OEMFR* trame;

        trame = new CV7OEMFR(Vitesse, Temperature, Direction);
#ifdef PC
        cout << "Trame Direction : " << trame->getDirection() << " °" << endl;
        cout << "\nTrame Vitesse : " << trame->getVitesse() << " m/s" << endl;
        cout << "\nTrame Temperature : " << trame->getTemperature() << " °C" << endl;
#endif
#ifdef ESP
        Serial.begin(9600);
        Serial.println(trame->getDirection());
        delay(2000);
        Serial.println(trame->getVitesse());
        delay(2000);
        Serial.println(trame->getTemperature());
        delay(2000);
#endif 

        return 0;
    }