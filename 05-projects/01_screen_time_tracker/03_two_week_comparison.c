/*
=============================================================================
FILE: 03_two_week_comparison.c
PURPOSE: Track and compare screen time across two consecutive weeks.
=============================================================================
*/

#include <stdio.h>

int main(void) {

/* === STEP 1: DEFINE VARIABLES ===

This version tracks the same three screen-time categories
across two consecutive weeks.

Each category needs one value for Week 1 and one for Week 2.
*/

    int socialA, socialB; 
    int videoA, videoB;
    int gamesA, gamesB;

    int totalA, totalB; 
    float dailyAverageA, dailyAverageB;

    int recommendedLimit = 120; // 2 hours in minutes

/* === STEP 2: GET SCREEN-TIME FOR BOTH WEEKS ===

The user enters the weekly screen-time minutes for each
category for Week 1 and Week 2.
*/

    printf("Multi-Week Tracking\n");
    printf("===========================\n");
    
    printf("Social Media (minutes per week)\n");
    printf("Week 1: ");
    scanf("%d", &socialA);
    printf("Week 2: ");
    scanf("%d", &socialB);
    
    printf("Video Streaming (minutes per week)\n");
    printf("Week 1: ");
    scanf("%d", &videoA);
    printf("Week 2: ");
    scanf("%d", &videoB);

    printf("Video Games (minutes per week)\n");
    printf("Week 1: ");
    scanf("%d", &gamesA);
    printf("Week 2: ");
    scanf("%d", &gamesB);

/* === STEP 3: VALIDATE INPUT ===

All six screen-time values must be zero or greater.

The || (OR) operator allows us to check all values in
one condition. If any value is negative, the program stops.
*/
    
    if (socialA < 0 || socialB < 0 || videoA < 0 || videoB < 0 || gamesA < 0 || gamesB < 0) {
        printf("Error: Screen-time values cannot be negative.\n");
        return 1;
    }

/* === STEP 4: CALCULATE RESULTS ===

Calculate the total screen time for each week.

Then divide each weekly total by 7.0 to calculate
the average screen time per day.
*/
   
    totalA = socialA + videoA + gamesA;
    totalB = socialB + videoB + gamesB;

    dailyAverageA = totalA / 7.0;
    dailyAverageB = totalB / 7.0;

/* === STEP 5: DISPLAY BOTH WEEKS === */

    printf("\nMulti-Week Results\n");
    printf("===========================\n");

    printf("Social Media Week 1: %d minutes\n", socialA);
    printf("Social Media Week 2: %d minutes\n", socialB);

    printf("---------------------------\n");

    printf("Video Streaming Week 1: %d minutes\n", videoA);
    printf("Video Streaming Week 2: %d minutes\n", videoB);

    printf("---------------------------\n");

    printf("Games Week 1: %d minutes\n", gamesA);
    printf("Games Week 2: %d minutes\n", gamesB);

    printf("===========================\n");

    printf("Total Screen Time Week 1: %d minutes\n", totalA);
    printf("Daily Average Week 1: %.2f minutes\n", dailyAverageA);

    printf("---------------------------\n");

    printf("Total Screen Time Week 2: %d minutes\n", totalB);
    printf("Daily Average Week 2: %.2f minutes\n", dailyAverageB);

    printf("---------------------------\n");

/* === STEP 6: CHECK RECOMMENDED LIMIT ===

Each week's daily average is compared separately with the recommended daily limit.
*/

    if (dailyAverageA <= recommendedLimit) {
        printf("Status: Week 1 - Within recommended limit.\n");
    } else {
        printf("Status: Week 1 - Above recommended limit.\n"); 
    }

    if (dailyAverageB <= recommendedLimit) {
        printf("Status: Week 2 - Within recommended limit.\n");
    } else {
        printf("Status: Week 2 - Above recommended limit.\n");
    }

/* === STEP 7: COMPARE THE TWO WEEKS ===

Compare overall usage between the two weeks and print whether total screen 
time increased, decreased, or stayed the same. 
*/
    printf("---------------------------\n"); 

    if(totalB > totalA) { 
        printf("Total screen time increased from Week 1 to Week 2.\n");
    } else if (totalB < totalA) {
        printf("Total screen time decreased from Week 1 to Week 2.\n");
    } else {
        printf("Total screen time stayed the same from Week 1 to Week 2.\n");
    }   

    return 0;
}