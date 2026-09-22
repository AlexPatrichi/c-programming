/*
=============================================================================
FILE: 01_basic_weekly_total.c
PURPOSE: Calculate weekly screen time across three categories.
=============================================================================
*/

#include <stdio.h>

int main(void) {

/* === STEP 1: DEFINE SCREEN-TIME CATEGORIES ===

This first version uses three predefined screen-time categories.
The values are stored directly in variables and represent the total
number of minutes spent in each category during one week.
*/ 
    int social = 225; 
    int video = 340; 
    int games = 410; 

/* === STEP 2: CALCULATE WEEKLY TOTAL === 

Add the three categories together to calculate the total
screen time for the week.
*/
    int total = social + video + games;

    
/* === STEP 3: DISPLAY RESULTS === */
    printf("Weekly Screen-Time Tracker\n");
    printf("--------------------------\n");

    printf("Social Media: %d minutes\n", social);
    printf("Video Streaming: %d minutes\n", video);
    printf("Games: %d minutes\n", games);

    printf("--------------------------\n");
    printf("Total Screen Time: %d minutes\n", total);
    
    return 0;
}

