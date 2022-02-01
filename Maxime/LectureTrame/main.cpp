#include "CV7OEMFR.h"
#include <iostream>

using namespace std;

int main()
{
    
    string Direction;
    string Vitesse = "$IIMWV,344.0,R,005.9,M,A*31<CR><LF>";
    string Temperature = "WIXDR,C,026.0,C,,*56<CR><LF>";
    Direction=Vitesse;

    CV7OEMFR* trame[3];

    trame[0] = new CV7OEMFR(Direction);
    trame[1] = new CV7OEMFR(Vitesse);
    trame[2] = new CV7OEMFR(Temperature);

    cout << "Trame Direction :\n" << endl;
    trame[0]->splitString(Direction);
    //trame[0]->getDirection();
    //delete trame[0];

    cout << endl << "\nTrame Vitesse :\n" << endl;
    trame[1]->splitString(Vitesse);
    //trame[1]->getTemperature();
    //delete trame[1];

    cout << endl << "\nTrame Temperature :\n" << endl;
    trame[2]->splitString(Temperature);
    //trame[2]->getTemperature();
    //delete trame[2];

    return 0;
}