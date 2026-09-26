/*
=============================================================================
FILE: 01_basic_temperature_logger.c
PURPOSE: Record temperature readings for up to 30 days and allow the user
         to display the readings or calculate the overall average.
=============================================================================
*/

#include <stdio.h>

int main(void) {

/* === STEP 1: GET NUMBER OF DAYS ===

The user chooses how many days of temperature readings
they want to record.

The number must be between 1 and 30 because this program
stores a maximum of 30 daily temperature readings.
*/
    int numberOfDays;

    do {
        printf("How many days would you like to record (1-30): ");

        if (scanf("%d", &numberOfDays) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');  // Discard invalid input
            numberOfDays = 0;

        } else if (numberOfDays < 1 || numberOfDays > 30) {
            printf("Invalid choice. Please enter a number between 1 and 30.\n");
        }

    } while (numberOfDays < 1 || numberOfDays > 30);

/* === STEP 2: STORE TEMPERATURE READINGS ===

The array can store a maximum of 30 temperature readings.

The loop runs numberOfDays times and stores each temperature
in the next position of the array.

Array indexes start at 0:

    Day 1 -> temperatureReadings[0]
    Day 2 -> temperatureReadings[1]
    Day 3 -> temperatureReadings[2]
    ...
*/
    float temperatureReadings[numberOfDays]; 

    for (int i = 0; i < numberOfDays; i++) {
        printf("Enter temperature for day %d: ", i + 1);
        scanf("%f", &temperatureReadings[i]);
    }

/* === STEP 3: DISPLAY MENU ===

This basic version contains two menu options:

    1 -> Display all temperature readings
    2 -> Calculate and display the average temperature
*/
    int choice; 
    
    printf("\n------------------ Menu ------------------");
    printf("\n1. Display all temperature readings."); 
    printf("\n2. Calculate and display the average temperature.");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

/* === STEP 4: PROCESS MENU CHOICE ===

A switch statement performs the action selected by the user.

Option 1 loops through the array and displays each
temperature reading.

Option 2 adds all readings together and divides the total
by the number of recorded days.
*/
    switch (choice) {
        case 1:
            printf("\nRecorded temperature readings:\n");
            
            for (int i = 0; i < numberOfDays; i++) {
                printf("Day %d: %.1fC\n", i + 1, temperatureReadings[i]);
            }
            break;
    
        case 2: {
            float temperatureSum = 0.0;
            float temperatureAverage;

            for (int i = 0; i < numberOfDays; i++) {
                temperatureSum += temperatureReadings[i];
            }    

            temperatureAverage = temperatureSum / numberOfDays;

            printf("The average temperature for %d days is: %.1fC", numberOfDays, temperatureAverage);
            break;
        }  
        default: 
            printf("Invalid choice. Please enter 1 or 2.\n");    
    }

    return 0;
}