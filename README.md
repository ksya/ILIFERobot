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

#Hardware installation
##PCB LED connections for reading robot status
t1 = tp47 -> G
t2 = tp52 -> nc (probably for the start button)
t3 = tp44 -> D5 (led 1)
t4 = tp49 -> D1 (led 2)
t5 = tp48 -> D6 (led 3)
t6 = tp43 -> 3V

##PCB IR pin
tp19 -> D2 (IR sensor)

##The voltage dividers for reading docking and battery status
(yellow heat shrink) 10 kOhm between G and D0 --> 100 kOhm between D0 and DOCK+ (red)
(blue heat shrink) 10 kOhm between G and A0 --> 100 kOhm between A0 and BAT+ (red)

##Insulate
Be sure to protect the NodeMCU from touching the metal plate. Insulate the plate with insulation tape or protect the NodeMCU itself.

#Software installation
Change the lines in ILIFERobot.ino to match your WiFi credentials and MQTT server:

    const char* WiFi_SSID = "your_ssid"; // LAN
    const char* WiFi_PW = "your_password";
    const char* mqtt_server = "192.168.5.7";

Compile and upload the software to your NodeMCU 

After that, there will be a Web UI available. It will also broadcast status on MQTT topic "ILIFERobot/state". Commands can be send on topic "ILIFERobot/command". For more information, see the Home-Assistant config.

![Web UI of the smart Ilife Robot](https://github.com/ksya/ILIFERobot/raw/master/images/webui.png)

#Other findings
I couldn't figure out how to read out digital signals, but if anyone wants to try, you can search the documentation of the CPU. For the ILIFE V5s it is a STM32F030R8.
