# Aalya's Prototype Shield Documentation

## Step-By-Step Tutorial

### Brainstorming & Establishing Requirements

Before we get into the physical work of connecting and soldering everything on the prototype shield, we must first understand where everything goes. In this particular case, we are working with a radio that will be recieving transmissions. The radio itself consists of three main elements: a row that connects to power, a row that connects to ground, and a row that for the signals in the radio. That means that we are going to need 3 rows of header pins connected to the board: a place for the radio to connect to. You can find an image attached below in order to get a clearer understanding. You can see the bottom row (the far left on the screen) is dedicated to the signal. You can see the channels are labeled from 1 - 6. Next, the middle row is labeled positive, meaning it needs to be connected to 5V on the arduino. Finally, the top row (far right on the screen) is dedicated to ground, which is what it needs to be connected to on the arduino. 

<img width="355" alt="Screen Shot 2022-09-18 at 8 51 11 PM" src="https://user-images.githubusercontent.com/70956039/190919188-da48097f-de2b-496c-bf5a-d9bd88e72865.png">


Next, we need to think of the wiring. What pins should connect to what element in the radio? In this case it was rather simple to figure out. As mentioned, we must have a row connected to 5V and another connected to ground. In that sense, we did not have to make many deisions. We just needed to properly wire the correct row to the correct bus on the prototype shield. As for the last row, the one dedicated to the signal, we have to think of what would be the most convenient. 

### Soldering Process

### Final Result

### Testing the Shield
