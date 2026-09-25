/*
=============================================================================
FILE: 04_calendar_navigation.c
PURPOSE: Print and navigate calendars for 2025 using automatic weekday
         calculation, date highlighting, and robust input validation.
=============================================================================
*/

#include <stdio.h>

int main(void) {
/* === STEP 1: GET MONTH NUMBER ===

The user selects the first month to display using a number from 1 to 12.

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

            while (getchar() != '\n');
            monthNumber = 0; 

        } else if (monthNumber < 1 || monthNumber > 12) {
            printf("Invalid choice. Please enter a number between 1 and 12.\n");
        }

    } while (monthNumber < 1 || monthNumber > 12);

/* === STEP 2: STORE MONTH INFORMATION ===

monthNames stores the names of all 12 months.

monthDays stores the correct number of days in each month for 2025.

Both arrays use the same index for the same month.

Because array indexes start at 0, monthNumber - 1 is used
to access the selected month.
*/

    const char* monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    

/* === STEP 3: START CALENDAR NAVIGATION ===

The calendar system continues until the user chooses Exit.

After each calendar is displayed, the user can:

    1 -> move to the previous month
    2 -> move to the next month
    3 -> exit the program
*/ 
    int choice;

    do {

/* === STEP 4: CALCULATE STARTING WEEKDAY ===

1 January 2025 is Wednesday, which is weekday 3.

daysBeforeMonth stores the total number of days before the
selected month.

The for loop adds the number of days from every previous month.

The starting weekday is then calculated using % 7 so that
the result stays within the seven-day week.
*/
        int daysBeforeMonth = 0; 

        for (int i = 0; i < monthNumber - 1; i++) {
            daysBeforeMonth += monthDays[i];
        }

        int startingWeekday;
        startingWeekday = ((3 - 1 + daysBeforeMonth) % 7) + 1;
        
/* === STEP 5: GET NUMBER OF DAYS IN SELECTED MONTH ===

monthNumber - 1 gives the array index of the current month.

This allows the program to use the correct number of days
when printing the calendar and validating the highlighted date.
*/  
    
        int daysInMonth = monthDays[monthNumber - 1];

/* === STEP 6: GET DATE TO HIGHLIGHT ===

The user selects a day within the current month.

The value must be a number and must be between 1 and
the number of days in the selected month.

For example:

    February -> 1 to 28
    April    -> 1 to 30
    July     -> 1 to 31
*/
   
        int highlightDay;

        do {
            printf("Enter a date number: ");

            if (scanf("%d", &highlightDay) != 1) {
                printf("Invalid input. Please enter a number.\n");

                while (getchar() != '\n'); 
                highlightDay = 0; 

            } else if (highlightDay < 1 || highlightDay > daysInMonth) {
                printf("Invalid choice. Please enter a number between 1 and %d.\n",
                        daysInMonth);
            }

            } while (highlightDay < 1 || highlightDay > daysInMonth);

/* === STEP 7: DISPLAY CALENDAR ===

Print the selected month title and the Monday-to-Sunday header.

Empty positions are printed before Day 1 so that it appears
under the weekday calculated automatically by the program.
*/

        printf("\n===================== %s =====================\n", 
                    monthNames[monthNumber - 1]);
           
        printf("\nMon\tTue\tWed\tThu\tFri\tSat\tSun\n");

        for (int i = 1; i < startingWeekday; i++) {
            printf("\t");
        }

/* === STEP 8: PRINT DAYS, HIGHLIGHT DATE, AND COUNT WEEKENDS ===

position keeps track of where each day is printed
in the calendar week.

When the current day matches highlightDay, brackets are
printed around the number.

For example: 14    [15]    16

If position is 6, the current day is Saturday.
If position is 7, the current day is Sunday.

When Sunday is reached, a new line starts and position
returns to Monday (1).
*/
        int position = startingWeekday;

        int saturdayCount = 0;
        int sundayCount = 0;

        for (int day = 1; day <= daysInMonth; day++) {

            if (day == highlightDay) {
                printf("[%d]\t", day);
            } else {
                printf("%d\t", day);
            }

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

Display the number of Saturdays and Sundays in the
currently selected month.
*/
        printf("\n\nSaturdays: %d\n", saturdayCount);
        printf("Sundays: %d\n", sundayCount);


/* === STEP 10: DISPLAY NAVIGATION MENU ===

After viewing the calendar, the user can move to the previous
month, move to the next month, or exit.

The menu repeats until a valid numeric choice from 1 to 3
is entered.
*/
        printf("\n1. Previous Month");
        printf("\n2. Next Month");
        printf("\n3. Exit");

        do {
            printf("\nEnter your choice: ");

            if (scanf("%d", &choice) != 1) {
                printf("Invalid input. Please enter a number.\n");

                while (getchar() != '\n');  // Discard invalid input
                choice = 0;
                continue;
            }

            if (choice < 1 || choice > 3) {
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
            }

        } while (choice < 1 || choice > 3);

/* === STEP 11: NAVIGATE BETWEEN MONTHS ===

Previous Month decreases monthNumber by 1.
Next Month increases monthNumber by 1.

Navigation stays within 2025:

    January  -> cannot move further back
    December -> cannot move further forward

After changing monthNumber, the outer loop repeats and
recalculates the calendar for the new month.
*/        

        if (choice == 1) {

            if (monthNumber > 1) {
                monthNumber--;
            } else {
                printf("You are already at January.\n");
            }

        } else if (choice == 2) {

            if (monthNumber < 12) {
                monthNumber++;
            } else {
                printf("You are already at December.\n");
            }

        } else {
            printf("Exiting the program...\n");
        }

        } while (choice != 3);

        return 0;
}