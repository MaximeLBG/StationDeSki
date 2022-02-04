#include "CV7OEMFR.h"
#include <Windows.h>    // Pour la commande "SetConsoleOutputCP(1256)"
#include <iostream>

using namespace std;

int main()
{
    SetConsoleOutputCP(1256);   // Affichage des caractères spéciaux
    
    string Direction = "$IIMWV,344.0,R,005.9,M,A*31<CR><LF>";
    string Vitesse = "$IIMWV,344.0,R,005.9,M,A*31<CR><LF>";
    string Temperature = "WIXDR,C,026.0,C,,*56<CR><LF>";

    CV7OEMFR* trame;

    trame = new CV7OEMFR(Vitesse,Temperature,Direction);

    cout << "Trame Direction : " << trame->getDirection() << " °" << endl;

    cout << "\nTrame Vitesse : " << trame->getVitesse() << " m/s" << endl;

    cout << "\nTrame Temperature : " << trame->getTemperature() << " °C" << endl;

    return 0;
}