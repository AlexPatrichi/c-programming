/*
=============================================================================
FILE: 02_correct_month_calendar.c
PURPOSE: Print a single-month calendar for 2025 using the correct number
         of days for the selected month, and count Saturdays and Sundays.
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

/* === STEP 5: DETERMINE NUMBER OF DAYS IN THE MONTH ===

Unlike the previous version, this calendar uses the correct
number of days for each month in 2025.

2025 is not a leap year, so February has 28 days.
*/

    int daysInMonth;

    switch (monthNumber) {

        case 1:
            daysInMonth = 31;
            break;

        case 2:
            daysInMonth = 28;
            break;

        case 3:
            daysInMonth = 31;
            break;

        case 4:
            daysInMonth = 30;
            break;

        case 5:
            daysInMonth = 31;
            break;

        case 6:
            daysInMonth = 30;
            break;

        case 7:
            daysInMonth = 31;
            break;

        case 8:
            daysInMonth = 31;
            break;

        case 9:
            daysInMonth = 30;
            break;

        case 10:
            daysInMonth = 31;
            break;

        case 11:
            daysInMonth = 30;
            break;

        case 12:
            daysInMonth = 31;
            break;
    }

/* === STEP 6: DISPLAY CALENDAR TITLE ===

The selected month is displayed above the calendar grid.
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
            printf("\n====================== July ======================\n");
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

/* === STEP 7: PRINT CALENDAR HEADER AND POSITION DAY 1 ===

The calendar contains seven columns from Monday to Sunday.

Empty positions are printed before Day 1 so that it appears
under the starting weekday selected by the user.
*/
    printf("\nMon\tTue\tWed\tThu\tFri\tSat\tSun\n");

    for (int i = 1; i < startingWeekday; i++) {
        printf("\t");
    }

/* === STEP 8: PRINT CALENDAR DAYS AND COUNT WEEKENDS ===

position keeps track of where each day is printed
in the calendar week (Monday to Sunday).

Each day is printed and position moves forward.

If position is 6, the current day is Saturday.
If position is 7, the current day is Sunday.

When Sunday is reached, a new line starts
and position returns to Monday (1).
*/

    int position = startingWeekday;

    int saturdayCount = 0;
    int sundayCount = 0;

    for (int day = 1; day <= daysInMonth; day++) {

        printf("%d\t", day);

        if (position == 6) {
            saturdayCount++;
        }
       
        if (position == 7) {
            sundayCount++; 
        }

        if (position == 7) {
            printf("\n");
            position = 1;
        } else {
            position++;
        }
    }

/* === STEP 9: DISPLAY WEEKEND TOTALS ===

After the calendar is printed, display how many Saturdays
and Sundays occur in the selected month.
*/

    printf("\nSaturdays: %d\n", saturdayCount);
    printf("Sundays: %d\n", sundayCount);

    return 0;
}