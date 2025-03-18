## Description of all the pins in the cluster and what they do
Warning lamps have (+12V) if you have to supply the pin with +12V to illuminate them or (GND) if you have to ground the pin.

### Brown plug

| Pin ID | Original wire color | Description |
|:-|:-:|:-:|
| 1 | orange | fuel sender + |
| 2 | white | fuel sender - |
| 3 | red | +12V, main power source of cluster[1] |
| 4 | violet | trip computer reset GND[2] |
| 5 | |||
| 6 | white-green | injection warning light (GND) |
| 7 | brown | alternator warning light (GND) |
| 8 |||
| 9 |||
| 10 | yellow | ignition switch +12V |

* [1]: it's also a +12V pin for immobilizer LED.
* [2]: grounding this "trip computer reset" does the same thing as pressing the button on the cluster itself, it resets the trip odometer.

### Black plug

| Pin ID | Original wire color | Description |
|:-|:-:|:-:|
| 1 | ||
| 2 | grey | breakpad wear warning light (GND) |
| 3 | green | abs warning light (GND) |
| 4 | white | handbrake warning light (GND) |
| 5 | beige | Immobilizer LED GND |
| 6 | pink | connects to trip computer somehow, i don't know |
| 7 | white | rev counter signal wire |
| 8 | violet | speedometer signal wire |
| 9 | gray-red | oil level indicator[3] |
| 10 | orange | oil level indicator[3] |

* [3]: in a real car the display which usually shows the odometer displays an oil level for a short time after starting an engine. The sensor is a variable resistor, perhaps connecting it to a resistor would show something when connecting power, but I haven't tested it.

### Gray plug

| Pin ID | Original wire color | Description |
|:-|:-:|:-:|
| 1 | black | GND |
| 2 |||
| 3 |||
| 4 |||
| 5 | green | high coolant temp warning light (+12V) |
| 6 | violet-yellow | oil pressure warning light (+12V) |
| 7 | ||
| 8 | beige | rear foglights warning lamp (+12V) |
| 9 | pink | front foglights warning lamp (+12V) |
| 10 | orange | right indicator warning lamp (+12V) |

### White plug
| Pin ID | Original wire color | Description |
|:-|:-:|:-:|
| 1 | violet | left indicator warnign light (+12V) |
| 2 | beige | low beam lights warning light (+12V) |
| 3 | white | high beam lights warning light (+12V) |
| 4 | orange | fasten seatbelts warning light (GND) |
| 5 | violet-green | glowplugs warning light (GND) |
| 6 | violet | airbag warning light (GND) |
| 7 | beige-green | door ajar warning light (GND) |
| 8 | blue | instrument illumination +12V |
| 9 | gray | temp gauge, it's a variable resistor |
| 10 | violet | instrument illumination GND |
