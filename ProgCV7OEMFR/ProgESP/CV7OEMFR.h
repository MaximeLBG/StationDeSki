#ifdef CV7OEMFR_h
#define CV7OEMFR_h
#include <Arduino.h>
#include <StringSplitter.h>
#include <ArduinoSTL.h>



class CV7OEMFR
{
private:

  float Vitesse, Temperature, Direction;
  int typeTrame;
  String trame;
  void splitString(String trame, String delim = ",");
  

public:


  CV7OEMFR(String trame = "");
  float getVitesse();
  float getTemperature();
  float getDirection();
  int getTypeTrame();

};
#endif
