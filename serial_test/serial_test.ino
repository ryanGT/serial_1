#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

int inByte;

void setup()
{
  Serial.begin(115200);

  Serial.print("serial echo test");
  Serial.print("\n");// I always specify my linefeeds so I don't
                     // get messed up on different operating systems.
}

void loop()
{
  if (Serial.available() > 0) {
    inByte = Serial.read() - '0';
    if (inByte == 1){
      Serial.print("You sent me a 1.");
      Serial.print("\n");
    }
    else {
      Serial.print("You sent me a something else.");
      Serial.print("\n");
    }
  }
  delay(10);// wait 10 milliseconds before checking if new serial
            // bytes are available
}
