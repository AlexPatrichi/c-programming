/*
=====================================================================================
FILE: 04_daily_goal_tracker.c
PURPOSE: Track water intake over multiple days using millilitres, bottles, and cups.
         Includes a daily goal, environment adjustment, progress tracking,
         per-day summaries, overall totals, and longest goal streak.
=====================================================================================
*/

#include <stdio.h>

int main(void) {
/* === STEP 1: DEFINE TRACKING VARIABLES ===

dailyTotal stores the water consumed during the current day in millilitres.

overallTotal accumulates the water consumed across all tracked days.

goalLitres stores the user's original daily hydration goal.
goalMl stores the same goal converted into millilitres.
adjustedGoalMl stores the goal after the environment adjustment.

thisEntry stores the current entry after conversion into millilitres.

progress stores today's progress towards the adjusted daily goal
as a percentage.

daysMetGoal, currentStreak, and longestStreak are used to track
how consistently the daily hydration goal is reached.
*/

    float dailyTotal;
    float overallTotal = 0;

    float goalLitres;
    float goalMl;
    float adjustedGoalMl;

    float thisEntry = 0;
    float mlAmount;
    float progress;

    int numDays;
    int day;

    int mlCount = 0;
    int bottleCount = 0;
    int cupCount = 0;

    int option;
    int environmentChoice;

    int bottleAmount;
    int cupAmount;

    int daysMetGoal = 0;
    int currentStreak = 0;
    int longestStreak = 0;

    char choice;

/* === STEP 2: SET DAILY HYDRATION GOAL ===

The user enters a daily hydration goal in litres.

A do...while loop ensures that the value is positive.
The goal is then converted into millilitres because all water
entries in the program eventually use millilitres as the common unit.

    litres × 1000 = millilitres
*/

    do {
        printf("Enter your daily hydration goal in litres: ");

        if (scanf("%f", &goalLitres) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');  // Discard invalid input
            goalLitres = 0;
            continue;
        }

        if (goalLitres <= 0) {
            printf("Invalid amount. Please enter a positive value.\n");
        }

    } while (goalLitres <= 0);

    goalMl = goalLitres * 1000;
    
/* === STEP 3: SELECT ENVIRONMENT / ACTIVITY LEVEL ===

The environment factor adjusts the suggested daily hydration target:

    1 -> Cool / Indoor      = no adjustment
    2 -> Warm / Active      = +10%%
    3 -> Hot / Very Active  = +20%%

The menu repeats until the user selects a valid option.
*/
    printf("\nChoose environment/activity level:\n");
    printf("1. Cool/Indoor: No Adjustment\n");
    printf("2. Warm/Active: +10%% target\n");
    printf("3. Hot/Very Active: +20%% target\n");

    do {
        printf("Enter your choice: ");
        if (scanf("%d", &environmentChoice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');
            environmentChoice = 0;
            continue;
        }

        if (environmentChoice < 1 || environmentChoice > 3) {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

    } while (environmentChoice < 1 || environmentChoice > 3);

/* Calculate the adjusted daily target based on the selected
environment/activity level.
*/
    switch (environmentChoice) {
        case 1:
            adjustedGoalMl = goalMl; /* 2.1 Cool/Indoor: no adjustment */
            break;

        case 2:
            adjustedGoalMl = goalMl * 1.10; /* 2.2 Warm/Active: +10% suggested daily target */
            break;

        case 3:
            adjustedGoalMl = goalMl * 1.20; /* 2.3 Hot/Very Active: +20% suggested daily target */
            break;
    }

    printf("\nAdjusted daily target: %.2f ml | %.2f litres\n",
           adjustedGoalMl, adjustedGoalMl / 1000.0);

/* === STEP 4: GET NUMBER OF DAYS TO TRACK ===

The user chooses how many days will be recorded.

The value must be positive, so the do...while loop repeats
until a valid number of days is entered.
*/
    do { // Number of days to track
        printf("\nHow many days do you want to track? ");
        if (scanf("%d", &numDays) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');
            numDays = 0;
            continue;
        }

        if (numDays <= 0) {
            printf("Invalid number. Please enter a positive number of days.\n");
        }

    } while (numDays <= 0);

/* === STEP 5: TRACK WATER INTAKE FOR EACH DAY ===

The for loop controls which day is currently being recorded.

At the beginning of every new day:

    dailyTotal = 0

This ensures that each day starts with its own empty total.

choice is reset to 'Y' so the user can begin adding entries
for the new day.
*/

    printf("\n--- Water Intake Tracker ---\n");

    for (day = 1; day <= numDays; day++) {

        dailyTotal = 0;
        choice = 'Y';

        printf("\n==============================\n");
        printf("Day %d\n", day);
        printf("==============================\n");

/* === STEP 6: ADD WATER ENTRIES ===

The user can add multiple entries during the current day.

Each entry can be:

    1 -> Millilitres
    2 -> Bottles (500 ml each)
    3 -> Cups (240 ml each)

The menu repeats until a valid option is selected.
*/
        while (choice == 'y' || choice == 'Y') {

            thisEntry = 0;

            printf("\nWhat would you like to add?\n");
            printf("1. Millilitres\n");
            printf("2. Bottles (500 ml each)\n");
            printf("3. Cups (240 ml each)\n");

            do {
                printf("Enter your choice: ");
                if (scanf("%d", &option) != 1) {
                    printf("Invalid input. Please enter a number.\n");

                    while (getchar() != '\n');
                    option = 0;
                    continue;
                }

                if (option < 1 || option > 3) {
                    printf("Invalid choice. Please enter 1, 2, or 3.\n");
                }

            } while (option < 1 || option > 3);

/* Convert the selected input type into millilitres.

Each amount must be positive, so invalid values are repeatedly
requested until a valid amount is entered.

The converted value is added to dailyTotal and the appropriate
entry counter is increased.
*/
            switch (option) {

                case 1:
                    do {
                        printf("How many ml? Entry: ");
                        if (scanf("%f", &mlAmount) != 1) {
                            printf("Invalid input. Please enter a number.\n");

                            while (getchar() != '\n');
                            mlAmount = 0;
                            continue;
                        }

                        if (mlAmount <= 0) {
                            printf("Invalid amount. Please enter a positive value.\n");
                        }

                    } while (mlAmount <= 0);

                    thisEntry = mlAmount;
                    dailyTotal += thisEntry;
                    mlCount++;

                    printf("Added: %.2f ml.\n", thisEntry);
                    break;

                case 2:
                    do {
                        printf("How many bottles? Entry: ");
                        if (scanf("%d", &bottleAmount) != 1) {
                            printf("Invalid input. Please enter a number.\n");

                            while (getchar() != '\n');
                            bottleAmount = 0;
                            continue;
                        }

                        if (bottleAmount <= 0) {
                            printf("Invalid amount. Please enter a positive value.\n");
                        }

                    } while (bottleAmount <= 0);

                    thisEntry = bottleAmount * 500;
                    dailyTotal += thisEntry;
                    bottleCount ++;

                    printf("Added: %.2f ml.\n", thisEntry);
                    break;

                case 3:
                    do {
                        printf("How many cups? Entry: ");
                        if (scanf("%d", &cupAmount) != 1) {
                            printf("Invalid input. Please enter a number.\n");

                            while (getchar() != '\n');
                            cupAmount = 0;
                            continue;
                        }

                        if (cupAmount <= 0) {
                            printf("Invalid amount. Please enter a positive value.\n");
                        }

                    } while (cupAmount <= 0);

                    thisEntry = cupAmount * 240;
                    dailyTotal += thisEntry;
                    cupCount ++;

                    printf("Added: %.2f ml.\n", thisEntry);
                    break;
            }
/* === STEP 7: CALCULATE DAILY GOAL PROGRESS ===

After every entry, calculate how much of the adjusted daily
hydration target has been reached.

    progress = daily total / adjusted goal × 100

The percentage can exceed 100% if the user drinks more than
the daily target.
*/
            progress = (dailyTotal / adjustedGoalMl) * 100;

            printf("Day %d total: %.2f ml / %.2f litres\n",
                   day, dailyTotal, dailyTotal / 1000);
            printf("Progress towards daily goal: %.2f%%\n", progress);

            if (dailyTotal >= adjustedGoalMl) {
                printf("Daily goal reached!\n");
            }

/* Ask whether another water entry should be recorded
for the current day.

The question repeats until Y/y or N/n is entered.
*/
            do {  // Allow the user to return to the menu or exit after each entry 
                printf("\nAdd another entry for Day %d? (Y/N): ", day);
                scanf(" %c", &choice);

                if (choice != 'y' && choice != 'Y' &&
                    choice != 'n' && choice != 'N') {
                    printf("Invalid input. Please enter Y or N.\n");
                }

            } while (choice != 'y' && choice != 'Y' &&
                     choice != 'n' && choice != 'N');
        }

/* === STEP 8: DISPLAY DAILY SUMMARY AND UPDATE STREAK ===

At the end of each day, display the day's total.

If the adjusted daily goal was reached:

    • increase daysMetGoal
    • increase currentStreak
    • update longestStreak if necessary

If the goal was not reached, currentStreak resets to 0.

The day's intake is then added to overallTotal.
*/
        printf("\n--- Day %d Summary ---\n", day);
        printf("Total intake: %.2f ml\n", dailyTotal);
        printf("Total intake: %.2f litres\n", dailyTotal / 1000);

        if (dailyTotal >= adjustedGoalMl) {
            printf("Result: Goal met or exceeded.\n");
            daysMetGoal++;
            currentStreak++;

            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
            }

        } else {
            printf("Result: Goal not reached.\n");
            currentStreak = 0;
        }

        overallTotal += dailyTotal;
    }

/* === STEP 9: DISPLAY FINAL OVERALL SUMMARY ===

After all days have been processed, display:

    • overall intake in millilitres and litres
    • adjusted daily goal
    • number of days tracked
    • number of days meeting or exceeding the goal
    • longest consecutive goal streak
    • number of entries recorded for each input type
*/

    printf("\n=================================\n");
    printf("Final Overall Summary\n");
    printf("=================================\n");

    printf("Overall total intake: %.2f ml\n", overallTotal);
    printf("Overall total intake: %.2f litres\n", overallTotal / 1000);
    printf("Daily goal used: %.2f ml | %.2f litres\n",
           adjustedGoalMl, adjustedGoalMl / 1000);

    printf("\nDays tracked: %d\n", numDays);
    printf("Days meeting/exceeding goal: %d\n", daysMetGoal);
    printf("Longest streak meeting goal: %d day(s)\n", longestStreak);

    printf("\nEntries recorded across all days:\n");
    printf("Millilitre entries: %d\n", mlCount);
    printf("Bottles recorded: %d\n", bottleCount);
    printf("Cups recorded: %d\n", cupCount);

    return 0;
}