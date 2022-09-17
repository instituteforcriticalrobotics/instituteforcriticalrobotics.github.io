- Evaluate Performing Robots Kit (skills: electronics)
	- Build 7 prototyping shields for radio receivers
	- Test using Serial.println()
	- Wire 14 motors to the L298 motor driver and to the Arduino
	- Test (along with 6 other people) 
		- Each motor can be controlled 
		- No other radio interferes with or controls your motors
- Research, implement, and test “good enough” localization for a robot
	wandering around the corridors of C3 (skills: research, coding)
	- I had a research assistant last year who started on this so the first
		thing would be to look at her research (I have a link somewhere and she is
		on campus so we can talk with her too)
	- The robot doesn’t need to know precisely where it is, just generally which
		direction it’s headed and how far it is from my office. Goal is to keep
		robots within a certain radius of my office
	- Here are some resources that seem promising although I haven’t read (or
		watched) them all:
		- https://www.youtube.com/watch?v=1e5mLdjoKrc Building a self driving car
		- https://arxiv.org/abs/2208.02063 Evaluation and comparison of eight
			popular Lidar and Visual SLAM algorithms (SLAM = Simultaneous
			Localization and Mapping)
		- https://msadowski.github.io/basic-sensors-for-mobile-robots/  IMUs and
			LiDARs - Not Uncommon Pitfalls (IMU = Inertial Measurement Unit which
			typically consists of gyroscopes and accelerometers, LiDAR is a distance
			measuring sensor using the time light takes to reflect off the target)
		- https://www.internalpositioning.com/ localization by measuring signal
			strength (which roughly correlates to distance) to WiFi routers or
			Bluetooth devices. I assume you need to know where these WiFi devices
			are. Probably the simplest to get started with
		- https://github.com/MIT-SPARK/Kimera SLAM library
		- I don’t think that GPS is a viable option but in case all others fail,
			here’s a place to start:
			https://learn.sparkfun.com/tutorials/what-is-gps-rtk
		- https://www.a1k0n.net/2021/01/22/indoor-localization.html indoor
			localization by looking at ceiling lights
- Implement obstacle avoidance on an existing robot (skills: electronics,
	coding, mechanical)
	- I already have high quality ultrasonic sensors 
	- Your research might suggest other sensors, such as LiDARs, that I should
		buy
- My robot Man or Machine needs some mechanical work (skills: mechanical,
	design)
	- Design and make a head that matches the material, aesthetic, and
		dimensions of the body
	- Design a way of attaching the top and bottom of the body to the uprights
		(currently a very ugly bracket)
	- Finish the video conferencing software (skills: coding in Javascript) for
		the telepresence robot
		- Figure out why we audio does not work
	- Implement interface to Arduino for navigation control
- Design and build my website (skills: web design, writing, and maybe video
	creation). Must be done using open source tools such as Github Pages. Jack
	has been giving workshops for this.
- Other tasks will no doubt suggest themselves
