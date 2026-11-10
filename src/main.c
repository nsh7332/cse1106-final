
#include <stdio.h>
#include <pigpio.h>

#define PIN 17

int main(void)
{
    float temp, minTemp = 68, maxTemp = 76;
    float total = 0, newMin, newMax;
    int count = 0, choice;
    FILE *file;

    if (gpioInitialise() < 0)
    {
        printf("GPIO initialization failed.\n");
        return 1;
    }

    gpioSetMode(PIN, PI_OUTPUT);
    gpioWrite(PIN, 0);

    file = fopen("data/temperature_log.csv", "a");

    if (file == NULL)
    {
        printf("Error opening temperature log.\n");
        gpioTerminate();
        return 1;
    }

    do
    {
        printf("\n--- Classroom Comfort Monitor ---\n");
        printf("1. Enter Temperature\n");
        printf("2. Change Temperature Range\n");
        printf("3. View Average Temperature\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        if (choice == 1)
        {
            printf("Enter temperature (F): ");

            if (scanf("%f", &temp) != 1)
            {
                printf("Invalid temperature.\n");
                while (getchar() != '\n');
                continue;
            }

            total += temp;
            count++;

            if (temp >= minTemp && temp <= maxTemp)
            {
                printf("Status: NORMAL\n");
                printf("LED: OFF\n");
                gpioWrite(PIN, 0);
                fprintf(file, "%.2f,NORMAL\n", temp);
            }
            else
            {
                printf("Status: WARNING\n");
                printf("LED: ON\n");
                gpioWrite(PIN, 1);
                fprintf(file, "%.2f,WARNING\n", temp);
            }

            fflush(file);
        }
        else if (choice == 2)
        {
            printf("Enter minimum temperature: ");
            if (scanf("%f", &newMin) != 1)
            {
                printf("Invalid input.\n");
                while (getchar() != '\n');
                continue;
            }

            printf("Enter maximum temperature: ");
            if (scanf("%f", &newMax) != 1)
            {
                printf("Invalid input.\n");
                while (getchar() != '\n');
                continue;
            }

            if (newMin <= newMax)
            {
                minTemp = newMin;
                maxTemp = newMax;
                printf("Temperature range updated.\n");
            }
            else
            {
                printf("Invalid range.\n");
            }
        }
        else if (choice == 3)
        {
            if (count > 0)
                printf("Average Temperature: %.2f F\n",
                       total / count);
            else
                printf("No temperatures recorded.\n");
        }
        else if (choice == 4)
        {
            printf("Exiting program.\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 4);

    gpioWrite(PIN, 0);
    fclose(file);
    gpioTerminate();

    return 0;
}
