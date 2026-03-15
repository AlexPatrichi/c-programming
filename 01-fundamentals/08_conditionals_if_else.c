/*
=============================================================================
FILE: 08_conditionals_if_else.c
PURPOSE: Demonstrates conditional decision-making using if, else if, and else.
=============================================================================
*/

#include <stdio.h> // Include input library
#include <stdbool.h> // Include Bool type library 

int main(void) {

/* C supports common comparison operators from mathematics (< , >, <=, >=, ==, !=) to compare values
 and make decisions based on those comparisons.
 
CONDITIONAL STATEMENTS:
if       → executes code if a condition is true
else if  → checks another condition if the previous one is false
else     → executes code if none of the conditions are true
switch   → selects one block of code from many alternatives*/

    int score;
    bool passed; // Logical variable (true or false)

    printf("Enter your exam score (0-100): ");
    scanf("%d", &score);

    /*Decision Flow:
        score entered
             ↓
        validate input
             ↓
        score ≥ 90 → A
        score ≥ 80 → B
        score ≥ 70 → C
        score ≥ 60 → D
        otherwise → F    */

    /* Validate the input to ensure the score is within a valid range */
    if (score < 0 || score > 100) {
        printf("Invalid score. Please enter a value between 0 and 100.\n");
        return 1;
    }

    /* Determine the grade using conditional statements */
    if (score >= 90) { // Runs code only if a condition is true.
        printf("Grade: A\n");
    }
    else if (score >= 80) { // Adds another condition to check if the previous one failed.
        printf("Grade: B\n");
    }
    else if (score >= 70) {
        printf("Grade: C\n");
    }
    else if (score >= 60) {
        printf("Grade: D\n");
    }
    else { // Runs when none of the previous conditions are true.
        printf("Grade: F\n");
    }

    /* Boolean values in C 
    Condition in C evaluate to either true or false. 
    Traditional C represents these values as integers (0/false and 1/true).
    Modern C provides the boolean type from the <stdbool.h> library. 
    */

    passed = score >= 60;
    // The comparison returns true or false and stores the result in 'passed'

    if(passed) {
        printf("You passed.\n");
    } else {
        printf("Sorry, you failed.\n");
    }

    /* Ternary Operator
    A shorthand way to choose between two values based on a condition.
    Often used to replace a simple if-else statement in one line.

    Example:
    printf("Grade: %c — %s\n", grade, passed ? "You passed" : "Sorry, you failed");

    - Grade: %c → prints the letter grade
    - — %s      → prints a message based on the ternary operator
    - passed ? "You passed" : "Sorry, you failed" 
            → chooses the string depending on the boolean variable passed
    */

    return 0;
}