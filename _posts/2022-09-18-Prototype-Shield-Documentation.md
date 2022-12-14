# Prototype Shield Documentation

## Step-By-Step Tutorial by Aalya and Ahmed

## Brainstorming & Establishing Requirements

Before we get into the physical work of connecting and soldering everything on the prototype shield, we must first understand where everything goes. In this particular case, we are working with a radio that will be recieving transmissions. The radio itself consists of three main elements: a row that connects to power, a row that connects to ground, and a row that for the signals in the radio. That means that we are going to need 3 rows of header pins connected to the board: a place for the radio to connect to. You can find an image attached below in order to get a clearer understanding. You can see the bottom row (the far left on the screen) is dedicated to the signal. You can see the channels are labeled from 1 - 6. Next, the middle row is labeled positive, meaning it needs to be connected to 5V on the arduino. Finally, the top row (far right on the screen) is dedicated to ground, which is what it needs to be connected to on the arduino. 

<img width="355" alt="Screen Shot 2022-09-18 at 8 51 11 PM" src="https://user-images.githubusercontent.com/70956039/190919188-da48097f-de2b-496c-bf5a-d9bd88e72865.png">


Next, we need to think of the wiring. What pins should connect to what element in the radio? In this case it was rather simple to figure out. As mentioned, we must have a row connected to 5V and another connected to ground. In that sense, we did not have to make many deisions. We just needed to properly wire the correct row to the correct bus on the prototype shield. As for the last row, the one dedicated to the signal, we have to think of what would be the most convenient. In this case, we only needed to wire 4 of the signal pins, which made this task much easier. Based on convienience, it was decided that the pins would be wired as shown below:

(insert sketch i drew)

## Soldering Process

**Preparing the Header Pins**

There are two kinds of header pins we need for this particular project. First, the header pins that will connect the arduino. This is pretty straightforward, as the only thing you really have to do is make sure you pick the correct number of pins that will fit into the arduino. These are the ones that go to the side of the shield, that will later slide into the arduino. Second, you need header pins toin order to connect your radio to the shield. For this, you begin by grabbing a strip of header pins.

