/*
=============================================================================
FILE: 03_automatic_start_day.c
PURPOSE: Print a calendar for a selected month in 2025 and automatically
         calculate the weekday on which the month begins.
=============================================================================
*/

#include <stdio.h>

int main (void) {
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

            while (getchar() != '\n');  // Discard invalid input
            monthNumber = 0; 

        } else if (monthNumber < 1 || monthNumber > 12) {
            printf("Invalid choice. Please enter a number between 1 and 12.\n");
        }

    } while (monthNumber < 1 || monthNumber > 12);

/* === STEP 2: STORE MONTH INFORMATION ===

monthNames stores the names of all 12 months.

monthDays stores the number of days in each month for 2025.

Both arrays use the same index for the same month:

    index 0 -> January  -> 31 days
    index 1 -> February -> 28 days
    index 2 -> March    -> 31 days
    ...
    index 11 -> December -> 31 days

Because array indexes start at 0, monthNumber - 1 is used
to access the selected month.
*/
    const char *monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

    printf("Month: %s\n", monthNames[monthNumber - 1]); 
    
/* === STEP 3: COUNT DAYS BEFORE THE SELECTED MONTH ===

1 January 2025 is a Wednesday.

Using our weekday numbering:

    1 -> Monday
    2 -> Tuesday
    3 -> Wednesday
    4 -> Thursday
    5 -> Friday
    6 -> Saturday
    7 -> Sunday

daysBeforeMonth stores the total number of days that have passed
before the first day of the selected month.

For example, if March is selected:

    January  = 31 days
    February = 28 days

    daysBeforeMonth = 59
*/
    int daysBeforeMonth = 0; 

    for (int i = 0; i < monthNumber - 1; i++) {
        daysBeforeMonth += monthDays[i];
    }

/* === STEP 4: CALCULATE STARTING WEEKDAY ===

January 1, 2025 is Wednesday, which is weekday 3.

daysBeforeMonth tells us how many days we need to move forward
from January 1 to reach the selected month.

% 7 keeps the result inside a seven-day week.

The -1 and +1 are needed because our weekday numbers are 1 to 7,
while modulo arithmetic naturally works with values 0 to 6.

The final result is:

    1 -> Monday
    ...
    7 -> Sunday
*/
    int startingWeekday;

    startingWeekday = ((3 - 1 + daysBeforeMonth) % 7) + 1;

/* === STEP 5: GET NUMBER OF DAYS IN SELECTED MONTH ===

monthNumber - 1 gives the array index of the selected month.

For example:

    monthNumber = 2        -> February
    monthNumber - 1 = 1    -> array index 1
    monthDays[1] = 28
*/
    int daysInMonth = monthDays[monthNumber - 1];

/* === STEP 6: DISPLAY CALENDAR ===

Print the selected month title and the Monday-to-Sunday header.

Empty positions are printed before Day 1 so that it appears
under the weekday calculated by the program.
*/

    printf("\n===================== %s =====================\n", monthNames[monthNumber - 1]);
           
    printf("\nMon\tTue\tWed\tThu\tFri\tSat\tSun\n");

    for (int i = 1; i < startingWeekday; i++) {
        printf("\t");
    }

/* === STEP 7: PRINT CALENDAR DAYS AND COUNT WEEKENDS ===

position starts at the calculated weekday for Day 1.

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

/* === STEP 8: DISPLAY WEEKEND TOTALS ===

After the calendar is printed, display how many Saturdays
and Sundays occur in the selected month.
*/
    printf("\n\nSaturdays: %d\n", saturdayCount);
    printf("Sundays: %d\n", sundayCount);

    return 0;
}