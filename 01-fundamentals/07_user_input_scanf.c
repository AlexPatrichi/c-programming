/*
=============================================================================
FILE: 07_user_input_scanf.c
PURPOSE: Demonstrates user input using scanf() and fgets() through a simple 
gym app profile setup.
=============================================================================
*/

#include <stdio.h>

int main(void){

    printf("Welcome to the Gym App!\n");
    printf("Let's set up your profile!\n\n");

    char name[50];
    char goal[50];
    int age;
    double weight;
    double height;

/* Text input using fgets() */ 

    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);

    /* fgets() is used to safely read text input that may contain spaces.

    It takes three arguments:
        1. name - the variable where the input will be stored 
        2. sizeof(name) - The size of the array (char name[50];)
        3. stdin - The standard input stream. 
    C uses stdin instead of saying keyboard directly and is defined in <stdio.h> library. */
    
    printf("What is your fitness goal? ");
    fgets(goal, sizeof(goal), stdin);
    /* fgets() also stores a newline character (\n) at the end of the string.
    When you type something and press Enter, you are actually inputting your text plus a 
    newline character (\n), which fgets() stores in the array. */ 

/* Numeric input using scanf() */
    printf("How old are you? "); 
    scanf("%d", &age); 

    /* scanf() stops reading when it encounters first whitespace, which is why it is 
    commonly used to read numeric input from the user.

    scanf() takes two arguments. 
       1. (%d) - format specifier of the variable
       2. (&age) - links the user input to the variable
       
    Scanf() automatically reads from stdin and we don't need to mention it. (fscanf(stdin, "%d", &age);) */

    printf("Your height (in meters): ");
    scanf("%lf", &height);

    printf("Your weight (in kg): ");
    scanf("%lf", &weight);

    printf("\n=== Profile Created Successfully ===\n");

    printf("Welcome to the gym, %s !", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f m\n", height);
    printf("Weight: %.2f kg\n", weight);
    printf("Goal: %s", goal);

    return 0;
}