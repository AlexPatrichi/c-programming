/*
=============================================================================
FILE: 01_basic_calendar_grid.c
PURPOSE: Print a basic single-month calendar grid using a user-selected
         month, starting weekday, and a fixed number of 30 days.
=============================================================================
*/

#include <stdio.h>

int main(void) {

/* === STEP 1: GET MONTH NUMBER ===

The user selects a month using a number from 1 to 12.

The do...while loop repeats until a valid month is entered.

scanf() is also checked to make sure the user entered a number.
If scanf() fails, the invalid characters are discarded before
the program asks again.
*/
    int monthNumber; 

    do {
        printf("Enter your month number: ");

        if (scanf("%d", &monthNumber) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n'); // Discard invalid input
            monthNumber = 0; 

        } else if (monthNumber < 1 || monthNumber > 12) {
            printf("Invalid choice. Please enter a number between 1 and 12.\n");
        }

    } while (monthNumber < 1 || monthNumber > 12);

/* === STEP 2: DISPLAY MONTH NAME ===

A switch statement connects each month number to its
corresponding month name.
*/

    switch (monthNumber) {
        case 1: 
            printf("Month: January\n");
            break;
        
        case 2:
            printf("Month: February\n");
            break;

        case 3:
            printf("Month: March\n");
            break;

        case 4:
            printf("Month: April\n");
            break;

        case 5:
            printf("Month: May\n");
            break;

        case 6:
            printf("Month: June\n");
            break;

        case 7:
            printf("Month: July\n");
            break;

        case 8:
            printf("Month: August\n");
            break;

        case 9:
            printf("Month: September\n");
            break;

        case 10:
            printf("Month: October\n");
            break;

        case 11:
            printf("Month: November\n");
            break;

        case 12:
            printf("Month: December\n");
            break;
    } 
    
/* === STEP 3: GET STARTING WEEKDAY ===

The user decides which weekday will contain Day 1.

    1 -> Monday
    2 -> Tuesday
    3 -> Wednesday
    4 -> Thursday
    5 -> Friday
    6 -> Saturday
    7 -> Sunday

The value must be a number between 1 and 7.
*/

    int startingWeekday;

    do {
        printf("\nEnter your starting weekday (1 - Mon, 7 - Sun): ");

        if (scanf("%d", &startingWeekday) != 1) {
           printf("Invalid input. Please enter a number.\n");
           
           while (getchar() != '\n');  // Discard invalid input
           startingWeekday = 0; 

        } else if (startingWeekday < 1 || startingWeekday > 7) {
            printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }

    } while (startingWeekday < 1 || startingWeekday > 7);

/* === STEP 4: DISPLAY STARTING WEEKDAY ===

A switch statement converts the weekday number into
the corresponding weekday name.
*/

    switch (startingWeekday) {
        case 1:
            printf("Starting weekday: Monday\n");
            break;
    
        case 2:
            printf("Starting weekday: Tuesday\n");
            break;

        case 3:
            printf("Starting weekday: Wednesday\n");
            break;

        case 4:
            printf("Starting weekday: Thursday\n");
            break;

        case 5:
            printf("Starting weekday: Friday\n");
            break;

        case 6:
            printf("Starting weekday: Saturday\n");
            break;
        
        case 7:
            printf("Starting weekday: Sunday\n");
            break;
    } 

/* === STEP 5: DISPLAY CALENDAR TITLE ===

The selected month is displayed above the calendar grid.

At this stage the calendar is intentionally not based on
the real number of days in the selected month.
*/

        switch (monthNumber) {
            case 1: 
                printf("\n===================== January =====================\n");
                break;
            
            case 2:
                printf("\n===================== February ====================\n");
                break;
    
            case 3:
                printf("\n===================== March ======================\n");
                break;
    
            case 4:
                printf("\n===================== April ======================\n");
                break;
    
            case 5:
                printf("\n====================== May =======================\n");
                break;
    
            case 6:
                printf("\n====================== June ======================\n");
                break;
    
                case 7:
                    printf("\n==================== July ====================\n");
                break;
    
            case 8:
                printf("\n===================== August =====================\n");
                break;
    
            case 9:
                printf("\n=================== September ====================\n");
                break;
    
            case 10:
                printf("\n==================== October =====================\n");
                break;
    
            case 11:
                printf("\n==================== November ====================\n");
                break;
    
            case 12:
                printf("\n==================== December ====================\n");
                break;
        }

/* === STEP 6: PRINT CALENDAR HEADER ===

The calendar uses seven columns representing Monday through Sunday.
*/

    printf("\nMon\tTue\tWed\tThu\tFri\tSat\tSun\n");

/* === STEP 7: POSITION DAY 1 ===

Before printing Day 1, empty positions are printed according
to the selected starting weekday.

For example, if the month starts on Friday (5):

    Mon  Tue  Wed  Thu  Fri  Sat  Sun
                        1

Four empty positions are needed before Day 1.
*/

    for (int i = 1; i < startingWeekday; i++) {
        printf("\t");
    }

/* === STEP 8: PRINT CALENDAR DAYS ===

position keeps track of where each day is printed
in the calendar week (Monday to Sunday).

The calendar uses a fixed 30 days for this version.

Each day is printed and position moves forward.

When Sunday (7) is reached, a new line starts
and position returns to Monday (1).
*/

    int position = startingWeekday;
    
    for (int day = 1; day <= 30; day++) {
        printf("%d\t", day);

        if (position == 7) {
            printf("\n");
            position = 1;
        } else {
            position++;
        }
    }

    return 0;
}