/*
 # 
 #
 # Editor     : OneTwoSteph
 # Date       : 20.10.2016
 # Version    : 1
*/


/**** Libraries ****/
#include <SoftwareSerial.h>


/**** Global variables and parameters ****/
#define GREEN_LED_PIN     2 
#define RED_LED_PIN       3  

#define BAUD_RATE         115200

SoftwareSerial ble(10, 11);         // RX, TX

bool state = 0;


/**** Initialization function ****/
void setup() {
  // Initalize LED PINS
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  
  // Initialize software serial port (ble)
  ble.begin(BAUD_RATE);
  while(!ble);
  
  // Initialize hardware serial port (computer)
  Serial.begin(BAUD_RATE);
  while(Serial);
  
  // Configure the BLE
}


/**** Main loop function ****/
void loop() {
  digitalWrite(GREEN_LED_PIN, state);               
  digitalWrite(RED_LED_PIN, !state);
  state = !state;
  delay(1000);       
}
