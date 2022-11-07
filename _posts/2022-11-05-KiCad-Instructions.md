# How To Use KiCad

## [1] Introduction
- Make a directory or use Github repository by selecting the notebook icon in the righthand column
  2 options come up: Schematic (EESchema) and Layout
  <img width="947" alt="Screen Shot 2022-11-07 at 12 03 19 PM" src="https://user-images.githubusercontent.com/54836827/200257314-b6120a37-7c99-4794-8681-0e2ee76f9eb6.png">
  
  - EESchema is teh schematic design, wherein the theoretical PCB design is conducted. This is the placing of components and additions of values and connections
  - Layout address the footprints of each component and the tangible, physical layout of the PCB, such as component placement, and wiring ont he top and bottom of the PCB


## [2] Schematic Symbol
- Either access the symbol editor and find the specific component or create a non-existing component
  - Most times, the components will already exist and can immediately be placed into the schematic. The following step are for components that are not found in any KiCad library

## [3] Making A Schematic
- (A) Opens up the symbol library to choose, select and place components into the schematic
  - (C) Duplicates a component
  - (R) Rotates a component
<img width="395" alt="Screen Shot 2022-11-07 at 12 26 47 PM" src="https://user-images.githubusercontent.com/54836827/200261723-95025c7d-2ac9-4c71-8644-9657216a4a99.png">

- Assign specific values to each component on the schematic by right-clicking the component, opening th properties menu and selecting the value feature to input value (Or by using V as a shortcut)
- (W) runs wires/ connectoin between components
- Use the symbol library to select the power flag and the ground symbols (Down arrow). This is a common feature missed out in most circuits and is picked up as an error. Each component that needs to be grounded should go to a ground (multiple ground symbols still connect to one ground) and all the power sources are specified using a powerflag. Connections that do not go anywhere should have a no connectionsymbol (an X)
<img width="713" alt="Screen Shot 2022-11-07 at 12 30 05 PM" src="https://user-images.githubusercontent.com/54836827/200262316-09118a10-4f2b-442c-881c-aaf61ce32158.png">

- Once all the components are placed and connected correctly, use the Electrical Rules Calculator to double-check the connections
  - The ERC feature is located in the top toolbar on the right
- Annotate the components in the annotation menu. This is done to differentiate each component in theschematic and to fully define it
  - The Annotation feature is located directly on the right of the ERC
 
## [4] Associating Symbols
- Once the schematic has been constructed and validated by the ERC, a footprint needs to be designed
 - A footprint is the real-world size of each component that can be used to model the PCB design more accurately than a schematic
- Open the CvPCB function (top toolbar) to assign a footprint to each respective component
- Once CvPCB is selected and run, KiCad will automatically assign the footprint to each component. In the case that is does not or 
  if a new symbol was created, the footprint will need to manually be assigned. The middle column contains each component within the schematic.
  Once selected, a component library tha tcan be selected from the left column will need to be selected. From here, the component footprint can 
  be found and selected, then appearing in the righthand column

## [5] Create a Custom Footprint
