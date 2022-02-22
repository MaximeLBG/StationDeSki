*#include "CV7OEMFR.h"

#ifdef PC

	CV7OEMFR::CV7OEMFR(string trameVit, string trameTemp, string trameDir)
{
	this->Vit = trameVit;
	this->Temp = trameTemp;
	this->Dir = trameDir;
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


		if (trame == this->Vit)
		{
			if (flag == 3)
			{
				this->Vitesse = toFloattrame.substr(start, end - start));
			}
		}

		if (trame == this->Dir)
		{
			if (flag == 1)
			{
				this->Direction = toFloat(trame.substr(start, end - start));
			}
		}

		if (trame == this->Temp)
		{
			if (flag == 2)
			{
				this->Temperature = toFloat(trame.substr(start, end - start));
			}
		}
	}
}

#endif

#ifdef ESP
	CV7OEMFR::CV7OEMFR(String trameVit, String trameTemp, String trameDir)
	{
		this->Vit = trameVit;
		this->Temp = trameTemp;
		this->Dir = trameDir;
	}

	void CV7OEMFR::splitString(String trame, String delim)
	{
		int flag=0;

		for (int i = 0; i < trame.length(); i++)
		{
			if (trame[i] != delim)
			{
				flag++;
			}
			else
			{
				start = trame[flag]
			}
		}


		int start = 0;
		int end = trame.endsWith(delim);
		int flag = 0;

		while (end != -1)
		{
			start = end + delim.length();
			end = trame.endsWith(delim, start);
			flag++;


			if (trame == this->Vit)
			{
				if (flag == 3)
				{
					this->Vitesse = toFloat(trame.substring(start, end - start));
				}
			}

			if (trame == this->Dir)
			{
				if (flag == 1)
				{
					this->Direction = toFloat(trame.substring(start, end - start));
				}
			}

			if (trame == this->Temp)
			{
				if (flag == 2)
				{
					this->Temperature = toFloat(trame.substring(start, end - start));
				}
			}
		}
	}
#endif


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
float CV7OEMFR::getDirection()
{
	splitString(Dir);
	return this->Direction;
}

