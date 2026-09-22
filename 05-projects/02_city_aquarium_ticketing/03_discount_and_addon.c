/*
=============================================================================
FILE: 03_discount_and_addon.c
PURPOSE: Calculate aquarium ticket costs with a bulk discount
         and an optional Audio Guide add-on.
=============================================================================
*/

#include <stdio.h>
#include <ctype.h> 

int main(void) {

/* === STEP 1: DEFINE VARIABLES AND GET USER INPUT ===

The user selects:
    • exhibit zone
    • ticket type
    • number of tickets
    • whether they want an Audio Guide

The Audio Guide costs £4.50 per ticket.

This version introduces two additional costs:
    • a 15% bulk discount when more than 5 tickets are purchased
    • an optional Audio Guide add-on
*/
    char zone;
    char ticketType;
    char addOn;

    int quantity;

    float ticketPrice = 0; 
    float total = 0;
    float totalDiscount = 0;
    float totalAddon = 0;

    const float addonPrice = 4.50;

    printf("========Ticket Options========\n");

    printf("Enter Zone (S = Sharks, R = Reefs, P = Penguins): ");
    scanf(" %c", &zone);

    printf("Enter Ticket Type (N = Standard, E = Express): ");
    scanf(" %c", &ticketType);

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    printf("Optional Add-on: Audio Guide for £4.50 per ticket.(Y/N)");
    scanf(" %c", &addOn);
    
/* === STEP 2: NORMALIZE CHARACTER INPUT ===

toupper() converts lowercase letters to uppercase.

This allows the program to accept either uppercase or lowercase input.
For example, both 's' and 'S' can be used to select Sharks.
*/
    addOn = toupper(addOn); 
    zone = toupper(zone);
    ticketType = toupper(ticketType);

/* === STEP 3: VALIDATE USER INPUT ===

The program checks that:
    • quantity is greater than 0
    • zone is S, R, or P
    • ticket type is N or E
    • add-on selection is Y or N

If any value is invalid, the program displays an error
and stops.
*/
    if(quantity <= 0) {
        printf("Invalid request.\n");
        return 1;
    }

    if(zone != 'S' && zone != 'R' && zone != 'P') {
        printf("Invalid zone.\n");
        return 1;
    }

    if(ticketType != 'N' && ticketType != 'E') {
        printf("Invalid ticket type.\n");
        return 1;
    }

    if(addOn != 'Y' && addOn != 'N') {
        printf("Invalid add-on selection.\n");
        return 1;
    }

/* === STEP 4: DETERMINE TICKET PRICE ===

The switch statement selects the exhibit zone.

The ticket type then determines whether the Standard or Express 
price is used.
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
            return 1; 
    }

/* === STEP 5: CALCULATE TICKET TOTAL ===

First calculate the cost of all tickets before applying
the bulk discount or adding the optional Audio Guide. 
*/
    total = ticketPrice * quantity;

/* === STEP 6: APPLY BULK DISCOUNT ===

If more than 5 tickets are purchased, a 15% discount is calculated from the ticket total.*/
    if(quantity > 5) {
        totalDiscount = total * 0.15;
    }

    // The discount is then subtracted from the ticket total.
    total = total - totalDiscount;

/* === STEP 7: CALCULATE OPTIONAL ADD-ON ===

If the user selects 'Y', an Audio Guide is added for
every ticket purchased.

If the user selects 'N', totalAddon remains £0.
*/
    if(addOn == 'Y') {
        totalAddon = quantity * addonPrice;    
    } 
   
/* === STEP 8: DISPLAY RECEIPT ===

Display:
    • exhibit zone
    • ticket type
    • number of tickets
    • total before discount
    • bulk discount
    • add-on cost
    • final total

The final cost is the discounted ticket total plus
the optional add-on cost.
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

    return 0;
} 
