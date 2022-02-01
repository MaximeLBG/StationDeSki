#include "CV7OEMFR.h"

CV7OEMFR::CV7OEMFR(string trameVit, string trameTemp, string trameDir)
{
	this->Vit = trameVit;
	this->Temp = trameTemp;
	this->Dir = trameDir;
}

float CV7OEMFR::getVitesse()
{
	splitString(Vit);
	return this->Vitesse;
}
float CV7OEMFR::getTemperature()
{
	splitString(Temp);
	return this->Temperature;
}
string CV7OEMFR::getDirection()
{
	splitString(Dir);
	return this->Direction;
}

void CV7OEMFR::splitString(string trame, string delim)
{
	int start = 0;
	int end = trame.find(delim);
	int flag = 0;
	string resultat;

	while (end != -1)
	{
		//cout << "\t" << trame.substr(start, end - start) << endl;		Pour l'afficher ajouter "#include <iostream>"
		start = end + delim.size();
		end = trame.find(delim, start);
		flag++;


		if (trame == this->Vit)
		{
			if (flag == 3)
			{
				Vitesse = stof(trame.substr(start, end - start));
				//Vitesse = stof(resultat);
			}
		}

		if (trame == this->Dir)
		{
			if (flag == 2)
			{
				Direction = (trame.substr(start, end - start));
				//Direction = resultat;
			}
		}
	
		if (trame == this->Temp)
		{
			if (flag == 2)
			{
				Temperature = stof(trame.substr(start, end - start));
				//Temperature = stof(resultat);
			}
		}
	}
	//cout << "\t" << trame.substr(start, end - start);
}