#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS D4
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200); //Begin serial communication
  Serial.println("Arduino Digital Temperature // Serial Monitor Version"); //Print a message
  sensors.begin();
  sensors.setResolution(12);
}

void loop() {
  // Send the command to get temperatures
  sensors.requestTemperatures();  
  Serial.print("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0));
  DeviceAddress address={0,0,0,0,0,0,0,0};
  sensors.getAddress(address, 0);
  for (unsigned i=0; i<sizeof(address); ++i) {
    Serial.print(address[i]/16, HEX);
    Serial.print(address[i]&15, HEX);
  }
  Serial.println();
  //Update value every 1 sec.
  delay(1000);
}
