# PCB manufacturing process

This document has been made in order to record my progress in designing the
board with all the confusing aspects and mistakes as well, in order for me to
learn from my mistakes and show my steps

### 17/11/2022 

<img width="378" alt="Screen Shot 2022-11-17 at 2 01 36 PM" src="https://user-images.githubusercontent.com/54836827/202417455-1f8bacf2-4477-42a2-8fe1-5c4eb8b67752.png">

This schematic is the current design I am working with. The tracks are routed
via the front and back layers, even though I understand that the PCB material
we have is one sided. This is done in order to bypass the design checking
system KiCad has in place. At the moment, the nRFL2401 is placed at the end of
the bored in order to avoid the ground pins on the arduino

<img width="514" alt="Screen Shot 2022-11-17 at 2 01 46 PM" src="https://user-images.githubusercontent.com/54836827/202417463-2430a323-78ca-4955-bf34-f4efed9c0f98.png">

These are the current errors with the design. I need to understand why KiCad
is giving courtyard errors. I know that it is because the two components are
overlapping, so I need to find a way to register the arduino as on the bottom
of the board and the nRFL2401 on the top.  Another thing is the silkscreen
overlap, which from my understanding is the drawing of the component footprint
on the board overlapping each other. This should also be solved by inputing
the position of each component as on opposite sides of the board

### _____________________

<img width="676" alt="Screen Shot 2022-11-17 at 5 46 46 PM" src="https://user-images.githubusercontent.com/54836827/202465298-006752ba-0bbe-4804-a496-f92b68289b57.png">

Breakthrough! It was actually really simple. All I had to do was press (F) to
flip the component. I originally thought that it just flipped the orientation
but it actually flips the entire component to the other side of the board.
This can be seen by the border switching to blue outside and red inside
instead of the orinigal red outside and blue inside. This meant that I had to
rewire everything and start from the beginning, but that solved the courtyard
issues. The problem now is that the "slikscreen is clipped by the solder mask"
is still an issue

After some time of looking through, I've decided to continue with this design
as this is only a warning and not an error. With that in mind, I think it will
be possible to mill the PCB effectively without issue. All that is left is to
run the dimensions by Michael and remove the front layer routes. I also need
to confirm whether I should be using via holes or through holes in order to
overlap routes using something like a jumper wire

### 20/11/2022
![69047807513--C5C3F0E6-FDAB-4F5C-9408-B1CDD86BA4DD](https://user-images.githubusercontent.com/54836827/202911189-b0e65270-b13c-40a8-ab3f-27bac6073df9.jpg)

![Kicad](https://user-images.githubusercontent.com/54836827/202911049-17128c7d-a4b1-4903-abe2-7729e4ccc978.png)

This is the new and updated PCB (second image). I designed a PCB yesterday
that was similar (top image) however, I realized that one of the wirings int
eh schematic was wrong, and that 6 and 7 on the nRF24L01 were inverted, so I
had to go back and change it. This meant that I would now have two sets of via
holes instead of just one. The main update in these PCBs compared to the
previous date iteration is that the routes are much smaller and were set in
accordance with what I found online for the othermill pro. Furthermore, I
addedd a capacitor for the voltage and ground input.

### 12 February 2023

Michael here, learning how to use KiCad. Starting with Ahmed's servo board I
moved the connectors around and changed the footprint of the screw terminals,
the capacitor, and the Arduino pins. Also trying to get only the necessary
source files into github using .gitignore.

Notes from Ahmed's lesson:

- Open KiCad
- Open project
- Open schematic
- To delete a wire, right click on the wire or select and press "Delete"
- Any terminal that doesn't go anywhere (e.g. unused pins on Arduino) must be
	explicitely marked as no connect
- Every component must be labelled
- Every component must have a footprint
- Export netlist from schematic (file -> export -> netlist)
- Open the PCB view
- file -> import -> netlist
- update PCB
- Load and test
- Close the import netlist window
- Run the design rule checker (DRC). In addition to catching errors this will
	fill in the ground plane
- In the PCB view
	- f = footprint
	- m = move
	- r = rotate
	- a = add
	- x = route a track
- If any changes are made to footprints
	- update the netlist
	- update the PCB
- In some modes (like routing a trace) have to hit Esc twice to get out of
	that mode

Some useful resources:
- [Better manage KiCAD projects using
	Git](https://medium.com/inventhub/better-manage-kicad-projects-using-git-8d06e1310af8)
- [Practical Electronics/PCB
	Layout](https://en.wikibooks.org/wiki/Practical_Electronics/PCB_Layout)
	wherein "The optimum pad diameter for a through-hole component is twice its
	finished hole diameter."
- [How to Design a Custom Arduino Shield
	Board](https://resources.altium.com/p/how-design-custom-arduino-shield-board)
	wherein "Arduino base boards use pin headers with 0.1 inch (2.54 mm) pitch,
	with recommended hole sizes in the female header of 1.02 mm diameter.
- [Massaging your git for kicad](https://jnavila.github.io/plotkicadsch/)
	which includes important filters to remove changes that don't need to be
	tracked such as "changing the content of the files for administrative
	purpose, without any causal or visual relationship with user’s actions"

Goals of this exercise:

- Create a PCB for a servo shield
- Learn how to use KiCad
- Store on Github only the necessary source files. Never store any files that
	are produced from the source files.
