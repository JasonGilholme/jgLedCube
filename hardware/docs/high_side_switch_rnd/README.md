## Transistor Switch Tests

The goal here is to figure out the best way to switch the LED's to provide a solution that switches fast enough and doesn't use a lot of power.


#### Schematic 1

Found this on the internet and used it as a starting point.

Turn On:  250ns
Turn Off: Initially quick, lots of ringing

<img src="./001_schematic.jpg" width="600" align="center"><br>
Schematic

<img src="./001_rising.png" width="600" align="center"><br>
Rise Time

<img src="./001_falling.png" width="600" align="center"><br>
Fall Time (Time base matches Schematic 1)


#### Schematic 2

Recommendation from EEVBlog Forum User

Turn On:  100ns
Turn Off: Initially quick. Possibly quicker than Schematic 1. Ringing gone.


<img src="./002_schematic.jpg" width="600" align="center"><br>
Schematic

<img src="./002_rising.png" width="600" align="center"><br>
Rise Time

<img src="./002_falling_01.png" width="600" align="center"><br>
Fall Time


#### Schematic 3

Turn On:  Not measured
Turn Off: Initially quick rate.  Response time varies depending on component selection.

<img src="./003_schematic.jpg" width="600" align="center"><br>
Schematic

<img src="./002_falling_02.png" width="600" align="center"><br>
Schematic 2 fall at matching time base

<img src="./003_falling.png" width="600" align="center"><br>
Schematic 3

<img src="./003_falling_no_c1.png" width="600" align="center"><br>
Schematic 3 - without C1

<img src="./003_falling_no_c1_no_r5.png" width="600" align="center"><br>
Schematic 3 - without C1 and without R5

<img src="./003_falling_1k_for_r1_and_r4.png" width="600" align="center"><br>
Schematic 3 - 1k for R1 and R4

