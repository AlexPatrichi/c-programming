/*
=============================================================================
FILE: 02_temperature_analysis.c
PURPOSE: Record daily temperature readings and provide a repeating menu
         to display readings, calculate the average, and find the highest
         and lowest temperatures.
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

The outer for loop moves through each day.

The inner while loop makes sure a valid number is entered
before moving to the next day.

Array indexes start at 0:

    Day 1 -> temperatureReadings[0]
    Day 2 -> temperatureReadings[1]
    Day 3 -> temperatureReadings[2]
    ...
*/
    float temperatureReadings[numberOfDays]; 

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

/* === STEP 3: START REPEATING MENU ===

Unlike the previous version, the menu now repeats after
each action.

The program continues running until the user selects
option 4 to exit.

Available options:

    1 -> Display all temperature readings
    2 -> Calculate the average temperature
    3 -> Find the highest and lowest temperature
    4 -> Exit the program
*/

    int choice; 

    do {
    
        printf("\n------------------ Menu ------------------");
        printf("\n1. Display all temperature readings."); 
        printf("\n2. Calculate and display the average temperature.");
        printf("\n3. Find and display the highest and lowest temperature.");
        printf("\n4. Exit the program.");

        printf("\n\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');  // Discard invalid input
            choice = 0;
            continue;
        }

/* === STEP 4: PROCESS MENU CHOICE ===

A switch statement performs the selected action.

After an option finishes, the do...while loop returns
the user to the menu unless option 4 was selected.
*/
        switch (choice) { 
            // OPTION 1: DISPLAY ALL TEMPERATURE READINGS 
            case 1:
                printf("Recorded temperature readings:\n");
            
                for (int i = 0; i < numberOfDays; i++) {
                    printf("Day %d: %.1fC\n", i + 1, temperatureReadings[i]);
                }
                break;
                
            // OPTION 2: CALCULATE AVERAGE TEMPERATURE 
            case 2: {
                float temperatureSum = 0.0;
                float temperatureAverage;

                for (int i = 0; i < numberOfDays; i++) {
                    temperatureSum += temperatureReadings[i];
                }

                temperatureAverage = temperatureSum / numberOfDays;

                printf("\nThe average temperature for %d days is: %.1fC\n",
                       numberOfDays, temperatureAverage);

                break;
            }
            // OPTION 3: FIND HIGHEST AND LOWEST TEMPERATURE
            case 3: {
                float lowestTemperature = temperatureReadings[0];
                float highestTemperature = temperatureReadings[0];

                for (int i = 1; i < numberOfDays; i++) {

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
            
            // OPTION 4: EXIT PROGRAM 
            case 4: 
                printf("Exiting the program ... \n");
                break;

            // HANDLE INVALID MENU CHOICES 
            default:
                printf("Invalid choice. Please enter an option from 1 to 4.\n");    
        }

    } while (choice != 4); 

    return 0;
}