/*
=============================================================================
FILE: 01_basic_conversion.c
PURPOSE: Convert a single day's water intake from millilitres
         into litres and cups.
=============================================================================
*/

#include <stdio.h>

int main(void) {

/* === STEP 1: DEFINE VARIABLES AND GET WATER INTAKE ===

totalIntake stores the amount of water consumed during the day
in millilitres.

litres and cups will store the converted values.
*/
 
        float totalIntake, litres, cups;

/* === STEP 2: PROMPT USER FOR INPUT === */

        printf("Enter water intake for today (ml): ");
        scanf("%f", &totalIntake);

/* === STEP 3:  CONVERT MILLILITRES === 

Use the following fixed conversion rates:
        1 litre = 1000 ml
        1 cup   = 240 ml

To convert millilitres:
    litres = millilitres / 1000
    cups   = millilitres / 240
*/

        litres = totalIntake / 1000.0;
        cups = totalIntake / 240.0; 

/* === STEP 4: DISPLAY DAILY WATER INTAKE ===

Display the original water intake and its equivalent
in litres and cups.

%.2f displays each floating-point value to 2 decimal places.
*/
        printf("\n=== Daily Water Intake ===\n");
        printf("Water intake for today: %.2f ml\n", totalIntake);
        printf("Litres: %.2f L\n", litres);
        printf("Cups (240ml): %.2f cups\n", cups);

   return 0; 
}