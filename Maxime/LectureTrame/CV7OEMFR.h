#include <string>

using namespace std;

class CV7OEMFR
{
private:
	string Vit;
	string Temp;
public:
	CV7OEMFR(string trameVit="$IIMWV,344.0,R,005.9,M,A*31<CR><LF>", string trameTemp="$WIXDR,C,026.0,C,,*56<CR><LF>");
	float getVitesse();
	float getTemperature();
	void splitString(string TrameVit,string TrameTemp, string delim);
};

