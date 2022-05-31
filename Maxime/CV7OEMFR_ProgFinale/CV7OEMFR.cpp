#include "CV7OEMFR.h"
#ifdef PC
    CV7OEMFR::CV7OEMFR(string frame)    
    {
        this->frame = frame;    //The frame entered in the constructor becomes the frame of the class
    }
#endif

#ifdef Lorawan
    CV7OEMFR::CV7OEMFR(String frame)
    {
        this->frame = frame;    //The frame entered in the constructor becomes the frame of the class
    }
#endif

int CV7OEMFR::getFrameType()
{
    #ifdef PC
        if (this->frame.find("$IIMWV") != string::npos)     //We look for "$IIMWV" in the frame of the class
        {
            return 1;       //If found, return 1
        }
        else if (this->frame.find("$WIXDR") != string::npos)       //We look for "$WIXDR" in the frame of the class
        {
            return 2;       //If found, return 2
        }
        else       //Otherwise if neither of the two frames have been found, we return 0
            return 0;
    #endif

    #ifdef Lorawan
        if (this->frame.indexOf("$IIMWV")!=-1)      //We look for "$IIMWV" in the frame of the class
        {
            return 1;       // If found, return 1
        }
        else if (this->frame.indexOf("$WIXDR")!=-1)     //We look for "$WIXDR" in the frame of the class
        {
            return 2;       // If found, return 2
        }
        else
            return 0;       // Otherwise if neither of the two frames have been found, we return 0
    #endif
}

float CV7OEMFR::getDirection()
{
#ifdef PC
   splitString(frame);      // We return the result of the splitString function, with the class frame as an argument
#endif

#ifdef Lorawan

   StringSplitter* theFrame = new StringSplitter(this->frame,',',6);     //On déclare un pointeur sur la classe StringSplitter
   String result = theFrame->getItemAtIndex(1);      //result takes the result of the function "getItemAtIndex(1)"
   this->direction = result.toFloat();      // direction takes the result of result which is converted to float

#endif
   return this->direction;  // We return the result of direction
}

float CV7OEMFR::getSpeed()
{
#ifdef PC
   splitString(frame);      //We return the result of the splitString function, with the class frame as an argument
#endif
#ifdef Lorawan

   StringSplitter* theFrame = new StringSplitter(this->frame,',',6);     //Declare a pointer to the StringSplitter class
   String result = theFrame->getItemAtIndex(3);      //result takes the result of the "getItemAtIndex(3)" function
   this->speed= result.toFloat();     // speed takes the result of result which is converted to float

#endif
   return this->speed;    //We return the result of speed
}

float CV7OEMFR::getTemperature()
{
#ifdef PC
   splitString(frame);      //We return the result of the splitString function, with the class frame as an argument
#endif
#ifdef Lorawan

   StringSplitter* theFrame = new StringSplitter(this->frame,',',6);     //Declare a pointer to the StringSplitter class
   String result = theFrame->getItemAtIndex(2);      //result takes the result of the "getItemAtIndex(2)" function
   this->temperature = result.toFloat();    // temperature takes the result of result which is converted to float
   
#endif
   return this->temperature;    // We return the result of temperature
}

#ifdef PC
    void CV7OEMFR::splitString(string frame, string delim)
    {
        int start = 0;
        int end = frame.find(delim);
        int flag = 0;
        if(frame.size()<28)
        {
          
        }
          while (end != -1)
          {
              start = end + delim.size();
              end = frame.find(delim, start);
              flag++;
  
              if (flag == 1)
              {
                  if (getFrameType() == 1)
                  {
                      this->direction = stof(frame.substr(start, end - start));
                  }
              }
  
              else if (flag == 2)
              {
                  if (getFrameType() == 2)
                  {
                      string tmp = frame.substr(start, end - start);
                      this->temperature = stof(tmp);
                  }
  
              }
  
              else if (flag == 3)
              {
                  if (getFrameType() == 1)
                  {
                      this->speed = stof(frame.substr(start, end - start));
                  }
                  break;
              }
          }
    }
#endif
