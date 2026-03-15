/*
=============================================================================
FILE: 11_do_while_loop.c
PURPOSE: Demonstrates a do-while loop in C to repeat code until a valid 
input is received (input validation example).
=============================================================================
*/

/*do-while vs for loop:
We use a while loop when the number of iterations is unknown and a 
for loop when the number of iterations is known.
*/

/* Note:
   A while loop checks the condition before running the code, so it may never
   execute if the condition is false at the start.

   A do-while loop runs the code first and checks the condition afterward.
   This guarantees the loop executes at least once.
*/
#include <stdio.h>

int main(void) {
    /*In 09_switch_statements.c file, we checked grades once and exited on invalid input.
    
    Here, we use a defensive programming method introducing a do-while loop to repeat 
    the input until a valid score between 0 and 100 is entered. The program keeps asking automatically if
    the input is invalid, and only proceeds to the switch statement when a valid score is entered.
    */

    int score;

    do {
        printf("Enter your score (0-100): ");
        scanf("%d", &score);

        if (score < 0 || score > 100) {
            printf("Invalid score. Please enter a value between 0 and 100.\n");
        }

    } while (score < 0 || score > 100);
    // Repeat until the user enters a valid score
    // Loops are handy because they save time, reduce errors, and they make code more readable.

    switch (score / 10) {

        case 10:
        case 9:
            printf("Grade: A\n");
            break;

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
            printf("Grade: F\n");
    }
    // Use a switch statement to determine the grade

    return 0;
}
