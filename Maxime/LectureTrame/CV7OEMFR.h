#include <string>

using namespace std;

class CV7OEMFR
{
private:
	string Vit, Temp, Dir;
	float Vitesse, Temperature, Direction;
	void splitString(string trame, string delim = ",");

public:

	CV7OEMFR(string trameVit = "", string trameTemp = "", string trameDir = "");

	float getVitesse();
	float getTemperature();
	float getDirection();
};