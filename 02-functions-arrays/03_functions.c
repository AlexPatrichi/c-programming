/*
==================================================================================
FILE: 03_functions.c
PURPOSE: Introduction to return values and returning information from functions.
==================================================================================
*/

/* A function can receive values, perform a calculation, and return a result.
The return type tells us what type of value the function gives back.

Example: int calculate_total(int price, int quantity)

Here:
    int              -> return type
    calculate_total  -> function name
    price, quantity  -> parameters

The return statement sends the calculated value back to the code
that called the function.
*/

#include <stdio.h>

// FUNCTION PROTOTYPES
int calculate_total(int price, int quantity);
int calculate_change(int payment, int total);

int main(void) {
    int price = 15;
    int quantity = 3;
    int payment = 50;

    int total = calculate_total(price, quantity);
    /* The function receives price and quantity as arguments.

    calculate_total() multiplies them and returns the result.

        15 * 3 = 45

    The returned value is stored in 'total'.
    */

    int change = calculate_change(payment, total);

    printf("Price: %d\n", price);
    printf("Quantity: %d\n", quantity);
    printf("Total: %d\n\n", total);
    printf("Payment: %d\n", payment);
    printf("Change: %d\n", change);

     /* Then use the returned value as an argument in another function.

    payment = 50
    total   = 45

    calculate_change() returns 5.
    */
    return 0;
}

// FUNCTION DEFINITION
int calculate_total(int price, int quantity) {
    return price * quantity; 
}

int calculate_change(int payment, int total) {
    return payment - total; 
}