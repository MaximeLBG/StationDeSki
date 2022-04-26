#include "CV7OEMFR.h"
#ifdef PC
    CV7OEMFR::CV7OEMFR(string trame)    
    {
        this->trame = trame;    // La trame rentr�e dans le constructeur devient la trame de la classe
    }
#endif

#ifdef Lorawan
    CV7OEMFR::CV7OEMFR(String trame)
    {
        this->trame = trame;    // La trame rentrée dans le constructeur devient la trame de la classe
    }
#endif

int CV7OEMFR::getTypeTrame()
{
    #ifdef PC
        if (this->trame.find("$IIMWV") != string::npos)     //On chercher "$IIMWV" dans la trame de la classe
        {
            return 1;       // Si on à trouvé, on renvoi 1
        }
        else if (this->trame.find("$WIXDR") != string::npos)       //On chercher "$WIXDR" dans la trame de la classe
        {
            return 2;       // Si on à trouvé, on renvoi 2
        }
        else       // Sinon si aucune des deux trames ont �t� touv�es, on renvoi 0
            return 0;
    #endif

    #ifdef Lorawan
        if (this->trame.indexOf("$IIMWV")!=-1)      //On chercher "$IIMWV" dans la trame de la classe
        {
            return 1;       // Si on à trouvé, on renvoi 1
        }
        else if (this->trame.indexOf("$WIXDR")!=-1)     //On chercher "$WIXDR" dans la trame de la classe
        {
            return 2;       // Si on à trouvé, on renvoi 2
        }
        else
            return 0;       // Sinon si aucune des deux trames ont �t� touv�es, on renvoi 0
    #endif
}

float CV7OEMFR::getDirection()
{
#ifdef PC
   splitString(trame);      // On renvoi le resultat de la fonction splitString, avec comme argument, la trame de la classe
#endif

#ifdef Lorawan

   StringSplitter* laTrame = new StringSplitter(this->trame,',',6);     //On d�clare un pointeur sur la classe StringSplitter
   String result = laTrame->getItemAtIndex(1);      //result prend le resultat de la fonction "getItemAtIndex(1)"
   this->Direction = result.toFloat();      // Direction prend le resultat de result qui est converti en float

#endif
   return this->Direction;  // On renvoi le resultat de Direction
}

float CV7OEMFR::getVitesse()
{
#ifdef PC
   splitString(trame);      // On renvoi le resultat de la fonction splitString, avec comme argument, la trame de la classe
#endif
#ifdef Lorawan

   StringSplitter* laTrame = new StringSplitter(this->trame,',',6);     //On d�clare un pointeur sur la classe StringSplitter
   String result = laTrame->getItemAtIndex(3);      //result prend le resultat de la fonction "getItemAtIndex(3)"
   this->Vitesse= result.toFloat();     // Vitesse prend le resultat de result qui est converti en float

#endif
   return this->Vitesse;    // On renvoi le resultat de Vitesse
}

float CV7OEMFR::getTemperature()
{
#ifdef PC
   splitString(trame);      // On renvoi le resultat de la fonction splitString, avec comme argument, la trame de la classe
#endif
#ifdef Lorawan

   StringSplitter* laTrame = new StringSplitter(this->trame,',',6);     //On d�clare un pointeur sur la classe StringSplitter
   String result = laTrame->getItemAtIndex(2);      //result prend le resultat de la fonction "getItemAtIndex(2)"
   this->Temperature = result.toFloat();    // Temperature prend le resultat de result qui est converti en float
   
#endif
   return this->Temperature;    // On renvoi le resultat de Temperature
}

#ifdef PC
    void CV7OEMFR::splitString(string trame, string delim)
    {
        int start = 0;
        int end = trame.find(delim);
        int flag = 0;
        if(trame.size()<28)
        {
          
        }
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
