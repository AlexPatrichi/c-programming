/*
=============================================================================
FILE: 03_weekly_temperature_analysis.c
PURPOSE: Record and analyse daily temperature readings using a fixed-size
         array and sentinel value. The program can display readings,
         calculate averages, find highest and lowest temperatures, compare
         readings with a threshold, and calculate weekly averages.
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

            while (getchar() != '\n');  // Discard invalid input
            numberOfDays = 0;

        } else if (numberOfDays < 1 || numberOfDays > MAX_DAYS) {
            printf("Invalid choice. Please enter a number between 1 and 30.\n");
        }

    } while (numberOfDays < 1 || numberOfDays > MAX_DAYS); 


/* === STEP 2: STORE TEMPERATURE READINGS ===

Unlike the previous version, this program uses a fixed-size
array.

MAX_DAYS positions are available for temperature readings,
and one additional position is reserved for the sentinel.

    temperatureReadings[0]  -> Day 1
    temperatureReadings[1]  -> Day 2
    ...
    temperatureReadings[29] -> Day 30
    temperatureReadings[30] -> Sentinel (when all 30 days are used)

The sentinel marks the end of the valid temperature readings.
*/

    float temperatureReadings[MAX_DAYS + 1];

    for (int i = 0; i < numberOfDays; i++) {

        while (1) {
            printf("Enter temperature for day %d: ", i + 1);

            if (scanf("%f", &temperatureReadings[i]) == 1) {
                break;
            }

            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // Discard invalid input
        }
    }

    // Mark the end of the valid temperature readings
    temperatureReadings[numberOfDays] = SENTINEL;


/* === STEP 3: START REPEATING MENU ===

The menu repeats after each action until the user selects
option 6 to exit.

Available options:

    1 -> Display all temperature readings
    2 -> Calculate the overall average temperature
    3 -> Find the highest and lowest temperature
    4 -> Count days above and below a threshold
    5 -> Calculate weekly average temperatures
    6 -> Exit the program
*/
    int choice; 

    do {

        printf("\n------------------ Menu ------------------\n");
        printf("1. Display all temperature readings.\n");
        printf("2. Calculate and display the average temperature.\n");
        printf("3. Find and display the highest and lowest temperature.\n");
        printf("4. Count days above and below a temperature threshold.\n");
        printf("5. Calculate and display weekly average temperatures.\n");
        printf("6. Exit the program.\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');  // Discard invalid input
            choice = 0;
            continue;
        }

/* === STEP 4: PROCESS MENU CHOICE ===

The switch statement performs the selected action.

Most array operations use the sentinel instead of
numberOfDays to determine where the valid readings end.
*/

        switch (choice) {

            /* OPTION 1: DISPLAY ALL TEMPERATURE READINGS */
            case 1:
                printf("\nRecorded temperature readings:\n");

                for (int i = 0; temperatureReadings[i] != SENTINEL; i++) {
                    printf("Day %d: %.1fC\n",
                           i + 1, temperatureReadings[i]);
                }

                break;


            /* OPTION 2: CALCULATE OVERALL AVERAGE */
            case 2: {
                float temperatureSum = 0.0;

                for (int i = 0; temperatureReadings[i] != SENTINEL; i++) {
                    temperatureSum += temperatureReadings[i];
                }

                float temperatureAverage = temperatureSum / numberOfDays;

                printf("\nThe average temperature for %d days is: %.1fC\n",
                       numberOfDays, temperatureAverage);

                break;
            }


            /* OPTION 3: FIND HIGHEST AND LOWEST TEMPERATURE

            The first reading becomes the starting value for both
            lowestTemperature and highestTemperature.

            The remaining readings are compared with these values
            until the sentinel is reached.
            */

            case 3: {
                float lowestTemperature = temperatureReadings[0];
                float highestTemperature = temperatureReadings[0];

                for (int i = 1; temperatureReadings[i] != SENTINEL; i++) {

                    if (temperatureReadings[i] < lowestTemperature) {
                        lowestTemperature = temperatureReadings[i];
                    }

                    if (temperatureReadings[i] > highestTemperature) {
                        highestTemperature = temperatureReadings[i];
                    }
                }

                printf("\nLowest temperature: %.1fC\n", lowestTemperature);
                printf("Highest temperature: %.1fC\n", highestTemperature);

                break;
            }


            /* OPTION 4: COUNT DAYS ABOVE AND BELOW A THRESHOLD

            The user enters a temperature threshold.

            Each recorded temperature is compared with the threshold:

                temperature > threshold -> aboveCount increases
                temperature < threshold -> belowCount increases

            A temperature exactly equal to the threshold is counted
            as neither above nor below.
            */

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


            /* OPTION 5: CALCULATE WEEKLY AVERAGES

            The first recorded temperature represents Day 1 of Week 1.

            Every 7 readings form one complete week:

                Days 1-7   -> Week 1
                Days 8-14  -> Week 2
                Days 15-21 -> Week 3
                ...

            If the final week contains fewer than 7 days, its average
            is still calculated using the remaining readings.
            */

            case 5: {
                float weeklySum = 0.0;
                int dayCount = 0;
                int week = 1;

                printf("\nWeekly average temperatures:\n");

                for (int i = 0; temperatureReadings[i] != SENTINEL; i++) {

                    weeklySum += temperatureReadings[i];
                    dayCount++;

                    // Every 7 readings completes one full week
                    if ((i + 1) % 7 == 0) {

                        float weeklyAverage = weeklySum / dayCount;

                        printf("Week %d average: %.1fC\n",
                               week, weeklyAverage);

                        // Reset values for the next week
                        weeklySum = 0.0;
                        dayCount = 0;
                        week++;
                    }
                }

                // Calculate the average for an incomplete final week
                if (dayCount > 0) {

                    float weeklyAverage = weeklySum / dayCount;

                    printf("Week %d average: %.1fC\n",
                           week, weeklyAverage);
                }

                break;
            }


            /* OPTION 6: EXIT PROGRAM */

            case 6:
                printf("\nExiting the program...\n");
                break;


            /* HANDLE INVALID MENU CHOICES */

            default:
                printf("Invalid choice. Please enter an option from 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}