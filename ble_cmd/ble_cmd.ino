/*
 # 
 # Name       : rn4020_cmd
 # Editor     : OneTwoSteph
 # Date       : 20.10.2016
 # Version    : 1
*/


/**** Libraries ****/
#include <SoftwareSerial.h>


/**** Global variables and parameters ****/
#define GREEN_LED_PIN     2 
#define RED_LED_PIN       3  

#define WAKE_PIN          8

#define SLEEP             "0"
#define WAKE              "1"

#define BAUD_RATE         9600

SoftwareSerial ble(10, 11);         // RX, TX

String cmd = "";
String rsp = "";

/**** Initialization function ****/
void setup() {
  // Initialize wake PIN
  pinMode(WAKE_PIN, OUTPUT);
  digitalWrite(WAKE_PIN, LOW);
  
  // Initalize LED PINS
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  // Initialize hardware serial port (computer)
  Serial.begin(BAUD_RATE);
  while(!Serial);
  
  // Initialize software serial port (ble)
  ble.begin(BAUD_RATE);

  // Info
  Serial.println("Ready to go ! Type 1 to wake up the BLE and 0 to make it sleep. When the BLE is waken up, enter any command. Your commands will be echoed and the response of the BLE is given.");

  // Empty buffers before starting
  char c;
  while(ble.available()>0) c = ble.read();
  while(Serial.available()>0) c = Serial.read();
}


/**** Main loop function ****/
void loop() { 
  // Send command only if all BLE messages where read
  if(ble.available() <= 0){
    while(Serial.available() > 0){
      // Read command
      cmd = Serial.readStringUntil('\n');

      // Take special chars away
      while(cmd.indexOf('\n') != -1) cmd.remove(cmd.indexOf('\n'));
      while(cmd.indexOf('\r') != -1) cmd.remove(cmd.indexOf('\r'));

      // Echo command
      Serial.println(cmd);
      
      // Send command to BLE or wake/sleep BLE depending on command type
      // Command must terminate with "\r"
      if(cmd == SLEEP)
        digitalWrite(WAKE_PIN, LOW);
      else if (cmd ==  WAKE)
        digitalWrite(WAKE_PIN, HIGH);
      else
        ble.print(cmd + "\r");
    }
  }

  // Read BLE feedback
  while(ble.available() > 0){
    // Read buffer
    rsp = ble.readStringUntil('\n');

    // Take special chars away
    while(rsp.indexOf('\n') != -1) rsp.remove(rsp.indexOf('\n'));
    while(rsp.indexOf('\r') != -1) rsp.remove(rsp.indexOf('\r'));

    Serial.println(rsp);

    if(rsp == "ERR")
      Serial.println("Please write a correct command:");
  }     
}
