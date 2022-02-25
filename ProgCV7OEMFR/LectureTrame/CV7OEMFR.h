#define PC		// On d�cide sur qu'elle syst�me le programme doit fonctionner

#ifdef PC		// On d�finit une partie du programme qui fonctionnera sous PC
	#include <string>
#endif

using namespace std;

#ifdef Lorawan	// On d�finit une partie du programme qui fonctionnera sous Lorawan
	#include "Arduino.h"
	#include "boards.h"
	#include "utilities.h"
	#include "StringSplitter.h"
#endif
	

class CV7OEMFR									// Classe de l'an�mom�tre Ultrasonore
{
private:

		float Vitesse, Temperature, Direction;		// Variables ou ira le resultat demand�
		int typeTrame;								// Variables du type de la trame ("0","1" ou "2")

	#ifdef PC
		string trame;								// Trame r�cup�r�e sous PC
		void splitString(string trame, string delim = ",");		// Fonction permettant de s�parrer la trame � chaque "," rencontr�e sous PC
	#endif

	#ifdef Lorawan
		String trame;								// Trame r�cup�r�e sous Lorawan
	#endif

public:

	#ifdef PC
		CV7OEMFR(string trame = "");				// Constructeur de la classe recevant la trame sous PC
	#endif

	#ifdef Lorawan
		CV7OEMFR(String trame = "");				// Constructeur de la classe recevant la trame sous Lorawan
	#endif

		int getTypeTrame();							// Fonction qui renvoie "0","1" ou "2" en fonction de la trame

		float getVitesse();							// Fonction qui renvoie la Vitesse (r�el)
		float getTemperature();						// Fonction qui renvoie la Temperature (r�el)
		float getDirection();						// Fonction qui renvoie la Direction (r�el)

};