# ds18b20-print-id
Prints the ID (one wire address) of the first Dallas temperature sensor detected on GPIO2 (D4) of a Wemos D1 mini board

## Hardware setup
The wemos D1 mini has a 10k pullup resistor connected to D4.
This pullup resistor is sufficient to read out one or multiple Dallas
temperature sensors. no additional 4.7k resistors between 3.3V and data are
needed.

A dallas temperature sensor can be connected directly into GND-D4-D3.
D3 also has a 10k pullup resistor. It can be set to OUTPUT, HIGH if
parasite mode does not work with your sensor setup (not done here).

The dallas temperature sensor can be connected either in parasite mode (true
one-wire, no VDD), or the VDD Pin of the sensor can be connected to 3V3.
Connecting to VDD helps in case multiple sensors are connected or if the wires
are long.

## Read out IDs
Open a serial monitor with 115200 baud rate. Or change baud rate in source if
your serial monitor wants to open device with different baud rate.


## Limitations
Only one dallas temp sensor is read.

This is a tool to quickly identify the one wire address of temp sensors.
This tool is not intended to be used to continuously read out the temperatures
from a sensor and store or use them. Use dedicated tools for that purpose.
