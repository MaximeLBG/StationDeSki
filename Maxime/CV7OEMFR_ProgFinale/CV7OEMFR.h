#define Lorawan    //We decide on which system the program should run

#ifdef PC   //We define a part of the program that will work on PC
  #include <string>     //We include the string library
#endif

using namespace std;

#ifdef Lorawan  //We define a part of the program that will work under Lorawan
  #include <Arduino.h>      //We include the Arduino library
  #include "StringSplitter.h"   //We include the StringSplitter library
#endif
  

class CV7OEMFR                  //Ultrasonic Anemometer Class
{
private:

    float speed, temperature, direction;    //Variables where the requested result will go
    int frameType;                //Frame type variables("0", "1" or "2")

  #ifdef PC
    string frame;               //Frame retrieved on PC
    void splitString(string frame, string delim = ",");   //Function to separate the frame at each "," encountered on PC
  #endif

  #ifdef Lorawan
    String frame;               //Frame retrieved under Lorawan
  #endif

public:

  #ifdef PC
    CV7OEMFR(string frame = "");        //Constructor of the class receiving the frame under PC
  #endif

  #ifdef Lorawan
    CV7OEMFR(String frame = "");        //Constructor of the class receiving the frame under Lorawan
  #endif
    int getFrameType();             // Function that returns "0", "1" or "2" depending on the frame
    
    float getSpeed();             // Function that returns Speed ​​(real)
    float getTemperature();         // Function that returns Temperature ​​(real)
    float getDirection();           // Function that returns Direction ​​(real)

};
