#include "CV7OEMFR.h"

CV7OEMFR::CV7OEMFR(String trame)
{
  this->trame = trame;
}


int CV7OEMFR::getTypeTrame()
{
  if (this->trame.find("$IIMWV") != String::npos)
  {
    return 1;
  }
  else if (this->trame.find("$WIXDR") != String::npos)
  {
    return 2;
  }
  else
    return 0;

}
float CV7OEMFR::getVitesse()
{
  splitString(trame);
  return this->Vitesse;
}
float CV7OEMFR::getTemperature()
{
  splitString(trame);
  return this->Temperature;
}
float CV7OEMFR::getDirection()
{
  splitString(trame);
  return this->Direction;
}

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
