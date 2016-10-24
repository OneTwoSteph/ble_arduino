/*
 # 
 # Name       : rn4020_cmd_uart
 # Editor     : OneTwoSteph
 # Date       : 24.10.2016
 # Version    : 1
*/


/**** Libraries ****/


/**** Global variables and parameters ****/
#define GREEN_LED_PIN     2 
#define RED_LED_PIN       3  

#define BAUD_RATE         115200

#define STATE_READ        0
#define STATE_WRITE       1

char cmd = "";
String rsp = "";

/**** Initialization function ****/
void setup() {
  // Initalize LED PINS
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  
  // Initialize hardware serial port (computer)
  Serial.begin(BAUD_RATE);
  while(!Serial);

  // Print version
  Serial.println('V');
  delay(1000);
  Serial.println('D');
}


/**** Main loop function ****/
void loop() { 
  
}
