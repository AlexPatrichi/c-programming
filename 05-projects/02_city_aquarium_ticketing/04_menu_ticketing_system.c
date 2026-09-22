/*
=============================================================================
FILE: 04_menu_ticketing_system.c
PURPOSE: Create a menu-driven aquarium ticketing system that allows users
         to book tickets, view ticket prices, and exit the program.
=============================================================================
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
/* === STEP 1: DEFINE MENU VARIABLE ===

menuOption stores the user's selection from the main menu:
    • Option 1: Book tickets
    • Option 2: View ticket prices 
    (show the table for Sharks/Reefs/Penguins with Standard/Express)
    • Option 3: Exit the program*/

    int menuOption;

/* === STEP 2: DISPLAY THE REPEATING MAIN MENU ===

while (1) creates a loop that continues until the program
explicitly exits it with break or return.

This allows the user to use the menu repeatedly without
restarting the program.
*/

    while(1) {
        printf("\n=== City Aquarium Ticketing ===\n");
        printf("1. Book Tickets\n");
        printf("2. View Ticket Prices\n");
        printf("3. Exit\n");    
        printf("Enter choice:");

/* === STEP 3: VALIDATE MENU INPUT ===

Check that the user enters a number for the menu choice.

If invalid input is entered, discard the remaining characters
and restart the menu using continue.
 */
        if(scanf("%d", &menuOption) != 1) {   // Read the number
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');         // Discard remaining invalid input
            continue;                         // Go back to menu
        }
        while(getchar() != '\n');             // Discard newline after number

/* If the user selects option 3, break exits the while loop
and the program reaches return 0.
*/
        if(menuOption == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        
/* === STEP 4: PROCESS MENU OPTION ===

The switch statement determines which menu option is performed.

    1 -> Book tickets
    2 -> View ticket prices

Option 1 reuses the ticket booking logic developed in the
previous versions of the program.
*/

    switch(menuOption) {
        case 1: {
            char zone;
            char ticketType;
            char addOn;
            char again;

            int quantity;

            float ticketPrice = 0; 
            float total = 0;
            float totalDiscount = 0;
            float totalAddon = 0;

            const float addonPrice = 4.50;

            printf("\n========Ticket Options========\n");

            printf("Enter Zone (S = Sharks, R = Reefs, P = Penguins): ");
            scanf(" %c", &zone);

            printf("Enter Ticket Type (N = Standard, E = Express): ");
            scanf(" %c", &ticketType);

            printf("Enter Quantity: ");
            scanf("%d", &quantity);

            printf("Optional Add-on: Audio Guide for £4.50 per ticket.(Y/N)");
            scanf(" %c", &addOn);
    
            // Normalize user input to uppercase
            addOn = toupper(addOn); 
            zone = toupper(zone);
            ticketType = toupper(ticketType);

/* === STEP 5: VALIDATE BOOKING DETAILS ===

Before performing any calculations, check that:

    • quantity is greater than 0
    • zone is S, R, or P
    • ticket type is N or E
    • add-on selection is Y or N

If any value is invalid, break exits case 1 and returns
the user to the main menu.
*/

            if(quantity <= 0) {
                printf("Invalid request.\n");
                break;
            }

            if(zone != 'S' && zone != 'R' && zone != 'P') {
                printf("Invalid zone.\n");
                break;
            }

            if(ticketType != 'N' && ticketType != 'E') {
                printf("Invalid ticket type.\n");
                break;
            }

            if(addOn != 'Y' && addOn != 'N') {
                printf("Invalid add-on choice.\n");
                break;
            }

/* Determine the price of one ticket based on the selected
zone and ticket type.
*/
            switch(zone) {
                case 'S':  // exhibit zone: Sharks
                    if(ticketType == 'N') { // Standard
                        ticketPrice = 22;
                    } else if(ticketType == 'E') { // Express
                        ticketPrice = 32;
                    } 
                    break;

                case 'R': // exhibit zone: Reefs
                    if(ticketType == 'N') {
                        ticketPrice = 18;
                    } else if(ticketType == 'E') {
                        ticketPrice = 28;
                    }
                    break;

                case 'P': // exhibit zone: Penguins
                    if(ticketType == 'N') {
                        ticketPrice = 16;
                    } else if(ticketType == 'E') {
                        ticketPrice = 26;
                    }
                    break;

                default:
                    printf("Invalid zone.\n");
                    break; 
                }
                
/* === STEP 6: CALCULATE TICKET COSTS ===

First calculate the total ticket cost.

If more than 5 tickets are purchased, calculate a 15%
bulk discount and subtract it from the total.

If the Audio Guide was selected, add £4.50 per ticket.
*/

            // Calculate total before discount
            total = ticketPrice * quantity;

            // Apply 15% discount if more than 5 tickets are purchased
            if(quantity > 5) {
                totalDiscount = total * 0.15;
            }

            // Apply discount
            total = total - totalDiscount;

            // Optional add‑on if the user wants an Audio Guide (y/n) at £4.50 per ticket
            if(addOn == 'Y') {
                totalAddon = quantity * addonPrice;    
            } 
   
/* === STEP 7: DISPLAY RECEIPT ===

Display:
    • exhibit zone
    • ticket type
    • number of tickets
    • total before discount
    • bulk discount
    • add-on cost
    • final total
*/

            printf("\n========== RECEIPT ==========\n");

            printf("Zone: ");
            switch (zone) {
                case 'S':
                    printf("Sharks\n");
                    break;

                case 'R':
                    printf("Reefs\n");
                    break;

                case 'P':
                    printf("Penguins\n");
                    break;

                default:
                    printf("Error");
                    break;
            }

            printf("Ticket Type: ");
            if(ticketType == 'N') {
                printf("Standard\n");
            } else if(ticketType == 'E') {
                printf("Express\n");
            }

            printf("Tickets: %d\n", quantity);
            printf("Total Before Discount: £%.2f\n", quantity * ticketPrice);

            printf("Bulk Discount: £%.2f\n", totalDiscount);
            printf("Add-on Cost: £%.2f\n", totalAddon);

            printf("-----------------------------\n");
            printf("Final Total: £%.2f\n", total + totalAddon);

/* === STEP 8: RETURN TO MENU OR EXIT ===

After completing a booking, ask whether the user wants
to return to the main menu.

A do...while loop is used because the question must be
asked at least once.

    'Y' -> return to the main menu
    'N' -> exit the program

Invalid answers repeat the question.
*/
            do {
                printf("\nReturn to menu? (Y/N): ");
                scanf(" %c", &again);

                again = toupper(again);

                if(again != 'Y' && again != 'N') {
                   printf("Invalid input. Please enter Y or N.\n");
                }

            } while(again != 'Y' && again != 'N');

            if(again == 'N') {
               printf("Exiting the program. Goodbye!\n");
               return 0;
            }

             break;
        }

/* Option 2 displays the ticket price table and then returns
to the main menu.
*/

        case 2:
            printf("\n=== Ticket Prices ===\n");
            printf("Zone\t\tStandard\tExpress\n");
            printf("Sharks\t\t£22\t\t£32\n");
            printf("Reefs\t\t£18\t\t£28\n");
            printf("Penguins\t£16\t\t£26\n"); 
            break;

        default:
            printf("Invalid option.\n Please, try again.\n\n");
            break;
        }
    }

    return 0;
}