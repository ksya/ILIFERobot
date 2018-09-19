# ILIFERobot

Add WiFi capabilities to the ILIFE V5s using a NodeMCU or other ESP module. 
Beware, this is not an easy project, since there is currently no known way to connect to a debug port or serial output.

I just uploaded this since someone asked. The code is not really polished. Also, I don't have documentation of the hardware mods. 

1. You have to read out the led signals on top for the status
2. Hijack the IR inputs to emulate the remote and give it signals
3. Read out the battery voltage using a voltage divider
4. Detect a voltage on the docking input to check whether it is docked.

This can be connected to:
* IRPin:       4 (pin D2, pin that is used for sending the IR signals)
* statusPin1:  14 (pin D5, input pin for robot status (from led signal))
* statusPin2:  5 (pin D1, input pin for robot status (from led signal))
* statusPin3:  12 (pin D6, input pin for robot status (from led signal))
* dockPin:     16 (pin D0, input pin for dock contact)
* batteryPin: A0


The ILIFE V5s CPU is a STM32F030R8.
