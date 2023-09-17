#include <SoftwareSerial.h>

// Define the TX and RX pins for the SIM800L module
const int sim800lTxPin = 7;  // TX pin of SIM800L connected to Arduino's digital pin 7
const int sim800lRxPin = 8;  // RX pin of SIM800L connected to Arduino's digital pin 8

// Create a SoftwareSerial object for communication with the SIM800L module
SoftwareSerial sim800l(sim800lTxPin, sim800lRxPin);

void setup() {
  // Start serial communication with the Arduino IDE Serial Monitor
  Serial.begin(9600);
  
  // Start serial communication with the SIM800L module
  sim800l.begin(9600);
  
  // Give some time for the module to initialize
  delay(1000);
  
  Serial.println("Testing GSM Condition...");
}

void loop() {
  // Check if data is available from the SIM800L module
  if (sim800l.available()) {
    // Read the data from the module and print it to the Serial Monitor
    char c = sim800l.read();
    Serial.print(c);
  }
}
