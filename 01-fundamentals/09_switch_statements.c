/*
=============================================================================
FILE: 09_switch_statements.c
PURPOSE: Demonstrates how to use switch statements in C to handle multiple
possible values of a variable in a cleaner way than multiple if-else blocks.
=============================================================================
*/

#include <stdio.h>

int main(void) {
    int score;
        
    printf("Enter your score (0-100): ");
    scanf("%d", &score);

    if (score < 0 || score > 100)
        {
            printf("Invalid score. Please enter a score between 0 and 100.\n");
            return 1; // Program ended because of an error or invalid input 
        }
    /* The if statement validate the input before running the switch.
    The input validation prevent errors and invalid input from breaking the program.*/

    switch (score / 10) { 
    /* Evaluate the variable once, and compares it with different case values. 
    If there is a match, the associated block of code is executed.*/

        
        case 10: // Case 9 and 10 both produce Grade A
        case 9: 
        // Each possible value gets a block of code. 
            printf("Grade: A\n");
            break;
            // break - if the case is made, stops execution from continuing into next case.

        case 8:
            printf("Grade: B\n");
            break;

        case 7:
            printf("Grade: C\n");
            break;

        case 6:
            printf("Grade: D\n");
            break;
    
        default:
        // default - runs if no case matches. 
            printf("Grade: F\n");
    }

    return 0;

}