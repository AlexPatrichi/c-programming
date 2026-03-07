/*
============================================================
FILE: 04_variables.c
PURPOSE: Demonstrates how to declare, initialize, and use variables in C,
including variable naming rules, changing values, multiple variables, and format specifiers.
============================================================
*/

#include <stdio.h>
/*
To declare a variable, you specify its data type, name, and value.

- The data type defines what kind of data the variable stores (int, double, char, etc.).
- The variable name is how you refer to that value in your program.
- The '=' operator assigns a value to the variable.
- The value must match the variable's data type.

Variable names can contain letters, digits, and underscores, must start with a letter 
or underscore, and cannot be C keywords.
*/

int main(void)
{
    char name[30];           // Variable to store the user's name. Memory for up to 30 characters.
    double balance = 150.00; // Variable to store the initial balance.
    double deposit;          // Variable to store the deposit amount.
    double withdraw;         // Variable to store the withdrawal amount.

/* Note: 
Values can be printed directly, but variables allow us to store, reuse, and modify 
data throughout the program. */

    printf("=== Simple Bank Simulator ===\n");

    printf("Enter your name: ");
    scanf("%29s", name); 
    /* Even though we declared 'name' to hold 30 characters, scanf() still can write more than that, 
    so we use %29s to prevent buffer overflow + 1 for null terminator ('\0' - way to know where the string stops). */
    
    /* Because %s reads a string until it encounters whitespace, it will only capture the first word of the name.
    So, we need to use fgets() instead of scanf(), which allows us to read the entire line.

    Later, we’ll learn methods to read full lines including spaces. */
    
    printf("\nHello, %s!\n", name);
    printf("Starting balance: $%.2f\n", balance);

    printf("\nEnter deposit amount: ");
    scanf("%lf", &deposit);

/* Variable Value Change:
If you assign a new value to an existing variable, the new value will replace the old one. */
    balance = balance + deposit;
    // Alternatively, readable math: balance += deposit;

    printf("Balance after deposit: $%.2f\n", balance);

    printf("\nEnter withdrawal amount: ");
    scanf("%lf", &withdraw);

    balance = balance - withdraw;
    // Alternatively, readable math: balance -= withdraw;
    printf("Final balance: $%.2f\n", balance);

    return 0;
}