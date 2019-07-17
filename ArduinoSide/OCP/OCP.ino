/**
 * This example demonstrates how to read analog signals
 * It assumes there are potentiometers connected
 * to the 16 channels of the 74HC4067 mux/demux
 * 
 * For more about the interface of the library go to
 * https://github.com/pAIgn10/MUX74HC4067
 */

#include "MUX74HC4067.h"

int oldPVals[16], curPVal;

MUX74HC4067 mux(7, 8, 9, 10, 11);

void setup()
{
  Serial.begin(9600);
  while (!Serial) ;
  
  mux.signalPin(A0, INPUT, ANALOG);
}

void loop()
{
  int data;

  for (byte i = 0; i < 16; ++i)
  {
    curPVal = round((double)(mux.read(i)) * 100 / 1023);
    if (oldPVals[i] != curPVal){
      if (i < 8){
        Serial.print("0");
      }else{
        Serial.print("1");
      }
      Serial.print(i);
      Serial.print(":");
      Serial.println(curPVal);
      
      oldPVals[i] = curPVal;
    }
    delay(10);
  }  
}
