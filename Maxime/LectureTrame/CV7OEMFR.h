#include <string>

using namespace std;

class CV7OEMFR
{
private:
	string Vit;
	string Temp;
	string Dir, Direction;

	float Vitesse, Temperature;
public:
	CV7OEMFR(string trameVit = "", string trameTemp = "", string trameDir = "");
	~CV7OEMFR();
	void splitString(string trame, string delim = ",");
	float getVitesse() {return this->Vitesse;};
	float getTemperature() { return this->Temperature; };
	string getDirection() { return this->Direction; };
};

