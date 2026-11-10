
# Smart Classroom Comfort Monitor

## System Design

### Project Overview
For our project, we are using a Raspberry Pi and a C program to monitor classroom temperatures. The user enters a temperature, and the program checks whether it is within the acceptable range. The program then displays the result and uses an LED light to show if there is a warning.

### How the System Works
1. The program starts and sets up the Raspberry Pi.
2. A menu appears with options to enter a temperature, change the temperature range, view the average, or exit.
3. The user enters a temperature in Fahrenheit.
4. The program checks if the temperature is between 68°F and 76°F.
5. If the temperature is within the range, the program displays "NORMAL" and turns the LED off.
6. If the temperature is outside the range, the program displays "WARNING" and turns the LED on.
7. The temperature and its status are saved to a file.
8. The menu appears again so the user can choose another option.

### Hardware Design
Our project uses a Raspberry Pi 4B connected to a breadboard with a red LED, a 1,000-ohm resistor, and jumper wires.

The LED is connected to GPIO 17, which is physical pin 11 on the Raspberry Pi. The circuit also connects to a ground pin.

The resistor helps control the amount of electricity going through the LED so it does not get damaged.

When the program sends a HIGH signal to GPIO 17, the LED turns on. When it sends a LOW signal, the LED turns off.

### Software Design
The program is written in C and uses the pigpio library to control the LED.

We use:
- Variables to store temperature readings and calculate the average.
- If/else statements to check whether a temperature is normal or outside the range.
- A loop to keep the program running until the user exits.
- File handling to save the temperatures and their statuses.
- GPIO functions to turn the LED on and off.

### Program Flow
1. The program starts and sets up the Raspberry Pi.
2. The main menu appears with four options.
3. The user can enter a temperature, change the temperature range, view the average, or exit.
4. When a temperature is entered, the program checks if it is within the acceptable range.
5. If the temperature is normal, the LED stays off. If it is too high or too low, the LED turns on.
6. The program saves the temperature and its status to a file.
7. The menu appears again until the user decides to exit.

### Data Storage
The program saves the temperature readings and their statuses in a CSV file called `temperature_log.csv` inside the `data` folder.

For example, the file might contain:

72.00,NORMAL

79.00,WARNING

65.00,WARNING

This allows us to look back at the temperatures that were entered.

### Conclusion
Our project uses C programming and Raspberry Pi hardware to create a simple classroom temperature monitor. It checks temperature readings, displays the results, and uses an LED to warn the user when a temperature is outside the acceptable range. The program also saves the readings and allows the user to calculate the average temperature.
