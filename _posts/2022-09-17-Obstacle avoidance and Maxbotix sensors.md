*17th September 2022 - Maxbotix sensors research*

# Maxbotix sensors
https://www.maxbotix.com

## LV EZ0 MB1000  1x 
Installed at the front of the robot

**Benefits:**
- Highest sensitivity 
- Widest range

price: 26.95 dollars (new 34.44)

<a href="url"><img src="https://www.maxbotix.com/pictures/sensor_beam/Beam%20Pattern%20MB1000.gif" height="250" width="300" ></a>

## LV EZ2 MB1020  1x
- from the initial observation it is the best fit for our robot
- balance between sensibility, range, size of the object detected and power consumption

price: 24.95 dollars (new 34.44)

<b href="url"><img src="https://www.maxbotix.com/pictures/sensor_beam/Beam%20Pattern%20MB1020.gif" height="250" width="300" ></b>


## LV EZ3 MB1030  2x 
- Lowest sensibility
- excellent side object rejection (not desirable)
- low power consumption 
- *only Large object detection*  (we need even a small object detection)

price: 24.95 dollars (new 34.44)

<a href="url"><img src="https://www.maxbotix.com/pictures/sensor_beam/Beam%20Pattern%20MB1030.gif"  height="250" width="300" ></a>

Initially the sensors were labeled with a wrong number so I changed the label. There is no difference between the sensors by their visual appearance. 


**Warning by maxbotix:
Minimum distance to detect is 15.2cm, not good between 0-15.2cm
Maximum distance 180cm**

**How does an ultrasonic sensor work?**

- Sensors send ultrasound waves to an object, they get reflected and ultrasonic sensors detect them. 
- Time is measured in microseconds, distance in centimeters
- Distance (cm) = [speed of sound (cm/μs)*time(μs)]/2
  - Speed of sound = 0.0343cm/μs (for dry air at 20°C)
  - Is this going to affect the measurement? 
  - Speed of sound depends on the temperature and humidity
  - The speed of sound increases by 0.6 meters per second per °C 
- the sensor should feature internal temperature compensation and automatically calculate the difference and give accurate readings
option of installing another sensor, however, I think since we do not need to calculate precise distance, this is not needed


Additional Resources:
Sample obstacle avoiding robot
https://create.arduino.cc/projecthub/Alfa0420/obstacle-avoiding-robot-using-arduino-and-ultrasonic-sensor-c179bb

Questions:

- How to connect sensors in the most efficient way?
    - Parallel, serial 
- Do these sensors need a movable stand or is it enough to have a stable stand considering these sensors will only measure distances?

*24th September 2022 - Connecting sensors*

**Connecting a single independent sensor**

Sensor Operation
- Analog Output
- Pulse Width Output
- **Serial Output**
  - most suitable
 
