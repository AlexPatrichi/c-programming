/*
=============================================================================
FILE: 02_multi_day_tracking.c
PURPOSE: Track water intake over multiple days, convert each day's intake
         into litres and cups, and display the total consumption.
=============================================================================
*/

#include <stdio.h>

int main(void) {
/* === STEP 1: DEFINE VARIABLES ===

totalIntake stores the water consumed for the current day in millilitres.

litres and cups store the converted values for the current day.

totalLitres is a running total that accumulates the litres consumed
across all recorded days.

days counts how many days have been recorded.

choice controls whether the while loop continues.
*/
        float totalIntake, litres, cups;
        float totalLitres = 0;

        int days = 0;
        
        char choice = 'y';

/* === STEP 2: TRACK WATER INTAKE OVER MULTIPLE DAYS ===

The while loop continues as long as choice is 'y' or 'Y'.

For each day:
    1. Get the water intake in millilitres.
    2. Convert it into litres and cups.
    3. Display the converted values.
    4. Add the litres to the running total.
    5. Increase the number of days tracked.
*/
        printf("=== Multi-day Tracking ===\n");
        while (choice == 'y' || choice == 'Y') {
            printf("Enter water intake for the day (ml): ");
            scanf("%f", &totalIntake);    
            
            litres = totalIntake / 1000.0;
            cups = totalIntake / 240.0;

            printf("Litres: %.2f L | Cups: %.2f\n", litres, cups);
            
            totalLitres += litres; 
            days++; 

/* === STEP 3: ASK WHETHER TO ADD ANOTHER DAY ===

The leading space in " %c" tells scanf() to skip any leftover
whitespace, including the newline from the previous input.

If the user enters 'y' or 'Y', the loop repeats.
Any other character causes the loop to end.
*/            

            printf("Do you want to enter another day? (y/n): ");
            scanf(" %c", &choice);
        }
        
/* === STEP 4: DISPLAY TRACKING SUMMARY ===

After the loop ends, display:
    • number of days tracked
    • total litres consumed across all days
*/

        printf("\n=== Tracking Summary ===\n");
        printf("Number of days tracked: %d\n", days); 
        printf("Total litres consumed: %.2f L\n", totalLitres);

   return 0; 
}