/*
=============================================================================
FILE: 04_pointer_temperature_logger.c
PURPOSE: Record and analyse daily temperature readings using a fixed-size
         array, sentinel value, loops, menu options, and pointers.

         Pointers are used to traverse the temperature array, find the
         highest and lowest temperatures, and reverse the array.
=============================================================================
*/

#include <stdio.h>

#define MAX_DAYS 30
#define SENTINEL -999.0f

int main(void) {

/* === STEP 1: GET NUMBER OF DAYS ===

The user chooses how many days of temperature readings
they want to record.

The number must be between 1 and MAX_DAYS.
*/

    int numberOfDays;

    do {
        printf("How many days would you like to record (1-30): ");

        if (scanf("%d", &numberOfDays) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');
            numberOfDays = 0;

        } else if (numberOfDays < 1 || numberOfDays > MAX_DAYS) {
            printf("Invalid choice. Please enter a number between 1 and 30.\n");
        }

    } while (numberOfDays < 1 || numberOfDays > MAX_DAYS);


/* === STEP 2: STORE TEMPERATURE READINGS ===

The program uses a fixed-size array.

MAX_DAYS positions are available for temperature readings,
with one additional position reserved for the sentinel.

The sentinel marks the end of the valid readings.
*/

    float temperatureReadings[MAX_DAYS + 1];

    for (int i = 0; i < numberOfDays; i++) {

        while (1) {
            printf("Enter temperature for day %d: ", i + 1);

            if (scanf("%f", &temperatureReadings[i]) == 1) {
                break;
            }

            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
        }
    }

    temperatureReadings[numberOfDays] = SENTINEL;


/* === STEP 3: START REPEATING MENU ===

The menu repeats until the user selects option 7.

Available options:

    1 -> Display all temperature readings
    2 -> Calculate the overall average
    3 -> Find highest and lowest temperatures
    4 -> Count days above and below a threshold
    5 -> Calculate weekly averages
    6 -> Reverse and display temperature readings
    7 -> Exit
*/

    int choice;

    do {
        printf("\n------------------ Menu ------------------\n");
        printf("1. Display all temperature readings.\n");
        printf("2. Calculate and display the average temperature.\n");
        printf("3. Find and display the highest and lowest temperature.\n");
        printf("4. Count days above and below a temperature threshold.\n");
        printf("5. Calculate and display weekly average temperatures.\n");
        printf("6. Reverse the temperature readings and display them.\n");
        printf("7. Exit the program.\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');
            choice = 0;
            continue;
        }


/* === STEP 4: PROCESS MENU CHOICE === */

        switch (choice) {

        /* OPTION 1: DISPLAY READINGS USING A POINTER

        ptr initially points to the first element of the array.

        Dereferencing ptr with *ptr gives the temperature stored
        at the current position.

            ptr   -> address
            *ptr  -> temperature at that address

        ptr++ moves the pointer to the next array element.
        */
            case 1: {
                float *ptr = temperatureReadings;
                int day = 1;

                printf("\nRecorded temperature readings:\n");

                while (*ptr != SENTINEL) {
                    printf("Day %d: %.1fC\n", day, *ptr);

                    ptr++;
                    day++;
                }

                break;
            }


        /* OPTION 2: CALCULATE OVERALL AVERAGE */
            case 2: {
                float temperatureSum = 0.0;

                for (int i = 0; temperatureReadings[i] != SENTINEL; i++) {
                    temperatureSum += temperatureReadings[i];
                }

                float temperatureAverage =
                    temperatureSum / numberOfDays;

                printf("\nThe average temperature for %d days is: %.1fC\n",
                       numberOfDays, temperatureAverage);

                break;
            }


        /* OPTION 3: FIND HIGHEST AND LOWEST USING A POINTER

        The first reading becomes the initial highest and lowest.

        The pointer starts at the second reading because the first
        reading has already been used for initialization.

        The pointer then moves through the array until it reaches
        the sentinel.
        */
            case 3: {
                float lowestTemperature = temperatureReadings[0];
                float highestTemperature = temperatureReadings[0];

                float *ptr = temperatureReadings + 1;

                while (*ptr != SENTINEL) {

                    if (*ptr < lowestTemperature) {
                        lowestTemperature = *ptr;
                    }

                    if (*ptr > highestTemperature) {
                        highestTemperature = *ptr;
                    }

                    ptr++;
                }

                printf("\nLowest temperature: %.1fC\n",
                       lowestTemperature);

                printf("Highest temperature: %.1fC\n",
                       highestTemperature);

                break;
            }


        /* OPTION 4: COUNT DAYS ABOVE AND BELOW A THRESHOLD */
            case 4: {
                float threshold;
                int aboveCount = 0;
                int belowCount = 0;

                printf("\nEnter threshold temperature: ");

                while (scanf("%f", &threshold) != 1) {
                    printf("Invalid input. Please enter a number: ");
                    while (getchar() != '\n');
                }

                for (int i = 0; temperatureReadings[i] != SENTINEL; i++) {

                    if (temperatureReadings[i] > threshold) {
                        aboveCount++;
                    }

                    if (temperatureReadings[i] < threshold) {
                        belowCount++;
                    }
                }

                printf("Days above threshold: %d\n", aboveCount);
                printf("Days below threshold: %d\n", belowCount);

                break;
            }


        /* OPTION 5: CALCULATE WEEKLY AVERAGES */
            case 5: {
                float weeklySum = 0.0;
                int dayCount = 0;
                int week = 1;

                printf("\nWeekly average temperatures:\n");

                for (int i = 0; temperatureReadings[i] != SENTINEL; i++) {

                    weeklySum += temperatureReadings[i];
                    dayCount++;

                    if ((i + 1) % 7 == 0) {

                        float weeklyAverage =
                            weeklySum / dayCount;

                        printf("Week %d average: %.1fC\n",
                               week, weeklyAverage);

                        weeklySum = 0.0;
                        dayCount = 0;
                        week++;
                    }
                }

                // Handle an incomplete final week
                if (dayCount > 0) {

                    float weeklyAverage =
                        weeklySum / dayCount;

                    printf("Week %d average: %.1fC\n",
                           week, weeklyAverage);
                }

                break;
            }


        /* OPTION 6: REVERSE ARRAY USING POINTERS

        Two pointers are used:
            leftPtr  -> first temperature
            rightPtr -> last temperature

        The values at these addresses are swapped.

        The pointers then move towards each other:
            leftPtr++
            rightPtr--

        The process stops when the pointers meet or cross.

        Example:
            Before: [27] [28] [26] [24] [29]
            After: [29] [24] [26] [28] [27]
        */
            case 6: {
                float *leftPtr = temperatureReadings;
                float *rightPtr =
                    temperatureReadings + numberOfDays - 1;

                while (leftPtr < rightPtr) {

                    float temp = *leftPtr;

                    *leftPtr = *rightPtr;
                    *rightPtr = temp;

                    leftPtr++;
                    rightPtr--;
                }


        /* Display the reversed readings.

        After reversing:
            temperatureReadings[0] -> Today
            temperatureReadings[1] -> Yesterday
            temperatureReadings[2] -> 2 days ago
            ...
        */
                float *ptr = temperatureReadings;
                int daysAgo = 0;

                printf("\nReversed temperature readings:\n");

                while (*ptr != SENTINEL) {

                    if (daysAgo == 0) {
                        printf("Today: %.1fC\n", *ptr);

                    } else if (daysAgo == 1) {
                        printf("Yesterday: %.1fC\n", *ptr);

                    } else {
                        printf("%d days ago: %.1fC\n",
                               daysAgo, *ptr);
                    }

                    ptr++;
                    daysAgo++;
                }

                break;
            }


        /* OPTION 7: EXIT PROGRAM */
            case 7:
                printf("\nExiting the program...\n");
                break;


        /* HANDLE INVALID MENU CHOICES */
            default:
                printf("Invalid choice. Please enter an option from 1 to 7.\n");
        }

    } while (choice != 7);

    return 0;
}