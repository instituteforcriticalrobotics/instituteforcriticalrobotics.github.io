# PCB manufacturing process

This document has been made in order to record my progress in designing the board with all the confusing aspects and mistakes as well, in order for me to learn from my mistakes and show my steps

### 17/11/2022 

<img width="378" alt="Screen Shot 2022-11-17 at 2 01 36 PM" src="https://user-images.githubusercontent.com/54836827/202417455-1f8bacf2-4477-42a2-8fe1-5c4eb8b67752.png">

This schematic is the current design I am working with. The tracks are routed via the front and back layers, even though I understand that the PCB material we have is one sided. This is done in order to bypass the design checking system KiCad has in place. At the moment, the nRFL2401 is placed at the end of the bored in order to avoid the ground pins on the arduino

<img width="514" alt="Screen Shot 2022-11-17 at 2 01 46 PM" src="https://user-images.githubusercontent.com/54836827/202417463-2430a323-78ca-4955-bf34-f4efed9c0f98.png">

These are the current errors with the design. I need to understand why KiCad is giving courtyard errors. I know that it is because the two components are overlapping, so I need to find a way to register the arduino as on the bottom of the board and the nRFL2401 on the top.
Another thing is the silkscreen overlap, which from my understanding is the drawing of the component footprint on the board overlapping each other. This should also be solved by inputing the position of each component as on opposite sides of the board

### _____________________

<img width="676" alt="Screen Shot 2022-11-17 at 5 46 46 PM" src="https://user-images.githubusercontent.com/54836827/202465298-006752ba-0bbe-4804-a496-f92b68289b57.png">

Breakthrough! It was actually really simple. All I had to do was press (F) to flip the component. I originally thought that it just flipped the orientation but it actually flips the entire component to the other side of the board. This can be seen by the border switching to blue outside and red inside instead of the orinigal red outside and blue inside. This meant that I had to rewire everything and start from the beginning, but that solved the courtyard issues. The problem now is that the "slikscreen is clipped by the solder mask" is still an issue

After some time of looking through, I've decided to continue with this design as this is only a warning and not an error. With that in mind, I think it will be possible to mill the PCB effectively without issue. All that is left is to run the dimensions by Michael and remove the front layer routes. I also need to confirm whether I should be using via holes or through holes in order to overlap routes using something like a jumper wire
