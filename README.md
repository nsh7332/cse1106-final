
# Smart Classroom Comfort Monitor

## Project Description
For our CSE 1106 final project, our group chose to create a Smart Classroom Comfort Monitor using C and a Raspberry Pi.

The program lets users enter classroom temperatures and checks if they are within a comfortable range. If the temperature is too high or too low, the program displays a warning and turns on an LED light.

## Project Features
Our program can:
- Accept temperature readings in Fahrenheit.
- Check if temperatures are between 68°F and 76°F.
- Display NORMAL or WARNING depending on the temperature.
- Turn an LED on or off based on the result.
- Save temperature readings to a CSV file.
- Calculate the average temperature.
- Let users change the acceptable temperature range.

## Materials Used
- Raspberry Pi 4B
- Breadboard
- Red LED
- 1,000-ohm resistor
- Jumper wires
- C programming language
- pigpio library

## How to Run the Program

1. Open the project folder on the Raspberry Pi.
2. Make sure the data folder exists.
3. Open the terminal and compile the program.

Compile:
```bash
gcc -o monitor src/main.c -lpigpio -lrt -lpthread
```

Run:
```bash
sudo ./monitor
```

The program uses GPIO 17 to control the LED, so the LED needs to be connected to the correct pin.

## How the Program Works
When the program starts, a menu appears with four options:

1. Enter Temperature
2. Change Temperature Range
3. View Average Temperature
4. Exit

The user can enter a temperature, and the program checks if it is within the acceptable range.

If the temperature is normal, the LED stays off. If it is too high or too low, the LED turns on.

Each reading is also saved to a file so it can be viewed later.

## Testing
We prepared test cases for normal temperatures, high temperatures, low temperatures, boundary temperatures, and changing the acceptable range.

We also included additional tests for the average calculation and invalid inputs.

Our testing report is located in tests/test_plan.md.

The physical LED will be tested on the Raspberry Pi during Lab Session B.

## Project Files
- src/main.c - Main C program
- docs/requirements.md - Project requirements
- docs/design.md - System design
- docs/change_log.md - Changes and debugging notes
- tests/test_plan.md - Software testing report
- data/temperature_log.csv - Saved temperature readings

## Conclusion
This project helped us practice using C programming with Raspberry Pi hardware. We used concepts like variables, loops, if statements, and file handling to create a program that checks classroom temperatures and gives warnings when needed.
