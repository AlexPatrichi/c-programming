/*
=============================================================================
FILE: 02_user_input_average.c
PURPOSE: Track weekly screen time using user input and calculate a daily average.
=============================================================================
*/

#include <stdio.h>

int main(void) {

/* === STEP 1: DEFINE VARIABLES ===

Instead of storing predefined screen-time values, this version
allows the user to enter their own weekly screen time.

recommendedLimit represents the maximum recommended daily
screen time in minutes.
*/
    int social, video, games;
    int total;
    float dailyAverage;
    int recommendedLimit = 120; // 2 hours in minutes
    
/* === STEP 2: GET USER INPUT ===

scanf() stores each value entered by the user in the
corresponding variable.
*/    
    printf("Weekly Screen-Time Tracker\n");
    printf("--------------------------\n");
    
    printf("How many minutes do you spend on social media weekly?\n");
    printf("Input: ");
    scanf("%d", &social);
    
    printf("How many minutes do you watch video streaming weekly?\n");
    printf("Input: ");
    scanf("%d", &video);

    printf("How many minutes do you spend playing video games weekly?\n");
    printf("Input: ");
    scanf("%d", &games);


/* === STEP 3: VALIDATE INPUT ===

Screen time cannot be negative.

The || (OR) operator allows us to check all three values.
If at least one value is negative, the program displays an error and stops.
*/
    if (social < 0 || video < 0 || games < 0) {
        printf("Error: Screen-time values cannot be negative.\n");
        return 1;
    }

/* === STEP 4: CALCULATE RESULTS ===

First, add all three categories to calculate the weekly total.

The weekly total is then divided by 7 to calculate the
average screen time per day.

Using 7.0 causes floating-point division, allowing the result
to contain decimal places.
*/    
    
    total = social + video + games; // Calculate total weekly screen time
    dailyAverage = total / 7.0;     // Compute the daily average.

/* === STEP 5: DISPLAY RESULTS === */ 

    printf("\nWeekly Results\n");
    printf("--------------------------\n");

    printf("Social Media: %d minutes\n", social);
    printf("Video Streaming: %d minutes\n", video);
    printf("Games: %d minutes\n", games);

    printf("--------------------------\n");
    printf("Total Weekly Screen Time: %d minutes\n", total);
    printf("Daily Average: %.2f minutes\n\n", dailyAverage);
    
/* === STEP 6: CHECK RECOMMENDED LIMIT ===

Compare the daily average with the recommended daily limit.

    dailyAverage <= recommendedLimit  -> “Within recommended limit”
    dailyAverage > recommendedLimit   -> “Above recommended limit”  
*/
    if (dailyAverage <= recommendedLimit) {
        printf("Status: Within recommended limit.\n");
    } else {
        printf("Status: Above recommended limit.\n");
    }

    return 0;
}

