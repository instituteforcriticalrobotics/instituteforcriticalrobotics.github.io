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

![308395700_2255833637902672_2317292943274531609_n](https://user-images.githubusercontent.com/94536332/192133779-c3e1115c-d9f2-4eb4-b1ae-b17834d7c152.jpg)


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
