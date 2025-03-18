## Clio II Ph1 (1998-2001) cluster (non-CAN)
### The cluster
Cluster described here is, generally, one with part numbers starting with 77.  
They all have four 10-pin plugs: Brown, White, Grey and Black, described below.  
I have a cluster with part number 7700410434, but 7700410442, 7700410430, 7700410437 etc. should also work.  
Some of those don't have tachometers, but the wiring from what I've seen is the same, as all the car wiring was laid equal and only the clusters were different.  
Also, *some* gauge clusters from first gen Kangoo might work I have not tested them, so this is just a guess.  
I've found 7700308748 online and the connections seem to be the same, but I can't give a concrete answer. Beware, some Kangoo clusters with 77 part number came with two-plug setup, as an example p/n 7711368915. I have no idea whether it's a CANbus setup or it's the same plug as first gen Laguna which used those plugs.

Phase 1 Clios also came with CAN-controlled clusters. I honestly These are easily distinguished visually as they have two round dials with a rectangle of warning lights. Also, they have two plugs, a gray 30-pin and red 15-pin. Their part numbers start with **82**, for example 8200059763, 8200276525, 8200054429, 8200059765 and 8200057247.

The cluster I've bought still had original plugs intact with wires cut off. This is preferable as it's easier to solder, however I will provide instructions as to what pins are which in case you have a bare cluster.

### Pins
When looking at the back of the cluster, the plugs (and their pins) are as follows:

|	|	|
|:-:|:-:|
|Black|Brown|
|1-10|1-10|
|Grey|White|
|10-1|10-1|

All the pins are described on the [Pins] page.

### Necessary parts
* Arduino (nano or uno is sufficient),
* 12V source, 1A should suffice
* a single 220ohm resistor

#### Addtional features
* an SPI 5V 2 Relay Module (if you wish to have working indicators),

### Connections

![Connection diagram](diagram.png)

The absolute minimum is to connect pins 3 (red wire) and 10 (yellow wire) from the brown socket to +12V. These are +12 from battery and ignition switch respectively. Next connect Pin 1 from the gray socket to GND. This is main ground of the cluster.  
At this point the mileage display should light up and the low fuel warning light should be illuminated, fuel gauge should show empty.

Next, connect pins 1 and 2 (orange and white wires) from the brown plug with a 220ohm resistor. After some time (or unplugging and replugging power to the cluster (yellow ignition wire should suffice) the low fuel warning lamp should come off and fuel gauge should show about half a tank.

Next, connect arduino's GND pin to your circuit's GND, pin D4 of arduino to pin 8 (violet wire) of black socket and pin D5 of arduino to pin 7 of black socket (white wire). My cluster had two white wires connected to pin 7 in the socket, if yours is like that too, you can use any one of them.

If you want your cluster to have backlight illumination (as if you turned on the lights in the car) connect pin 8 (blue wire) from white socket to +12V and pin 10 of white socket (violet wire) to GND.

### Arduino
The arduino program listens to commands, this repository also has an example python script that connects to BeamNG's OutGauge implementation and transmits them to the cluster.