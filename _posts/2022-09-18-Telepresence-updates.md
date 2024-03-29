# Amina's updates on the telepresence robot

# April 1-9: Updates

## Summary and my conclusion:
It is most optimal to wait until we get a stable Ubuntu to install latest updates and software needed for connection. Current Raspi software is unable to install latest software due to network issues that can be easily resolved with the IT's virtual machine. Virtual machine will also allow us to test the webRTC software easier by resolving the HTTPS issues.

<img src="/media/april-errors.png">

## Tasks performed
- [x] Met with Michael to submit the IT form
- [x] Shared wifi links with Ahmed to setup on new Raspi
- [x] Updating my raspi for new software since I haven't updated it in a while (`sudo apt-get update` + `sudo apt-get upgrade`)
  - Faced some errors when upgrading, so had to run `sudo apt-get upgrade --fix-errors`, but that also resulted in a lot of `failed to fetch...` warnings and errors. Perhaps this can be resolved once we have our virtual Ubuntu with a server/domain?
- [x] Brainstorming ways around testing audio connection

Remaining to-do:
- [ ] Check on SSL status since installing it on the domain
- [ ] Start preparing instructions for the handover to next student
- [ ] Start brainstorming on ways around new website frontend!

## Mar 31: Updates
- [x] Followed-up with Michael and IT regarding the space requirements for hosting. Waiting for the IT response
- [x] Got some tasks around servers on Linux and resolving audio on RasPi. Will get started with that over the weekend
- [x] Will update my hours for Ramadan to be weekends/late evenings  

