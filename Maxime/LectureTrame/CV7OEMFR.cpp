#include "iostream"
#include "CV7OEMFR.h"

CV7OEMFR::CV7OEMFR(string trameVit, string trameTemp)
{
	this->Vit = trameVit;
	this->Temp = trameTemp;
}
float CV7OEMFR::getVitesse()
{
	char delim = ',';
	for (int i = 0; i < Vit.length(); i++)
	{
		if (Vit[i] == delim)
		{
			splitString(Vit, ",");
		}
	}
	return 0;
}
float CV7OEMFR::getTemperature()
{
	char delim = ',';
	for (int i = 0; i < Temp.length(); i++)
	{
		if (Temp[i] == delim)
		{

		}
	}
	return 0;
}
void CV7OEMFR::splitString(string TrameVit,string TrameTemp, string delim = ",")
{
	TrameVit = this->Vit;
	TrameTemp = this->Temp;
	int startVit = 0;
	int endVit = TrameVit.find(delim);
	while (endVit != -1)
	{
		cout << Vit.substr(startVit, endVit - startVit) << endl;
		startVit = endVit + delim.size();
		endVit = TrameVit.find(delim, startVit);
	}
	cout << TrameVit.substr(startVit, endVit - startVit);

	int startTemp = 0;
	int endTemp = TrameTemp.find(delim);
	while (endTemp != -1)
	{
		cout << Temp.substr(startTemp, endTemp - startTemp) << endl;
		startTemp = endTemp + delim.size();
		endTemp = TrameTemp.find(delim, startTemp);
	}
	cout << TrameTemp.substr(startTemp, endTemp - startTemp);
}