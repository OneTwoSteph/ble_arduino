/*
 # 
 # Name       : rn4020_cmd_rx_test
 # Editor     : OneTwoSteph
 # Date       : 24.10.2016
 # Version    : 1
*/


/**** Libraries ****/
#include <SoftwareSerial.h>


/**** Global variables and parameters ****/
#define GREEN_LED_PIN     2 
#define RED_LED_PIN       3  

#define BAUD_RATE         9600

#define STATE_READ        0
#define STATE_WRITE       1

SoftwareSerial ble(10, 11);         // RX, TX

char cmd = "";
String rsp = "";
int nb = -1;
int old_nb = -1;

/**** Initialization function ****/
void setup() {
  // Initalize LED PINS
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  
  // Initialize software serial port (ble)
  ble.begin(BAUD_RATE);
  
  // Initialize hardware serial port (computer)
  Serial.begin(BAUD_RATE);
  while(!Serial);

  // Info
  Serial.println("Arduino ready to go !");
}


/**** Main loop function ****/
void loop() { 
  // Check number of bytes
  nb = ble.available();
  if(old_nb != nb){
    Serial.print("There are ");
    Serial.print(nb);
    Serial.println(" bytes to print");
  }
  old_nb = nb;

  // Read 1 byte
  if(nb > 0){
    Serial.print("The string '");
    Serial.print(ble.readString());
    Serial.println("' was read");
  }
}
