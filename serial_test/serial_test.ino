#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

int inByte;
int dataByte;
int dataByte2;
int out;

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
    else if (inByte == 2){
      //Case 2: read next byte and return next byte plus one
      dataByte = Serial.read();
      out = dataByte + 1;
      Serial.write(out);
    }
    else if (inByte == 3){
      //Case 3: read next byte and return next byte squared
      dataByte = Serial.read();
      out = dataByte*dataByte;
      Serial.write(out);
    }    
    else if (inByte == 4){
      //Case 4: read two additional bytes and return byte1 + byte2
      dataByte = Serial.read();
      dataByte2 = Serial.read();
      out = dataByte + dataByte2;
      Serial.write(out);
    }    
    else {
      Serial.print("genuino: You sent me something else.");
      Serial.print("\n");
    }
  }
  delay(10);// wait 10 milliseconds before checking if new serial
            // bytes are available
}
