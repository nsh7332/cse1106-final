
# Smart Classroom Comfort Monitor

## Project Requirements

### Project Description
For this project, our group is creating a classroom temperature monitoring system using C and a Raspberry Pi. The program lets users enter classroom temperatures and checks if they are within a comfortable range. If the temperature is too high or too low, the program displays a warning and turns on an LED light.

### Functional Requirements
Our program will be able to:

1. Let users enter classroom temperatures in Fahrenheit.
2. Check if the temperature is between 68°F and 76°F.
3. Display "NORMAL" when the temperature is within the acceptable range.
4. Display "WARNING" when the temperature is too high or too low.
5. Turn the LED on when there is a warning.
6. Turn the LED off when the temperature is normal.
7. Save temperature readings and their statuses to a file.
8. Calculate the average temperature from the readings entered during the current run.
9. Let users change the minimum and maximum acceptable temperatures.
10. Let users exit the program when finished.

### Hardware Requirements
- Raspberry Pi 4B
- Breadboard
- Red LED light
- 1,000-ohm resistor
- Jumper wires

### Software Requirements
- C programming language
- GCC compiler
- pigpio library
- GitHub

### Temperature Range
The default acceptable temperature range is 68°F to 76°F.

Temperatures of exactly 68°F or 76°F are considered normal.

### LED Indicator
The LED light is used to show whether the classroom temperature is acceptable.

- NORMAL: The LED stays off.
- WARNING: The LED turns on.

### Data Storage
The program saves each temperature reading and its status in a CSV file called `temperature_log.csv`. This allows the readings to be viewed later.

### Average Temperature
The program keeps track of the temperatures entered while it is running. It uses these readings to calculate the average temperature. The average resets when the program is restarted, but previous readings remain saved in the file.
