#include "iostream"
#include "CV7OEMFR.h"

CV7OEMFR::CV7OEMFR(string trameVit, string trameTemp, string trameDir)
{
	this->Vit = trameVit;
	this->Temp = trameTemp;
	this->Dir = trameDir;
}
CV7OEMFR::~CV7OEMFR()
{
}
void CV7OEMFR::splitString(string trame, string delim)
{
	int start = 0;
	int end = trame.find(delim);
	int flag = 0;

	while (end != -1)
	{
		//cout << "\t" << trame.substr(start, end - start) << endl;
		start = end + delim.size();
		end = trame.find(delim, start);
		flag++;
		if (trame == this->Vit)
		{
			if (flag == 3)
			{
				cout << "\t" << trame.substr(start, end - start) << endl;
			}
		}

		if (trame == this->Dir)
		{
			if (flag == 2)
			{
				cout << "\t" << trame.substr(start, end - start) << endl;
			}
		}
	
		if (trame == this->Temp)
		{
			if (flag == 2)
			{
				cout << "\t" << trame.substr(start, end - start) << endl;
			}
		}
	}
	//cout << "\t" << trame.substr(start, end - start);
}