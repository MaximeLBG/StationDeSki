#include "CV7OEMFR.h"

 CV7OEMFR trame("$IIMWV,344.0,R,005.9,M,A*31") ;
 
 //using namespace std; 


void setup() {
  int result = trame.getTypeTrame();
  if(result == 1)
  {
    Serial.print(trame.getDirection());
    Serial.print(trame.getVitesse());   
  }
  else if (result == 2)
  {
    Serial.print(trame.getTemperature());
  }
  else
    Serial.print("Aucune trame trouvée.");
        
}

void loop() {
  
  
}
