#include "CV7OEMFR.h"
#include <iostream>

using namespace std;

int main()
{
    
    string Direction = "$IIMWV,344.0,R,005.9,M,A*31<CR><LF>";
    string Vitesse = "$IIMWV,344.0,R,005.9,M,A*31<CR><LF>";
    string Temperature = "WIXDR,C,026.0,C,,*56<CR><LF>";

    CV7OEMFR* trame;

    trame = new CV7OEMFR(Vitesse,Temperature,Direction);

    cout << "Trame Direction : " << trame->getDirection();

    cout << endl << "\nTrame Vitesse : " << trame->getVitesse();

    cout << endl << "\nTrame Temperature : " << trame->getTemperature() << endl;

    return 0;
}