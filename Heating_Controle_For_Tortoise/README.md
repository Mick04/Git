# Heating control for the tortoise enclosure

this sketch as been working in the enclosure for about 15 months (todays date "25/10/2018")
using the Wemos d1 mini and is running on the blynk app.
 
in the "Heating_Controle_For_Tortoise" folder there is a folder containing ds18b20_temperature_sensor_id_detection.ino, you need to run this sketch to find the ID for each of the ds18b20’s the Setup is as follows.


Connect each sensor one at a time the run the sketch open the serial monitor you should get a print out something like this
“ ROM = 40 255 245 190 164 22 3 116 No more addresses.”
Obviously the ID will be different all you need in the sketch is the last number IE “116”.
Also in the folder there are photos of the setup and layouts, schematics and images from fritzing.

Parts List.
Wemos D1 mini.
3 DS18B20 Waterproof Sensors   
1 Y-019 5V RELAY MODULE
1 3.3 Ω resistor
1 4.7k Ω resistor
2 4.7Ω  resistors
1 NPN transistor
1 3 pin terminal block 
1 red LED (optional)
1 Green LED (optional)
Red Green and Yellow wire

See Heater Control instructions.doc or Heater Control instructions.odt


