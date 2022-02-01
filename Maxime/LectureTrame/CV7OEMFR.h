#include <string>

using namespace std;

class CV7OEMFR
{
private:
	string Vit, Temp, Dir, Direction;
	float Vitesse, Temperature;
	void splitString(string trame, string delim = ",");

public:

	CV7OEMFR(string trameVit = "", string trameTemp = "", string trameDir = "");

	float getVitesse();
	float getTemperature();
	string getDirection();
};