/*
=============================================================================
FILE: 01_basic_ticket_price.c
PURPOSE: Determine an aquarium ticket price using fixed values
         and a switch statement.
=============================================================================
*/

#include <stdio.h>

int main (void) {

/* === STEP 1: DEFINE TICKET DETAILS ===

This first version uses fixed values and requires no user input.
        • zone: exhibit zone: ‘S’ = Sharks, ‘R’ = Reefs, ‘P’ = Penguins
        • ticketType: ‘N’ = Standard Entry, ‘E’ = Express Entry
        • ticketPrice: price of one ticket, derived from zone + ticketType
*/

    char zone = 'S';
    char ticketType = 'N';

    char *zoneName;
    char *ticketName;

    float ticketPrice;

/* === STEP 2: SELECT EXHIBIT ZONE AND TICKET PRICE ===

The switch statement compares the value stored in zone
with each case.

Only the matching case is executed.

    zone = 'S' -> case 'S'
    zone = 'R' -> case 'R'
    zone = 'P' -> case 'P'

Break ends the matching case and exits the switch.
Default handles a zone that does not match any valid case.
*/

    switch(zone) {
        case 'S':  // exhibit zone: Sharks
            zoneName = "Sharks";
            if(ticketType == 'N') {
                ticketPrice = 22;
                ticketName = "Standard";
            } else if(ticketType == 'E') {
                ticketPrice = 32;
                ticketName = "Express";
            } else {
                printf("Invalid ticket type. Use 'N' or 'E'.\n");
                return 1; 
            }
            break;

        case 'R': // exhibit zone: Reefs
            zoneName = "Reefs";
            if(ticketType == 'N') {
                ticketPrice = 18;
                ticketName = "Standard";
            } else if(ticketType == 'E') {
                ticketPrice = 28;
                ticketName = "Express";
            } else {
                printf("Invalid ticket type. Use 'N' or 'E'.\n");
                return 1; 
            }
            break;

        case 'P': // exhibit zone: Penguins
            zoneName = "Penguins";
            if(ticketType == 'N') {
                ticketPrice = 16;
                ticketName = "Standard";
            } else if(ticketType == 'E') {
                ticketPrice = 26;
                ticketName = "Express";
            } else {
                printf("Invalid ticket type. Use 'N' or 'E'.\n");
                return 1; 
            }
            break;

        default:
            printf("Invalid zone.\n");
            return 1; 
        }

/* === STEP 3: DISPLAY TICKET ===

Display the zone, ticket type, and the ticket price (formatted to 2 d.p.).

    Example Outcome:
    Zone: Sharks
    Ticket Type: Standard
    Ticket Price: £22.00  */

    printf("Ticket\n");
    printf("------------------\n");
    printf("Zone: %s\n", zoneName);
    printf("Ticket Type: %s\n", ticketName);
    printf("Ticket Price: £%.2f\n", ticketPrice);

    return 0;
}

