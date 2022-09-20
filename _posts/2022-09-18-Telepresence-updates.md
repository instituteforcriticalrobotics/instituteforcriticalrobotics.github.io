# Amina's updates on the telepresence robot

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
