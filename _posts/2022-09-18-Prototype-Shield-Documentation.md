# Prototype Shield Documentation

## Step-By-Step Tutorial by Aalya and Ahmed

## Brainstorming & Establishing Requirements

Before we get into the physical work of connecting and soldering everything on the prototype shield, we must first understand where everything goes. In this particular case, we are working with a radio that will be recieving transmissions. The radio itself consists of three main elements: a row that connects to power, a row that connects to ground, and a row that for the signals in the radio. That means that we are going to need 3 rows of header pins connected to the board: a place for the radio to connect to. You can find an image attached below in order to get a clearer understanding. You can see the bottom row (the far left on the screen) is dedicated to the signal. You can see the channels are labeled from 1 - 6. Next, the middle row is labeled positive, meaning it needs to be connected to 5V on the arduino. Finally, the top row (far right on the screen) is dedicated to ground, which is what it needs to be connected to on the arduino. 

<img width="355" alt="Screen Shot 2022-09-18 at 8 51 11 PM" src="https://user-images.githubusercontent.com/70956039/190919188-da48097f-de2b-496c-bf5a-d9bd88e72865.png">


Next, we need to think of the wiring. What pins should connect to what element in the radio? In this case it was rather simple to figure out. As mentioned, we must have a row connected to 5V and another connected to ground. In that sense, we did not have to make many deisions. We just needed to properly wire the correct row to the correct bus on the prototype shield. As for the last row, the one dedicated to the signal, we have to think of what would be the most convenient. In this case, we only needed to wire 4 of the signal pins, which made this task much easier. Based on convienience, it was decided that the pins would be wired as shown below:

(insert sketch i drew)

## Soldering Process

**Preparing the Header Pins**

- Cutting the header pins for the radio
- Mention the big header pins (the ones that connect to the arduino)
- How it should be cut in a way that ensures that it fits into the radio

**Preparing the Wires**

- Stripping the wires
- bending them so they fit nicely
- measuring their length

**Soldering to the Shield**

Once the wires have been shaped and fitted to their respective locations, it is important to correctly solder them to the board and establish a connection. Solder the wires to the board using the soldering iron and wound up solder. Bring the Solder close to the wire and let the iron melt the solder onto the board. Solder is a conductive material that melts at around the 300 degree mark ont he soldering iron, which should not be turn up any higher than 350 degrees celcius. 

Show picture of Soldering onto the board

A clean soldered connection should have a cone like shape as the wire connects the pin to the board. This cone shape takes up less space and is helpful in make sure there are not shorted connections. Some tips are shared as to how to best clean up any mishapen or extra soldered connection in the final touches section below. Though the board would work with mishapen connections with extra solder that isnt touching any other connection, it is still helpful to make each connection as clean as possible

Show underside of the board image

One helpful tip for getting the wires flush and as close to the surface of the board as possible is to first establish a loose soldered connection without worrying about how close the wire is to the board. Now that the connection has been made, you can have the iron in one hand and press onto the wire from the back with the other. Reheat the soldered connection to release the wire and then press the wire down towards the board with the other hand. This will solidify with the wire flush onto the board however be careful not to have your hand there for too loing as it will be very hot, as the wire weill conduct heat.

Estalbish the soldered connections of each wire near the analogue pins. Now it is important to connect the wire to the headers. Use the tweezers to bend the wire towards the pins of the soldered down header as shown in the image below. This will make it much easier to establish a clean connection. Then, int he same fashion as the other connections, solder the wire to the pin, thereby connecting the wire to the headers.

Show picture of headers

Now that the wires are connected and the motor inputs have a way of being received, the shield must have a way to receive power and be grounded. Wires will have to be run to the 5V and the GND bus, located on the top left of the board.

show image of the 5V and GND bus/ column

In a similar way, solder the wires that have already been made down in the same fashion as the previous connections. Place the wire and solder down the ends to the bus/ column. Then, bend the excess wire near the headers towards the header pins to ease connection and solder the two together. 
Show image of all the sodlered connection


- Show images of the actual soldering process
- Mention some tricks and tips that help with soldering
- Placement of the iron on the board, how it allows the solder to flow, etc...
- It should be shaped like a cone, shouldn't go up too high on the wire, etc...

**Final Touches**

One final note is to make sure everything is trimmed and flush. Any excess wire poking out (as shown in the image below) should be trimmed down and closer to the board. Any soldered connections that are too wide or have too much solder should be cleaned up. This can be done in a multitude of different ways. One effective way is my using the suction apartus in the transparent ins on your desk. This is used to suck up any excess heated solder. Press down on the top of the suction to engage the equipment. Use the iron the heat up the solder the press the small black button on the front near the middle of the suction apartatus to suck up the solder. Another way is to heat up the solder to take it onto the iron then clean the iron on the wound up steel wool (gold) on the table. These are both effective ways in cleaning up the soldered connections. Make sure there is not excess solder randomly on the board as this could cause unintentionally short circtuits in the future.


## Testing the Shield