## Mar 6: Backend Updates
- [x] Generated (for the 1000th time -- let's hope it really works this time!) the CSR files for the domain
- [x] Sent activation request for the SSL; Michael will receive confirmation details via email
- [x] Working with the IT team to register domain on the DNS  

## Meeting with IT notes regarding the DNS and hosting:
- They provide hosting services with their DMZ (not sure what this stands for);
- These services can use the domain name we've registered `instituteforcriticalrobotics.org` and provide more security. In summary: we will be outsorcing the networking tasks to them;
- Can be hosted on Windows, MacOS, or Linux. I mentioned that Linux is preferred;
- They asked about memory, RAM, and CPU requirements. I mentioned this will depend on the projects that the ICR decides to host. Michael, what are your thoughts on this?
- If additional services like SQL, more space, etc. is required, we can let them know.
- They will send us a follow-up email with their fees etc. I think this is a very safe bet compared to hosting services online, because it is in-house (NYU) and provides additional security/maintanance for less fee.

Nexts steps:
- [ ] Wait for the SSL activation
- [ ] Follow-up with IT with our preferences for hosting/DNS
- [ ] Start testing!

## Mar 1-3

- [x] Bought the domain name `instituteforcriticalrobotics.org`
- [x] Contacted IT to register on DNS
- [x] Reverted all the SSL (self-signed) mainpulations on local repo to start from the blank state with a registered SSL
- [ ] Currently waiting for the response from IT to start moving the website and the codebase files to the new domain  

## Feb 27

To make HTTPS connection work: need a domain name. Ask Michael if OK with getting an ICR domain (like `icr-nyuad.com`?) Costs around $10 per year on `namecheap.com`. Can purchase myself and ask for reimbursement.

This way, can install SSL certificate and proceed with testing. Otherwise, it is very difficult to tell if mic/camera can be accessed through external connections to the server. But I am figuring this out. Will come with updates.

## Feb 13

Troubleshooting day...Notes:
- Camera starts acting up if CSR is in the git directory
- Audio issues can be because of:
  - Microphone Permissions: The getUserMedia() API requires user permission to access the microphone. If the permission is not granted, the API will not work.
  - Microphone Hardware: Ensure that the microphone is properly connected to the Raspberry Pi and is working correctly.
  - Browser Compatibility: Different browsers may have different support levels for WebRTC and getUserMedia(). Try using a different browser to see if the issue is resolved.
  - Operating System: Check to see if the operating system is compatible with WebRTC and has the necessary libraries and dependencies installed.
  - WebRTC Library: Ensure that the WebRTC library being used is compatible with the Raspberry Pi and has been properly configured.
- What I suspect is happening is that because there is no constant audio connection (only earphones), Pi does not read a source of audio input/output, which breaks getUserMedia(). I should confirm it next time.
- And I am still trying to figure out what is wrong with the SSL installation. Purchasing a domain might be a solution, but there could be a workaround that I am not seeing for testing purposes!

## Feb 12

- [x] Updated and re-generated CSR certificate
- [x] Tried to enroll in the certificate activation, and... 

I just keep running into hurdles! I got one step closer to enrolling the SSL certificate, but another hurdle is "invalid domain name in your CSR". And this is because the domain at the moment is the IP address of the Raspberry Pi.

<img src="/media/new-error.png">

I am trying to zoom out a bit to remind again why all of these steps are needed:
1. A person opens up a website online to get access to the robot
2. Robot initializes video and audio signals through webRTC
3. A person can move the robot and also be shown on the robot's page

What is missing right now:

`A person opens up a website online to get access to the robot`
- [ ] Remote streaming on webRTC
  - [ ] For remote streaming to work, we need HTTPS. For HTTPS, we need SSL. For SSL, we need domain name.

`Robot initializes video and audio signals through webRTC`
- [ ] Audio works on non-Raspberry Pi devices. Find a way to connect to Audio on Pi 

`A person can move the robot and also be shown on the robot's page`
- [x] Is able to receive Serial signals from the web page. This is the least of our concerns as of now.

It seems like the progress is slow and we're taking 1 step forward and 3 back. But it's a complex task, so the solutions also take more than expected.

## Feb 8

- [x] Installed an apache packages `sudo apt-get install apache2` and `sudo apt-get install apache2-utils`
- [x] Generated CSR doc to generate the SSL certificate that Michael purchased
- [ ] Ooop..a hiccup from the server? It seems like SSL generator could not go through, so I am investigating why.

<img src="/media/hiccup.png">

## Feb 6

- [x] Cloned forked branch of the webRTC repo with serial communication
- [x] both `8080/robot` and `8080/` pages work from Pi
- [x] ensured that SSL/safe connection is what I need to proceed to next stage

Here is another suggestion on a potential workaround:

`Alternatively, you can set up a reverse proxy, such as NGINX, to act as a secure endpoint for your Raspberry Pi server, which would allow you to access the server using a URL that starts with "https."`

Here are the instructions generated by ChatGPT on installing NGINX:
````
Setting up a reverse proxy using nginx involves the following steps:

Install nginx: You can install nginx by running the following command in the terminal:
sudo apt-get update
sudo apt-get install nginx

Configure the nginx reverse proxy: You need to create a configuration file for nginx in the sites-available directory.
sudo nano /etc/nginx/sites-available/reverse_proxy.conf

In the file, add the following code:
server {
listen 80;
server_name my_domain.com;
location / {
proxy_pass http://your_nodejs_app_ip:port;
proxy_http_version 1.1;
proxy_set_header Upgrade $http_upgrade;
proxy_set_header Connection 'upgrade';
proxy_set_header Host $host;
proxy_cache_bypass $http_upgrade;
}
}

Create a symbolic link in the sites-enabled directory:
sudo ln -s /etc/nginx/sites-available/reverse_proxy.conf /etc/nginx/sites-enabled/

Test the configuration and restart nginx if there are no errors:
sudo nginx -t
sudo service nginx restart
````

## Feb 1

Working around SSL certificate to access the website using IP address on Pi. A temporary worka around this is using a self-trusted SSL certificate, which is what I will do now to see if that solves the issue.

OK, tried the self-signed certificate, but the server proceeded to give the following error: `"ERR_SSL_PROTOCOL_ERROR"`. The best solution in this case seems to purchase the certificate, as we cannot advance without it. Hence have to stash self-signed certificate changes and ask Jack/Micahel for SSL certificate purchase.

Price: $5.99 per year for a total of 5 years bundle (https://comodosslstore.com/promoads/cheap-comodo-ssl-certificates.aspx?gclid=CjwKCAiAuOieBhAIEiwAgjCvcnxuD2VlyTwAL_dCjapV6NNKWZf5jnDLMZtU5MO54vxbrLZgMXh5HBoCN5YQAvD_BwE)

````
const https = require('https');
const fs = require('fs');

const options = {
  key: fs.readFileSync('path/to/private.key'),
  cert: fs.readFileSync('path/to/certificate.crt')
};

const server = https.createServer(options, (req, res) => {
  // Your server code here
});

server.listen(443);

````

## Jan 30

Camera works! I am able to now connect to `localhost:8080/robot` page on raspberry pi.

The issue was: audio has to be (temporarily) disabled due to lack of microphone on raspi. I anticipate that with microphone connection both will work.

To resolve: access to `localhost:8080/` from different device. Cannot reach it from other devices, as of now. Might be due to the SSH certificate thing. Will look into this now.

Issue: I can run `:8080/robot` from my mac and connect to `:8080/` from my devices, but not from Pi. Similarly, I can run `:8080/robot` on Pi, but cannot connect using `IP:8080/` from my devices. Will need to try running `:8080/robot` from Chromium on Pi and connecting to `:8080/` from another browser.

## Jan 28

To log into the wifi, go to: ````1.1.1.1````

- [x] ran `sudo apt update` and `sudo apt upgrade`
- [x] downloaded `npm` and `nodejs` to current raspi
- [x] got raspi and codebase state to the point before the last crash!!! woohoo 🥳

Now figuring out the webcam + mic connection to get the media streams:
- installing kernel camera drivers (reason why camera isn't working)

````
If you have verified that the physical connection is correct, it is possible that the camera module is not compatible with the version of the Raspberry Pi you are using or the operating system.

It is also possible that the camera is not supported by the version of the Linux kernel you are using, or the driver is not properly installed.

You can try updating the OS or the kernel version, and see if that resolves the issue. But make sure that your camera is compatible with the new version before updating.
````

## Jan 25

- backing up Raspi to a new 16 gb microSD card
- encountering issue when connecting to wifi "radius connection not found. please contact help desk for assistance"

goals:
- connect to wifi
- download the codebase

## Jan 23

Happy 2023!

- met with Michael and Katarina today
- outlined goals for the semester

## Dec 8
- Trying to solve the issue caused by interrupted running of `rpi-update` from last week
- No progress

## Dec 4
Help! After attempting to run `rpi-update` to install some of the libraries for webRTC, the Pi is unable to connect to any network (shows `No wireless interfaces found`). So I googled the issue and attempted to run a few other commands, including downgrading to previous firmware and messing with the network settings. However, nothing worked and now I get errors when trying to perform any command on Pi. Any solutions?

Learning: DO NOT use `rpi-update` as it has unstable software and messes with your Pi...

````
WARNING: Pre-release versions of software are not guaranteed to work. You should not use rpi-update on any system unless recommended to do so by a Raspberry Pi engineer. It may leave your system unreliable or even completely broken. It should not be used as part of any regular update process.
````

## Dec 3
- Connected the web-camera -- thanks Michael for kindly providing the camera!
- Downloaded the `fswebcam` module to Pi, took a picture, and the computer froze right after that...Had to reboot. Here's the camera output:

<img src="/media/image.jpg">

Additional steps taken to test the camera according to the [instructions](https://www.highvoltagecode.com/post/webrtc-on-raspberry-pi-live-hd-video-and-audio-streaming):
- Enabling camera in config on Pi

Currently debugging:
- getmediastream does not recognize camera on raspi
- for a solution, check: https://stackoverflow.com/questions/28556402/webrtc-on-raspberry-pi
- follow these instructions to install UV4L, which is required to run webRTC from RasPii: https://www.linux-projects.org/uv4l/installation/

## Dec 2
- Re-registered for the guest wifi (use registration code: 28112). This is only valid for 7 days and needs to be renewed unless a permanent solution is found.
- Found that the USB path to arduino indeed is `/dev/ttyACM0`.
- Fixed serial communication! Tested that communication between RasPi - Arduino works and is ready to be programmed further ✅
- Node server is up and running from RasPi

Pending tasks:
- Get a USB camera to test the media stream
- Work with Alia for a permanent network solution

<img src="/media/arduino.gif">

## Weekly Update <Nov 20 - 27>
- Got a temporary workaround for networks (WiFi works)
- Downloaded the Repo and testing the code files
- For more details and next steps, please refer to the documentation below:

## Nov 27
- Cloned webRTC repo into the Pi computer
- Updated OS by running `sudo apt update` and `sudo apt upgrade` (took some time!)
- Installed node and npm
- Downloaded the codebase (finally!)
- Tested the server

Known problems:
- USB connection upon starting the server isn't detected.
  - Solution: Determine the value for `/dev/ttyACM0` (except that it's not ACM0 in this case -- find why)
- Serial connection not working.
  - Solution: See above. As soon as the port name is known, the connection will be working.
- No media stream is set.
  - Solution: Connect a USB camera and a microphone.

<img src="/media/no-media.JPG" width="400">
<img src="/media/which-usb.jpg" width="400">

## Nov 24

### Happy Thanksgiving! 🍁

Still a problem: **wpa_supplicant.conf Changes Disappear**
Temporary solution: internet enabled with the nyuadguest network.

Steps taken today:
- Upon testing a few commands and rebooting Raspberry Pi, it seems that SDCard removal is not necessary, because it is **not** read-only. I can indeed write, store, and update files on it. Just not the WiFi config for some strage reason. I am still investigating that.
- Emailed NYU IT to get additional help. 
- Tried also changing `update_config=0` from `update_config=1` (command that is presumably responsible for updates and overrides) but that change also got wiped out after a few seconds. Source: [this thread](https://raspberrypi.stackexchange.com/questions/105537/wpa-supplicant-conf-changes-disappear).
- Turned WiFi off completely and re-did the commands. Seems like it is not wiping out while the WiFi is off. Whenever I turn WiFi back on, the changes are wiped out...
- Proposed solution by NYU IT team: connect to nyuadguest AND abu dhabi VPN.
- IT helped connecting to guest and whitelisted the Pi's IP/config address.

## Weekly Update <Nov 13-20>
- Installing networking to RasPi
- Testing several connection methods
- Debugging with Alia and Jack

Planned for next week:
- Tuesday, one more try with Alia
- If all fails, ask Michael for help

## Nov 20

Troubleshooting Day 3...

What happens:
1. I append the NYU network to the `/etc/wpa_supplicant/wpa_supplicant.conf`, which briefly appears on the networks list when opening the same file. However, after a few minutes, the network dissapears from the list, if the changes have not been made/saved!
2. Tried to add the NYU network with the `add_network` command in `sudo wpa_cli`, but similar happens as in (1): changes are reflected for a moment, and then go back to previous state.

Could this be because of the file writing permissions? Even with sudo, the changes are clearly limited. 


## Nov 19

### Troubleshooting and trials continue...
- Rebooted RasPi to see if the network has been updated
- Re-followed the instructions but to no success
- Scheduled a meeting with Alia for tomorrow (Sunday, Nov 20) to connect to network

## Nov 18

- [x] Tried to connect Raspberry Pi to the NYU network through the terminal. 

I followed Jack's instructions documented in [his blog](https://jackbdu.wordpress.com/2017/04/01/interactive-media-arts-capstone-technical-documentation/). First, I hashed my NYU password and then added a vim command with my network authentication for NYU wifi, however that did not seem to make any difference on the network options on RaspPi.

<img src="/media/commands.JPG" width="400">
<img src="/media/vim-text.JPG" width="400">
<img src="/media/no-wifi.JPG" width="400">

Focus for next time:
- Debug networking (follow up again with Jack)
- Download codebase to RasPi
- Run server form RasPi if above two go successfully

## Nov 17

- [x] Got the network information from Alia.

Look into this for connecting to wifi:
- https://jackbdu.wordpress.com/2017/04/01/interactive-media-arts-capstone-technical-documentation/
- https://tolotra.com/2018/07/22/how-to-solve-no-wireless-interface-found-on-a-raspberry-pi-3/
- https://forums.raspberrypi.com/viewtopic.php?t=211383#p1304765

## Nov 11 + Weekly Update

Side note: I've been away this weekend, so will aim to catch up on work next week.

### Advancing SerialPort Communication

Next steps:
- Decipher commands from the Arduino's side. I.e. differentiating between "go left" and "go right". That can be as easy as cathing the appropriate Serial Port command. I will have to figure that out. Is 9600 baud optimal for this?

### Moving to Linux and Raspberry Pi

The main priority for today was moving wires and the codebase to Raspberry Pi. I was successfully able to wire up the microphone and the Arduino (image below), and will be exchanging the Raspberry Pi camera that I checked out from the IM Lab to a USB camera, so that the audio and video connections work better. 

<img src="/media/wires.JPG" width="400">

Although wiring was done with no problem, I couldn't reach GitHub because of the network issues on Raspberry Pi. Eduroam and NYU wifi's are unavailable for connection, which is why I cannot access certain websites, such as GitHub, to download and test the codebase. Any tips on how to work around this?

<img src="/media/network-issue.JPG" width="400">

## Weekly Summary <Oct 30 - Nov 6>

- [x] Installed SerialPort npm library for Node
- [x] Successfully tested Node - Arduino communication (see documentation below) 
- [x] Modified codebase and pushed changes to the main!

Focus for next week:
- Change the microphone cable in the IM lab (previous one didn't work)
- Test code on Linux (same code should work, according to SerialPort documentation)
- Test complex Arduino commands if all successful

## Nov 6: Testing Arduino <-> Node communication

Arduino code and help is taken from [this wonderful ITP tutorial](https://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-serial-control-of-an-arduino/).

#### Step 0: Preparing Node (this is done from the day before).

````
const { SerialPort } = require('serialport');

// Create an Arduino port
const port = new SerialPort({
  path: '/dev/cu.usbmodem14201', // change this depending on Raspberry Pi port: /dev/ttyACM0
  baudRate: 9600, // change this depending on Raspberry Pi baudRate
});

function sendToArduino(message) {
  port.write(message, function(err) {
    if (err) {
      return console.log('Error on write: ', err.message);
    }
    console.log('message written: ', message);
  });
}
````

#### Step 1: Preparing the Arduino:

````
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char input = Serial.parseInt();
    // use the value of the incoming byte to control the LED's brightness:
    analogWrite(LED_BUILTIN, input);
  }
}
````

#### Step 2: Send commands when pressing buttons from the website.

````
switch (path) {
    case '/1':
      // goes front etc.
      console.log("Go left");
      sendToArduino("1");
      break;
    case '/2':
      // goes front etc.
      console.log("Go forward");
      sendToArduino("2");
      break;
    case '/3':
      // goes front etc.
      console.log("Go right");
      sendToArduino("3");
      break;
    case '/4':
      // goes front etc.
      console.log("Go back");
      sendToArduino("4");
      break;
    case '/5':
      // goes front etc.
      console.log("Stop");
      sendToArduino("5");
      break;

````

#### Step 4: Watch the results!

Successful testing -- the built-in LED blinks when sending communication from Node. 

![Successful message send from server to serial](/media/node.png)

## Nov 5: SerialPort for Node.JS

Used [this guide](https://serialport.io/docs/guide-usage) to help in installation process.

After installing the SerialPort npm library, modified code to read from the Arduino port and transfer information:

````
// Create an Arduino port
const port = new SerialPort({
  path: '/dev/cu.usbmodem14201', // change this depending on Raspberry Pi port: /dev/ttyACM0
  baudRate: 9600, // change this depending on Raspberry Pi baudRate
});

port.write('main screen turn on', function(err) {
  if (err) {
    return console.log('Error on write: ', err.message);
  }
  console.log('message written');
});

// Open errors will be emitted as an error event
port.on('error', function(err) {
  console.log('Error: ', err.message)
})
````

[From ITP tutorial](https://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-serial-communication-with-node-js/): "The serialport library, like most node.js libraries, is event-based. This means that when the program is running, the operating system and the user’s actions will generate events and the program will provide functions to deal with those events called callback functions."

And it looks like the message is going through:

![Successful message send from server to serial](/media/serial.png)

The next step is to make sure that Arduino is receiving this message. This can be tested through LED connection. 

### Question:
As I am unable to view the Arduino's serial window, how do I check if Arduino received the messages from the server? 

## Nov 4

- Watched a video on raspi and arduino communication. Questions:
  - Does the communication only work via Python? In the video and other resources, the communication always seemed to use Python.
- Q: How to wire up raspi and arduino? After that will be a part of starting a server from raspi
- Installed SerialPort Nodejs npm library. More info: https://www.npmjs.com/package/serialport 

## Nov 3

### Priority task:
1) Start up the node server from RasPi
2) Read web commands to be fed to Arduino
3) Transmit web commands from the RasPi server to Arduino

Done:
- read through serial communication: https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/#:~:text=The%20easiest%20way%20is%20to,Arduino%20IDE)%20to%20your%20board.

To watch:
- https://www.youtube.com/watch?v=3QSsnnbJYFc&ab_channel=ElitheComputerGuy


## Oct 24th-30th Weekly Update:

I've spent the majority of the time this week working on understanding SSL and networking for webRTC. To install SSL, we need to purchase a certificate to be used on both client and server when transmitting data through getUserMedia() function used in webRTC. Without HTTPS connection and SSL that is required for that connection, the two-way interaction process will not be possible. The next step would be to purchase an SSL certificate to establish safe connection.

This makes me consider 2 independent things:
1. Do we want webRTC to be used as a primary way of two-way interaction? I understand this codebase was first created in 2017-18, during the times where digital tools like Zoom and Google Meet were not widely accessible. If we eliminate the problem of two-way connection by using a third-party video conferencing and focus just on transmitting Arduino commands to Raspberry Pi, will this still be helpful in the research? Or does it break the initial intention of using webRTC?
2. My progress with figuring out network connections is rather slow due to my understanding of the topic and my own schedule this semester, i.e. I spent the majority of the time I have on understanding the theory instead of problem-solving. I anticipate getting more time this J-term and Spring 2023 semester, with grad school applications and the majority of the Capstone being out of the way. While I am also waiting on external help with networking, is it a possibility for me to temporarily switch to the website-building pending task from the [ICR to-do list](https://instituteforcriticalrobotics.github.io/2022/09/16/Task-list.html)? I feel confident about finishing a personal website for Michael in the remainder of the semester and do not anticipate any heavy technical blockers with this. Let me know if this is something you/ICR team can consider. Of course, I will still try to figure out networking for webRTC, and hopefully this will be resolved in the next few months.

## Oct 30 Summary

### Helpful instruction on installing SSL on Linux
- How to install SSL connection on [Ubuntu](https://www.filecloud.com/supportdocs/fcdoc/latest/server/filecloud-administrator-guide/installing-filecloud-server/post-installation/ssl-configuration/use-ssl-on-linux/install-an-ssl-certificate-on-ubuntu)
- How do we purchase an SSL certificate? That would be the next step.

## Oct 28 Summary
- [x] Watched SSL video explanations https://www.youtube.com/watch?v=SJJmoDZ3il8&ab_channel=dtommy1979 and https://www.youtube.com/watch?v=33VYnE7Bzpk&ab_channel=SunnyClassroom
- [x] Found this as a proof of Jack's hypothesis from last time: https://stackoverflow.com/questions/41922515/webrtc-video-streaming-doesnt-work-through-http
- [x] webRTC x HTTPS findings: https://stackoverflow.com/questions/43901648/webrtc-over-https-issue  

- Ask Michael: is there a particular reason why we don't use Zoom or Google Meets for this project? If third-party video-audio connection is used, can arduino commands live on a separate website? Trying to gauge the optimal way to solve this.
- Slowly progressing, will work on this a bit more in-depth over the weekend! 

## Weekly Update
- Debugging in progress:
  As of now, there are two identified issues:
  1. An HTTPS connection is required for a two-way interaction when testing
  2. Client media stream sharing isn't sending data as expected
  If I get time during Fall break, I will look into #2. Otherwise, I will get back to it after Oct 23rd.

## Oct 13 debugging with Jack:

Summary: there are two separate problems
1) with HTTPS (localhost + non-local connection won't peer connect to each other even if the code is perfect)
2) because http://10.225.22.40:8080/ doesn't work by itself (outside of localhost), there's definitely sth wrong with the codebase. I am looking into this now

Other discussed points:
- how do we know it's creating the offer on the server? if the video is shown, then probably the call is going through?
- https secure connections may impact // look into hosting in https // get a license, can do both locally and raspi
- install ssl license https://www.thesslstore.com/knowledgebase/ssl-install/whm-ssl-installation/

Investigation notes:
- As determined from the codebase, robot sends the video data, but client never shares their video/audio data. Hence we're not able to pull up the client video/audio. The next step in solving this would be to get the client share this data, but that would only work in a safe HTTPS connection. See notes from above for details on how to set this up.

## Oct 9 debugging:
- Stuck, ouch! Cannot find a way to output client video on a robot's side. Watched multiple tutorials, but get lost in actual implementation in the existing codebase. Tutorials seem to use different/potentially updated formatting in webRTC and I don't understand how to map to our state. Perhaps it's time to ask for help from Jack.

## Oct 7 updates:
- Created separate CSS file for storing the styles and refactoring the code to maintain standard web dev coding practices.
- Refactoring HTML to show both videos and having options to see the client name and if they wish to mute audio/video.

## Oct 6:
- Requested necessary equipment for raspi testing from the IM Lab. Pickup available on Oct 10th (no earlier slots). The return time is on Oct 13th -- is it possible to extend for research purposes? 
- Still slightly confused about server connection on raspi. So questions for me to research/answer:
  - Starting a server on raspi from Node
  - Reading from a server on raspi
  - Requesting audio connection from client to output on robot -- how is this feasible with webRTC? Lookup tutorials and test.

Client audio/video setup:
- testing two-way connection but to no success yet; debugging and researching best connection options.
- do we want to make that available by default or give the user an option to choose?
- I am tempted to follow a tutorial for establishing a two-way connection since it seems clearer than the existing setup...

Focus for next time:
- debugging two-way connection
- collect camera and microphone for raspi
- raspi network connection
     

## Oct 4 Goals Updates:
- Two-way interaction between server and client:
  - right now client sees and hears the robot; but robot can't see and hear the client.
- Raspi connection to server and testing from raspi directly, rather than locally.
- Raspi receiving arduino commands and responding to them.

## Oct 1 Summary:
- Browsing information about raspi and sockets; so the goal is to make raspi read from the server or to start a server on its own?
- if it starts a server, then it needs socket programming; [this video is a good example](https://www.youtube.com/watch?v=QihjI84Z2tQ)
- correct if my understanding is wrong: robot (raspi) starts the server; client connects and sees the video and audio with webRTC; client can press buttons and that will trigger raspi to respond by sending info to arduino.

## Sep 29 Summary:
- Discovered that on the client's side audio was muted; enabled it.
- Do we need the audio to play on the robot's side? Disabled it on robot but in a way that still plays on client.
- Testing continued with Aalya!
- Now that's audio is fixed, figuring out the server situation on Raspberry Pi. Helpful links found:
  - https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/
  - https://ljvmiranda921.github.io/notebook/2017/02/21/send-data-from-rpi-to-server/
  - https://www.instructables.com/Connecting-Your-Raspberry-Pi-to-the-Web/
  - https://www.youtube.com/watch?v=Kt5_9h84CrQ
  - https://stackoverflow.com/questions/22036754/send-data-from-raspberrypi-to-webserver - this looks kind of helpful
- Question to Michael: what do you mean when one presses "stop"? Stop the motors from running? Pause the video? Exit from the web-page?
- TO-DO:
  - [ ] raspi connection to server and then to arduino
  - [ ] fix UI/UX after improved functionality
  - [ ] clean up the code into functions

## Sep 27 Summary:
- Good news: the audio now works on the robot's side -- do we need this? Should the audio only work on the client's side? Investigate that further.

## Sep 25 Meeting notes:
- Check with Alia Waleed on last semester's codebase for network connection
- Completed the Raspberry Pi setup on the computer
- Merged pull request
- Continue with debugging and meet in two weeks

## Sep 24 Summary:
- In webrtc.js there indeed was a line (75) that never asked for microphone permission! I will toggle the audio to true and see what happens.
  - Created a pull request with changes -> ask Michael to invite me as a collaborator to the repository. Otherwise, I am unable to test the changes.
- Was able to progress in understanding a bit thanks to this [video](https://www.youtube.com/watch?v=WmR9IMUD_CY). However, still don't understand the receiver/client/non-robot part of the video -- need to dig deeper through the codebase.
- Question to Michael: can there be more than one client/non-robot interactor? If so, how would that be ensured? Right now it seems like anyone can join and take "control" of the Arduino. What if there are conflicts?
- What is the difference between [this telepresence repository](https://github.com/michaelshiloh/telepresence) and [this with webRTC](https://github.com/michaelshiloh/webRTC)? The first one is the one with Python code.
- As far as it seems, pressing on buttons doesn't work because they aren't really connected to the Arduino code. In the backend, the button commands aren't linked with Arduino-specific commands, so that's why we get the error message. To fix this, we need to define these commands in the backend and link the code/codebases.

## Sep 22-23 Summary
- Checking if the website uses microphone:
  - so the website asks for the video permission in the beginning, but never does so for the microphone, so it's never initialized. this is why (my guess) we hear no audio (see screenshot attached). But this doesn't seem to resolve it.
- here's what I found as well "you need to open and forward UDP ports 9100-9199 to the pbx in firewall/router for the audio." (https://www.3cx.com/community/threads/webrtc-no-audio.40818/)
- A lot of [workarounds/fixes](https://community.asterisk.org/t/asterisk-16-4-webrtc-no-audio/83624) for audio involve diving into SIP trace / server / http config settings. I have little understanding of this, so perhaps should schedule some time with Jack to see if I can get help
- "All WebRTC clients are inside local network, so ICE isn't needed here. But the bad way - ICE is the problem here. I've made a lot of tests and found that if call initiator is Web RTC client and there is some delay in answer (10-25 seconds) - audio is completely absent. Also in this case in RTP debug can be seen than "sent RTP packet" doesn't have "via ICE" mark. But when call initiator is any SIP client (X-Lite, Ekiga, etc) - WebRTC works perfectly. And the answer (as I think) is in rtcp-mux - wich can't do Asterisk but Sofia (SIP library for FreeSwitch) can"
- Should I follow a new tutorial to replicate this?

## Sep 20 Summary
- [x] Tested video output with home-setup
- [x] Researched JS and HTML documentation for sound output [here](https://developer.mozilla.org/en-US/docs/Learn/HTML/Multimedia_and_embedding/Video_and_audio_content). Continue looking more into this next time.
- [x] Looked into sound changes in the codebase -- all looks fine 
- [x] Planned for debugging and sound testing with non-webRTC video

Focus for next time:
- Ask if audio ever worked?
- Add sound/video source to test on both devices

## Testing findings:
- Safari + iPhone connection doesn't work; while Chrome + iPhone works but without the sound
- What I can test: if the audio works at all => play some sound (or better -- a pre-loaded video with sound) when the client joins the conference; this can show if this is a browser issue or webRTC one

## Investigating why webRTC isn't working:
- "Starting with Asterisk 12 you need to have pjproject libraries installed, otherwise you most likely won't have audio in your WebRTC calls and no warning whatsoever!" [source](https://stackoverflow.com/questions/28501309/no-audio-in-webrtc-and-asterisk)
- "First question: have you ensured all firewall configs permit RTP streams from the chosen STUN / ICE server unconditionally? My own experience is that audio issues with WebRTC are almost always related to STUN / ICE & Firewall."

## Sep 18 Summary

### Meeting notes:
- [x] Got server to work on Amina's laptop
- [x] Clarified questions with Michael
- [x] Laptop question -- figuring out + IM lab/CAT might be able to help 

### Understanding notes:

Telepresence system consists of webRTC and Arduino, where server = web server and client = video + audio software for the robot (2 clients in total = robot and device).

### WebRTC:
- Send data through API's
- Client <-> Server <-> Client
- Transferring audio+video object for privacy

## Clarification points:
- How is the system intended to work and where does Arduino come in?
- Does the robot needs constructing at this time or is the main priority for now the software fix?
- How to power up computer to robot? How does it work remotely?
- Which network does the robot connect to?
- Ask Michael for a work laptop -- mine can't handle any more software :(

## Brainstorm around why the audio doesn't work:
- Buggy code?
- Browser issues? E.g. Chrome sometimes blocks external audio
- Network issues? Drop somewhere in the communication to server process?
