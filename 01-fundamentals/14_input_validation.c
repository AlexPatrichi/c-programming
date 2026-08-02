/*
=============================================================================
FILE: 14_input_validation.c

PURPOSE:
Demonstrates safe user input handling in C by validating numeric input,
range constraints, and user choice (Y/N) using loops and buffer clearing.
=============================================================================
*/

#include <stdio.h>
int main (void) {

    // Variables to store input
    int number; 
    char answer = 'Y';

    do {
        /* -------- NUMBER VALIDATION -------- */
        do {
            printf("Enter a number between 1 and 100: ");
            scanf("%d", &number);
        } while (number < 1 || number > 100);

        printf("Valid number entered: %d\n", number);

        printf("Do you want to continue? Y/N: ");
        scanf(" %c", &answer);

    } while (answer == 'Y' || answer == 'y');

    /* Input validation makes sure the input is correct before the program continues. 
    Without it, the program might crash or give the wrong result. */ 
    // Input validation ALWAYS uses loops.
    return 0;
}