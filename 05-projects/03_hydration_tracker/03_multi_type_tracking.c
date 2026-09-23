/*
=============================================================================
FILE: 03_multi_type_tracking.c
PURPOSE: Track water intake using multiple input types, convert each entry
         into millilitres, and display the total consumption.
=============================================================================
*/

#include <stdio.h>

int main(void) {
/* === STEP 1: DEFINE TRACKING VARIABLES ===

totalIntake stores the total amount of water consumed in millilitres.

mlCount, bottleCount, and cupCount count how many entries
of each type have been recorded.

choice controls whether the tracking loop continues.
option stores the user's menu selection.

thisEntry stores the current entry after it has been
converted into millilitres.
*/

   float totalIntake = 0; 

   int mlCount = 0; 
   int bottleCount = 0;
   int cupCount = 0;

   char choice = 'Y';  
   int option;

   float thisEntry;
   float mlAmount; 
   int bottleAmount;
   int cupAmount;

/* === STEP 2: DISPLAY MENU AND GET USER'S CHOICE ===

The while loop continues as long as choice is 'y' or 'Y'.
For each entry, the user can choose:
            • 1: Millilitres (ml)
            • 2: Bottles (assume 1 bottle = 500 ml)
            • 3: Cups (assume 1 cup = 240 ml)

Regardless of the selected unit, the amount will eventually
be converted into millilitres.
*/  
   printf("\n--- Multi-Type Tracking ---\n");
   while (choice == 'y' || choice == 'Y') {
      printf("What would you like to add?\n\t1. Millilitres\n\t2. Bottles (500 ml each)\n\t3. Cups (240 ml each)\n"); // Show menu
      printf("Enter your choice: "); 
      scanf("%d", &option); // Get user choice

/* === STEP 3: VALIDATE MENU CHOICE ===

Only options 1, 2, and 3 are valid.

If the user enters a number outside this range, continue
skips the rest of the current loop iteration and returns
to the menu.
*/
      if(option < 1 || option > 3) {
         printf("Invalid choice. Try again!\n");
         continue;
         }
            
/* === STEP 4: PROCESS AND CONVERT THE SELECTED ENTRY ===

The switch statement determines which type of water intake
the user wants to record.

All input types are converted into millilitres:

    Millilitres -> amount entered directly
    Bottles     -> number of bottles × 500
    Cups        -> number of cups × 240

The converted amount is stored in thisEntry and then added
to the running total.

The appropriate counter is also increased by 1 to record
one entry of that type.
*/           
      switch (option) {
         case 1:
            printf("How many ml? Entry: "); // Ask for quantity
            scanf("%f", &mlAmount);

            // ml entry input validation
            if(mlAmount <= 0) {
               printf("Invalid amount. Try again!\n");
               break;
            }

            thisEntry = mlAmount;  // Add it to total intake
            totalIntake += thisEntry;
            mlCount++; // Update counters

            printf("Added: %.2f ml.\n", thisEntry); // Confirmation
            break;
            
         case 2:
            printf("How many bottles? Entry: "); // Ask for quantity 
            scanf("%d", &bottleAmount);

            // bottles entry input validation
            if(bottleAmount <= 0) {
               printf("Invalid amount. Try again!\n");
               break;
            }

            thisEntry = bottleAmount * 500; // Convert to ml
            totalIntake += thisEntry; // Add it to total intake
            bottleCount++; // Update counters

            printf("Added: %.2f ml.\n", thisEntry); // Confirmation
            break;
            
         case 3:
            printf("How many cups? Entry: "); // Ask for quantity
            scanf("%d", &cupAmount);

            // cups entry input validation
            if(cupAmount <= 0) {
               printf("Invalid amount. Try again!\n");
               break;
            }

            thisEntry = cupAmount * 240; // Convert to ml
            totalIntake += thisEntry; // Add it to total intake
            cupCount++; // Update counters

            printf("Added: %.2f ml.\n", thisEntry); // Confirmation
            break;
      }

/* === STEP 5: ASK WHETHER TO ADD ANOTHER ENTRY ===

A do...while loop is used because the question must be
asked at least once.

The leading space in " %c" tells scanf() to skip leftover
whitespace before reading the character.

    Y / y -> return to the menu
    N / n -> finish tracking

Any other character repeats the question.
*/
         do {
            printf("\nAdd another entry? (Y/N): "); // New entry or exit
            scanf(" %c", &choice); // note the space before %c

            if (choice != 'y' && choice != 'Y' &&
                choice != 'n' && choice != 'N') {
                printf("Invalid input. Please enter Y or N.\n");
         }

         } while (choice != 'y' && choice != 'Y' &&
                 choice != 'n' && choice != 'N');
   }  
                    
/* === STEP 6: DISPLAY MULTI-TYPE SUMMARY ===

After the tracking loop ends, display:

    • total water intake in millilitres
    • total water intake converted into litres
    • number of entries recorded for each input type

The counters represent the number of entries, not the
number of individual bottles or cups consumed.
*/
   printf("\n=== Multi-Type Summary ===\n");
   printf("Total: %.2f ml (%.2f L)\n", totalIntake, totalIntake / 1000.0);
   printf("Bottles: %d, Cups: %d, Millilitres: %d\n", bottleCount, cupCount, mlCount);

   return 0; 
}