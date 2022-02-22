#ifdef PC
	#include <string>
	using namespace std;
#endif
#ifdef Lorawan
	#include <Arduino.h>
	#include <StringSplitter.h>
#endif
	

class CV7OEMFR
{
private:

	float Vitesse, Temperature, Direction;
	int typeTrame;
#ifdef PC
	string trame;
	void splitString(string trame, string delim = ",");
#endif

#ifdef Lorawan
	String trame;
	void splitString(String trame, String delim = ",");
#endif

public:
#ifdef PC
	CV7OEMFR(string trame = "");
#endif
#ifdef Lorawan
	CV7OEMFR(String trame = "");
#endif
	int getTypeTrame();
	float getVitesse();
	float getTemperature();
	float getDirection();

};