#include "CV7OEMFR.h"
#ifdef PC
    CV7OEMFR::CV7OEMFR(string trame)
    {
        this->trame = trame;
    }
#endif

#ifdef Lorawan
    CV7OEMFR::CV7OEMFR(String trame)
    {
        this->trame = trame;
    }
#endif

int CV7OEMFR::getTypeTrame()
{
    #ifdef PC
        if (this->trame.find("$IIMWV") != string::npos)
        {
            return 1;
        }
        else if (this->trame.find("$WIXDR") != string::npos)
        {
            return 2;
        }
        else
            return 0;
    #endif

    #ifdef Lorawan
        if (this->trame.indexOf("$IIMWV")!=-1)
        {
            return 1;
        }
        else if (this->trame.indexOf("$WIXDR")!=-1)
        {
            return 2;
        }
        else
            return 0;
    #endif
}

float CV7OEMFR::getDirection()
{
#ifdef PC
   splitString(trame);
#endif

#ifdef Lorawan
   StringSplitter* laTrame = new StringSplitter(this->trame,',',6);
   String result = laTrame->getItemAtIndex(1);
   this->Direction = result.toFloat();
#endif
   return this->Direction;
}

float CV7OEMFR::getVitesse()
{
#ifdef PC
   splitString(trame);
#endif
#ifdef Lorawan
   StringSplitter* laTrame = new StringSplitter(this->trame,',',6);
   String result = laTrame->getItemAtIndex(3);
   this->Vitesse= result.toFloat();
#endif
   return this->Vitesse;
}

float CV7OEMFR::getTemperature()
{
#ifdef PC
   splitString(trame);
#endif
#ifdef Lorawan
   StringSplitter* laTrame = new StringSplitter(this->trame,',',6);
   String result = laTrame->getItemAtIndex(2);
   this->Temperature = result.toFloat();
#endif
   return this->Temperature;
}

#ifdef PC
    void CV7OEMFR::splitString(string trame, string delim)
    {
        int start = 0;
        int end = trame.find(delim);
        int flag = 0;

        while (end != -1)
        {
            start = end + delim.size();
            end = trame.find(delim, start);
            flag++;

            if (flag == 1)
            {
                if (getTypeTrame() == 1)
                {
                    this->Direction = stof(trame.substr(start, end - start));
                }
            }

            else if (flag == 2)
            {
                if (getTypeTrame() == 2)
                {
                    string tmp = trame.substr(start, end - start);
                    this->Temperature = stof(tmp);
                }

            }

            else if (flag == 3)
            {
                if (getTypeTrame() == 1)
                {
                    this->Vitesse = stof(trame.substr(start, end - start));
                }
                break;
            }
        }
    }
#endif
