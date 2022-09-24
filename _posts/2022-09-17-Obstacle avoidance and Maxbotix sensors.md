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

*24th September 2022 - Connecting sensors*
