#include "CV7OEMFR.h"
#include <iostream>

using namespace std;

int main()
{
    CV7OEMFR* a;
    string Vit = "$IIMWV, 344.0, R, 005.9, M, A * 31 < CR > <LF>";
    string Temp = "WIXDR,C,026.0,C,,*56<CR><LF>";
    a = new CV7OEMFR;
    a->splitString(Vit,Temp, ",");

    return 0;
}