![IMG_6985](https://user-images.githubusercontent.com/70956039/193660275-3432a2e8-c9e3-433d-af4a-45608a6f1a66.jpg)

Next, you need to cut it based on what you need. In our case, the radio consists of 3 rows (with 6 pins in each). That means we need to have three strips in total, each of which can hold 6 pins. In order to properly cut the header strip, you need to count how many pins you need, and on cut on the next pin over. Meaning, if you need 6 pins, you cut the strip on the 7th pin. Make sure you leave enough distance to ensure that it is the amount of pins you require. It is always better to have more than less. 

![IMG_6989](https://user-images.githubusercontent.com/70956039/193661088-b23e61ea-90b6-4439-b0a2-c3a3bf29346e.JPG)

Once you cut it, you need to make sure that it fits into the radio before you solder it onto the board, otherwise it would be diffcult to fix it later. If it fits into the radio, then you are good to go. If not, here is what you should do:

1. Grab a small cutter, one that you can easily control and maneuvre
2. Try to cut off any excess off the header pin
3. Make sure that the sides and corners of the header pin are all straight, with no parts sticking out as that would prevent it from sliding into the radio
4. It is all about trial and error. Try cutting it where you think is needed, and then check if it fits in the radio. If not, try again until you eventually get it!

Here are images to help visualize the process:

![IMG_7001](https://user-images.githubusercontent.com/70956039/193662447-ae899196-44d3-4d89-935e-b4ca7aa09c55.JPG)

These header pins are somewhat faulty. If you focus on the edge of the pins, you can see that it is not straight. For some of them, it is comign down at a slant and at an angle. Those are the parts of the header pin you want to cut off.

![IMG_7007](https://user-images.githubusercontent.com/70956039/193663072-7e39b770-9397-4be5-b024-a25d2d699b2f.jpg)

Eventually, you will reach what is shown above, a stage where the header pins fit into the radio. 

**Preparing the Wires**

Next, we need to prepare the wires prior to the soldering process. The wiring of the board is integral and imperative for it to function properly. This is something that needs to be briefly planned before, that way the wires can go into the board in the most effective way.

1. First, grab some solid wire, and cut a length that you can work with (enough where you can bend it and move it around the board, and not accidentaly come up short). It is better to have more wire than less!
2. Next, you need to strip the wire on one end. This will allow you to solder it into the board later. The way to do that is by grabbing your wire cutters, and within them, you should be able to strip the wires. 

(insert image here)

3. Next, you need to bend the wire. This is so that it will fit close to the board in a neat way. Think of it as a path from one point of the board to the other, in this case, from the radio pins to the arduino pins. To summarize, the wires should be connected as follows: 

      | RADIO PIN   | ARDUINO PIN |
      | :---:       |    :----:   |
      | 0           | 8           |
      | 1           | 7           |
      | 2           | 4           |
      | 3           | 2           |
      
  This means that you have to figure out a way to bend the wires to fit into the assigned pins. 
      
- Stripping the wires
- bending them so they fit nicely (mention what pins they need to go into). 
- measuring their length

**Soldering to the Shield**

Once the wires have been shaped and fitted to their respective locations, it is important to correctly solder them to the board and establish a connection. Solder the wires to the board using the soldering iron and wound up solder. Bring the Solder close to the wire and let the iron melt the solder onto the board. Solder is a conductive material that melts at around the 300 degree mark on the soldering iron, which should not be turn up any higher than 350 degrees celcius. 

<img src="https://user-images.githubusercontent.com/54836827/193809109-d3ca73d5-c401-49b1-bef7-e7e3890f8539.jpg" width=50% height=50%>

A clean soldered connection should have a cone like shape as the wire connects the pin to the board. This cone shape takes up less space and is helpful in make sure there are not shorted connections. Some tips are shared as to how to best clean up any mishapen or extra soldered connection in the final touches section below. Though the board would work with mishapen connections with extra solder that isnt touching any other connection, it is still helpful to make each connection as clean as possible.

<img src="https://user-images.githubusercontent.com/54836827/193810457-34626089-ded3-43cb-afd7-3356fd6040b9.JPG" width=50% height=50%>

One helpful tip for getting the wires flush and as close to the surface of the board as possible is to first establish a loose soldered connection without worrying about how close the wire is to the board. Now that the connection has been made, you can have the iron in one hand and press onto the wire from the back with the other. Reheat the soldered connection to release the wire and then press the wire down towards the board with the other hand. This will solidify with the wire flush onto the board however be careful not to have your hand there for too loing as it will be very hot, as the wire weill conduct heat.

Estalbish the soldered connections of each wire near the analogue pins. Now it is important to connect the wire to the headers. Use the tweezers to bend the wire towards the pins of the soldered down header as shown in the image below. This will make it much easier to establish a clean connection. Then, int he same fashion as the other connections, solder the wire to the pin, thereby connecting the wire to the headers.

<img src="https://user-images.githubusercontent.com/54836827/193811102-96c86e95-861f-49fe-a998-4d391804375b.JPG" width=50% height=50%>

Now that the wires are connected and the motor inputs have a way of being received, the shield must have a way to receive power and be grounded. Wires will have to be run to the 5V and the GND bus, located on the top left of the board. In a similar way, solder the wires that have already been made down in the same fashion as the previous connections. Place the wire and solder down the ends to the bus/ column. Then, bend the excess wire near the headers towards the header pins to ease connection and solder the two together. 

<img src="https://user-images.githubusercontent.com/54836827/193812820-3978f4fc-7431-4b9f-9ca8-737146c12bac.jpg" width=50% height=50%>


**Final Touches**

One final note is to make sure everything is trimmed and flush. Any excess wire poking out (as shown in the image below) should be trimmed down and closer to the board. Any soldered connections that are too wide or have too much solder should be cleaned up. This can be done in a multitude of different ways. One effective way is my using the suction apartus in the transparent ins on your desk. This is used to suck up any excess heated solder. Press down on the top of the suction to engage the equipment. Use the iron the heat up the solder the press the small black button on the front near the middle of the suction apartatus to suck up the solder. Another way is to heat up the solder to take it onto the iron then clean the iron on the wound up steel wool (gold) on the table. These are both effective ways in cleaning up the soldered connections. Make sure there is not excess solder randomly on the board as this could cause unintentionally short circtuits in the future.

<img src="https://user-images.githubusercontent.com/54836827/193810933-24b6b1b0-0124-483e-a8e7-45307b1c3126.JPG" width=50% height=50%>


## Testing the Shield

To test the shield, connect the radio to the board by inserting it into the headers. Make sure it is placed aligned with the correct signal, 5V and GND as expressed previously. The images below show the makeup of the radio as well as the correct placement. Place the shield onto the arduino and connect the arduino to a computer in order to upload the testing code. 

<img src="https://nwzimg.wezhan.net/contents/sitefiles3604/18021148/images/3841491.jpg" width=50% height=50%>

<img src="https://user-images.githubusercontent.com/54836827/193811554-67bf9349-e86f-4f40-8320-ac70bb82e11b.jpg" width=50% height=50%>

Copy the code into the arduino window. Once this is done, read through the code to better understand what it is doing. This code uses a library called "EnableInterupt" which can be downloaded as a library. To do this, click on "sketch" in the top toolbar, open up the manage library feature, then search for and install the EnalbeInterrupt library. The testing code can be found using the link below

https://github.com/michaelshiloh/resourcesForClasses/blob/master/src/arduinoSketches/hobbyRC/minimalMoreChannels/minimalMoreChannels.ino

Make sure to complie the code to make sure everything is working (the circle with a tick) then upload it onto the board. To do this, Click on the Tools feature in the top tool bar and select "AruinoUno" as the board. To select the board as a port to be uploaded onto, in the same Tool menu, open the port selection and select the Arduino Uno. To uplaod, click on the right arrow button next to the compiling tick in the main window. Once the code is uploaded, the arduino and shield is ready to be tested.

To establish a connection between the radio and the transmitter, bring the transmitter (remote) close to the board. Then, press the small button on the back of the board the radio component (as shown int he radio image above). This can be found in an opening at the back of the board and can be reached by pressing it with a thin object like a pen. As you hold it down the green light on the radio will begin to falsh rapidly. Hold down the button until the light stops flashing and stays clearly on. Now the connection has been established.

Open the serial monitor on the arduino app on the computer. This should show 4 different values if the connection has been properly establsihed. As you test the 4 inputs on the transmitter, the value in each respective column should change. The four inputs are

1) Ch1 - Wheel (Trim Lever): Controls Steering/ Directoin
2) Ch2 - Trigger (Throttle): Controls Thorttle/ Power Output
3) Ch3 - VR Knob           : Auxillary (Custom Output)
4) Ch4 - SWA (tact switch) : Auxillary (Custom Output)

With each change in input (pressing or turning), the output reading on the serial monitor will change. Take note of any input that is not causing a change in output on the serial monitor. This would probably mean that one of the soldered connections is faulty and that a reevaluation of the connection is in order. If none of the readings are changing, then it is either that all the soldered connections were not made or the connection between the radio adn transmitter was not established. redo any of the steps accordinly to make sure a proper reading is given. 

If everything functions properly, the radio is now connected and is ready to use.
