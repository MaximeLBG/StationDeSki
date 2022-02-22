#define ESP

#ifdef PC
	#include <string>
	using namespace std;
#endif
#ifdef ESP
	#include <Arduino.h>
	#include <ArduinoSTL.h>
#endif

class CV7OEMFR
{
private:
	#ifdef PC
		string Vit, Temp, Dir;
		void splitString(string trame, string delim = ",");
	#endif

	#ifdef ESP
		String Vit, Temp, Dir;
		void splitString(String trame, String delim = ",");
	#endif

		double Vitesse, Temperature, Direction;

public:

	#ifdef PC
		CV7OEMFR(string trameVit = "", string trameTemp = "", string trameDir = "");
	#endif

	#ifdef ESP
		CV7OEMFR(String trameVit = "", String trameTemp = "", String trameDir = "");
	#endif

		float getVitesse();
		float getTemperature();
		float getDirection();
};