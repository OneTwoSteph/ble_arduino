/*
 # 
 #
 # Editor     : OneTwoSteph
 # Date       : 21.10.2016
 # Version    : 1
 #
 #
*/


/**** Libraries ****/
#include "rsa.h"
#include "aes.h"


/**** Global variables and parameters ****/
#define BAUD_RATE		115200


/**** Initialization function ****/
void setup() {
  // Initialize hardware serial port (computer)
  Serial.begin(BAUD_RATE);
  while(Serial);
}


/**** Main loop function ****/
void loop() {
  
  delay(10);       
}