![308472249_915875292705933_6893240304914835347_n](https://user-images.githubusercontent.com/94536332/192132208-c6ea6d56-6e5d-4129-8b83-1ca295c3d393.jpg)

**Using Multiple sensors in a system**

Three most common ways:

### AN Output Commanded loop
not suitable: The first sensor will range, then trigger the next and the same for all other sensors in the array, once the last sensor has ranged, it stops until the first is triggered. We need the loop to continously continue to be able to detect the distance for a longer time. 

### AN Output Constantly looping
First sensor ranges, then triggers the other and so on for all the sensors in the array. Once the last sensor has ranged, it will trigger the first sensor and continue in looping. 
This loop could be suitable, however, it is not ideal since we need all the sensors to work at the same time. On the other hand, Arduino works quite fast so this approach could work. It needs to be tested. 

![2022-10-25 11-26](https://user-images.githubusercontent.com/94536332/197710447-3e1e914a-acab-4f8f-b4c9-528842971f4b.jpeg)

### AN Output Simultaneous Operation
This does not work for all applications and it is very sensitive for the positioning of the sensors. Needs to be carefully tested, however, if this one works, it will be the best option. 
All the sensors RX pins are connected to each other and triggered at the same time causing all the sensors to take a range reading at the same time. However, once the reading is completed the sensors stop ranging until triggered next time. 

Questions to figure out:
- Is the reading going to continue when we change the distance by moving the robot with its engine? 
- How to do simultaneous operation in a loop to continue measuring?
- Is there a way how to trigger sensor again after every measurement?

![308194339_616174906886704_6373462202449362368_n](https://user-images.githubusercontent.com/94536332/192133802-4f64d121-d64d-4613-8133-e45687d0a26e.jpg)

*4th October 2022*
## Analog Output Single Sensor
I used the following scheme to connect sensors to the Arduino. I tested the range of the sensors.
![arduino-ultrasonic-sensor-single-lv-maxsonar](https://user-images.githubusercontent.com/94536332/193868742-f8917c03-881a-4466-8c56-fa569ea921e2.svg)

Link to the code:
https://github.com/katynkafialova/Man-or-Machine/blob/1f82bdac29848a3096d5d606d3c35b43a3af2967/Analog%20Output%20Single%20Sensor%20operation 

*30th October 2022*

To have the circuit continuously loop so the chain is always giving an analog voltage output
connect pin 5 of the last sensor in the sequence to pin 4 of the first sensor in sequence
1K resistor in sequence between the pin 5 output and pin 4 input
(4 bands - brown, black, orange, yellow)

### Timing:
number of sensors times the single sensor refresh rate
3 * 100mS = 300mS is the update rate per sensor 
for our robot it will be at least 5*100ms=500mS=0.5 s

Useful references:
https://www.maxbotix.com/Arduino-Ultrasonic-Sensors-085/#wiring  

https://playground.arduino.cc/Main/MaxSonar/  

https://www.maxbotix.com/tutorials1/031-using-multiple-ultrasonic-sensors.htm 


![moresensors](https://user-images.githubusercontent.com/94536332/198890758-5394588a-9234-4b2c-a0c2-3977a235414f.png)

The way how to wire two sensors together:

![moresensors](https://user-images.githubusercontent.com/94536332/198890825-769473ab-132e-420d-9f44-1c0355b48749.png)

Code to run Multiple Sensors in Continously looping circuit 
two sensors:
https://github.com/katynkafialova/Man-or-Machine/blob/0de71d7de29b9400baf47c928b856461b8fa4d7c/Multiple%20Sensors%20Analog%20Voltage 

three sensors:
https://github.com/katynkafialova/Man-or-Machine/blob/129adec68176fe22e00db9889c9f4eeb0fcbb0fe/Multiple%20Sensors%20Analog%20Voltage%203 

Overall, the sensors are working, however when connecting together as three sensors on one breadboard it gives one odd value. I would like to consult this because I might be doing something wrong. Also it might be that I am connecting the last sensor differently than it is supposed to be because it is a different type of sensor. If this issue gets solved, I think we are ready to install the sensors to the robot. We will probably need at least one or two more sensors for the robot to fully work. 

*3rd November 2022*

After consultation with Michael I corrected the circuit and now all three sensors are working together. Here is the schema of connections of sensors to arduino. The code used is the one above for three sensors. 

![scketch](https://user-images.githubusercontent.com/94536332/199817412-4124bf0c-07ac-4d28-a6db-9a0325f99e67.jpeg)

Question to think about: 
### Are maxbotix sensors the most suitable for our robot? 

1. The range is not detected below 6 inches but after experimenting with sensors I noticed it is more likely 8 inches 
2. There could be an alternative that can detect very short distance (the closest is 2 cm) - Ultrasonic Module HC-SR04 Distance Sensor For Arduino, cost 15 dirhams 
3. However, our robot is quite large so the precision of 20 cm should be fine? 

*6th November 2022*

I successfully connected three sensors on two different breadboards. The system is ready to be installed to the robot. 

For the reference the schema of the circuit:

![2022-11-06 15-42](https://user-images.githubusercontent.com/94536332/200168689-f7b39cd7-3e6f-447e-98c3-b7b623fc7e69.jpeg)

And the real image of the sensors connected:

![IMG_5779](https://user-images.githubusercontent.com/94536332/200168846-851ad5dc-2d62-4b3d-8e56-d52c79087924.jpg)


*5th December 2022*
Three sensors were attached on the robot on a rotatable mounts in the front part of the construction. 

![image0](https://user-images.githubusercontent.com/94536332/205699790-fe6464f3-5345-417f-ba39-1aa4c8c46da0.jpeg)

The wires were connected to the 
![image](https://user-images.githubusercontent.com/94536332/205700320-81ae74a6-a105-4ebe-af7a-d3a03fca18ca.png)

