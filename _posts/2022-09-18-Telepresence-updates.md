# Amina's updates on the telepresence robot

# Sep 29 Summary:
- Discovered that on the client's side audio was muted; enabled it.
- Do we need the audio to play on the robot's side?
- Testing continued with Aalya

# Sep 27 Summary:
- Good news: the audio now works on the robot's side -- do we need this? Should the audio only work on the client's side? Investigate that further.

# Sep 25 Meeting notes:
- Check with Alia Waleed on last semester's codebase for network connection
- Completed the Raspberry Pi setup on the computer
- Merged pull request
- Continue with debugging and meet in two weeks

# Sep 24 Summary:
- In webrtc.js there indeed was a line (75) that never asked for microphone permission! I will toggle the audio to true and see what happens.
  - Created a pull request with changes -> ask Michael to invite me as a collaborator to the repository. Otherwise, I am unable to test the changes.
- Was able to progress in understanding a bit thanks to this [video](https://www.youtube.com/watch?v=WmR9IMUD_CY). However, still don't understand the receiver/client/non-robot part of the video -- need to dig deeper through the codebase.
- Question to Michael: can there be more than one client/non-robot interactor? If so, how would that be ensured? Right now it seems like anyone can join and take "control" of the Arduino. What if there are conflicts?
- What is the difference between [this telepresence repository](https://github.com/michaelshiloh/telepresence) and [this with webRTC](https://github.com/michaelshiloh/webRTC)? The first one is the one with Python code.
- As far as it seems, pressing on buttons doesn't work because they aren't really connected to the Arduino code. In the backend, the button commands aren't linked with Arduino-specific commands, so that's why we get the error message. To fix this, we need to define these commands in the backend and link the code/codebases.

# Sep 22-23 Summary
- Checking if the website uses microphone:
  - so the website asks for the video permission in the beginning, but never does so for the microphone, so it's never initialized. this is why (my guess) we hear no audio (see screenshot attached). But this doesn't seem to resolve it.
- here's what I found as well "you need to open and forward UDP ports 9100-9199 to the pbx in firewall/router for the audio." (https://www.3cx.com/community/threads/webrtc-no-audio.40818/)
- A lot of [workarounds/fixes](https://community.asterisk.org/t/asterisk-16-4-webrtc-no-audio/83624) for audio involve diving into SIP trace / server / http config settings. I have little understanding of this, so perhaps should schedule some time with Jack to see if I can get help
- "All WebRTC clients are inside local network, so ICE isn't needed here. But the bad way - ICE is the problem here. I've made a lot of tests and found that if call initiator is Web RTC client and there is some delay in answer (10-25 seconds) - audio is completely absent. Also in this case in RTP debug can be seen than "sent RTP packet" doesn't have "via ICE" mark. But when call initiator is any SIP client (X-Lite, Ekiga, etc) - WebRTC works perfectly. And the answer (as I think) is in rtcp-mux - wich can't do Asterisk but Sofia (SIP library for FreeSwitch) can"
- Should I follow a new tutorial to replicate this?

# Sep 20 Summary
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

# Sep 18 Summary

## Meeting notes:
- [x] Got server to work on Amina's laptop
- [x] Clarified questions with Michael
- [x] Laptop question -- figuring out + IM lab/CAT might be able to help 

## Understanding notes:

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
