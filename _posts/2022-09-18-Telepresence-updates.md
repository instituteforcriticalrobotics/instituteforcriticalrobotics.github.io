# Amina's updates on the telepresence robot

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
