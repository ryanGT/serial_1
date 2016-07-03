#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

int inByte;

void setup()
{
  Serial.begin(115200);

  //Serial.print("serial echo test genuino");
  //Serial.print("\n");// I always specify my linefeeds so I don't
                     // get messed up on different operating systems.
}

void loop()
{
  if (Serial.available() > 0) {
    inByte = Serial.read();
    if (inByte == 1){
      Serial.print("You sent me a true 1.");
      Serial.print("\n");
    }
    else if (inByte == 49){//ascii "1"
      Serial.print("You sent me an ascii 1.");
      Serial.print("\n");      
    }
    else if (inByte == 48){//ascii "0"
      Serial.print("serial echo test genuino 07/03/16");
      Serial.print("\n");
    }
    else {
      Serial.print("genuino: You sent me something else.");
      Serial.print("\n");
    }
  }
  delay(10);// wait 10 milliseconds before checking if new serial
            // bytes are available
}
