/*
=============================================================================
FILE: 02_multi_ticket_total.c
PURPOSE: Calculate the total cost of multiple aquarium tickets
         using user input and a switch statement.
=============================================================================
*/

#include <stdio.h>

int main (void) {

/* === STEP 1: DEFINE VARIABLES AND GET USER INPUT ===

Prompt the user to select:
• Zone (S, R, P)
• Ticket type (N, E)
• Number of tickets (integer)  

The leading space before %c tells scanf() to skip any
whitespace before reading the character. 
*/

    char zone;
    char ticketType;

    float ticketPrice;
    float totalCost;

    int quantity; 

    printf("========Ticket Options========\n");

    printf("Enter Zone (S = Sharks, R = Reefs, P = Penguins): ");
    scanf(" %c", &zone);

    printf("Enter Ticket Type (N = Standard, E = Express): ");
    scanf(" %c", &ticketType);

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

/* === STEP 2: VALIDATE TICKET QUANTITY ===

At least one ticket must be purchased.

If quantity is zero or negative, the program displays
an error and stops.
*/
    if (quantity <= 0) {
        printf("Invalid request.\n");
        return 1;
    }

/* === STEP 3: DETERMINE TICKET PRICE ===

The switch-case structure selects the exhibit zone. 

Inside each case, an if / else if statement determines whether the ticket 
is Standard or Express and assigns the corresponding price.

Price table:

                 Standard    Express
    Sharks         £22         £32
    Reefs          £18         £28
    Penguins       £16         £26

Invalid zones and ticket types cause the program to stop. */

    switch(zone) {
        case 'S':  // exhibit zone: Sharks
            if(ticketType == 'N') { // Standard
                ticketPrice = 22;
            } else if(ticketType == 'E') { // Express
                ticketPrice = 32;
            } else {
                printf("Invalid ticket type.\n");
                return 1; 
        }
        break;

        case 'R': // exhibit zone: Reefs
            if(ticketType == 'N') {
                ticketPrice = 18;
            } else if(ticketType == 'E') {
                ticketPrice = 28;
            } else {
                printf("Invalid ticket type.\n");
                return 1; 
        }
        break;

        case 'P': // exhibit zone: Penguins
            if(ticketType == 'N') {
                ticketPrice = 16;
            } else if(ticketType == 'E') {
                ticketPrice = 26;
            } else {
                printf("Invalid ticket type.\n");
                return 1; 
        }   
        break;

    default:
        printf("Invalid zone.\n");
        return 1; 
    }

/* === STEP 4: CALCULATE TOTAL COST ===

All tickets in the purchase are for the same zone and
ticket type.

The total cost is therefore:

    totalCost = price of one ticket * number of tickets
*/

    totalCost = ticketPrice * quantity;

/* === STEP 5: DISPLAY RECEIPT ===

A second switch statement converts the zone character
into the full exhibit name for the receipt.

The ticket type is displayed using its corresponding name,
followed by the quantity and total purchase cost.
*/

    printf("\n========== RECEIPT ==========\n");

    printf("Zone: ");
    switch(zone) {
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
    printf("Total Cost: £%.2f\n", totalCost);

    return 0;
}
