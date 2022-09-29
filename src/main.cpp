#include <Arduino.h>
// #include <IRremote.h>
#include "include.h"

Midea midea;

const unsigned char Btn = WIO_KEY_A;


// IRsend irsend;
unsigned char state = LOW;
void setup()
{
  // put your setup code here, to run once:
  
  // midea.sendMideaOpen(0xB2,0x5F,0xD0);

  // delay(1000);

  // midea.sendMeidi_CLOSE();

  Serial.begin(9600);
}

void loop()
{
  
}
