# PCB manufacturing process

This document has been made in order to record my progress in designing the board with all the confusing aspects and mistakes as well, in order for me to learn from my mistakes and show my steps

<img width="378" alt="Screen Shot 2022-11-17 at 2 01 36 PM" src="https://user-images.githubusercontent.com/54836827/202417455-1f8bacf2-4477-42a2-8fe1-5c4eb8b67752.png">

This schematic is the current design I am working with. The tracks are routed via the front and back layers, even though I understand that the PCB material we have is one sided. This is done in order to bypass the design checking system KiCad has in place. At the moment, the nRFL2401 is placed at the end of the bored in order to avoid the ground pins on the arduino

<img width="514" alt="Screen Shot 2022-11-17 at 2 01 46 PM" src="https://user-images.githubusercontent.com/54836827/202417463-2430a323-78ca-4955-bf34-f4efed9c0f98.png">

These are the current errors with the design. I need to understand why KiCad is giving courtyard errors. I know that it is because the two components are overlapping, so I need to find a way to register the arduino as on the bottom of the board and the nRFL2401 on the top.
Another thing is the silkscreen overlap, which from my understanding is the drawing of the component footprint on the board overlapping each other. This should also be solved by inputing the position of each component as on opposite sides of the board
