/*
=======================================================================================
FILE: 03_data_types.c
PURPOSE: Demonstrates the basic data types in C, including int, float, double, and char,
along with their corresponding printf format specifiers.
=======================================================================================
*/

#include <stdio.h>

int main(void) {
/* A data type defines what kind of value a variable can store. */
    int items = 3;             // int stores whole numbers

    float apple_price = 1.50f;  // float stores decimal numbers
    float banana_price = 0.80f;
    float orange_price = 1.20f;
    // The 'f' suffix tells the compiler this number is a float instead of a double.

    double total;  
    // double stores decimal numbers with higher precision than float, but uses more memory.

    total = apple_price + banana_price + orange_price;
    // Calculate the total cost of all purchased items.

    char currency = '$';       // char stores a single character
    char store_name[] = "Local Market"; // char array (string) to store the name of the store

/* For each data type, we use the appropriate format specifier in printf(). */
    printf("%s %s\n", store_name, "Receipt"); // %s for string
    // Two %s specifiers require two arguments: store_name and "Receipt".
    printf("----------------\n");
  
    printf("Items purchased: %d\n", items);       // %d for int
    printf("Apple  : %c%.2f\n", currency, apple_price);  // %f for float
    printf("Banana : %c%.2f\n", currency, banana_price);
    printf("Orange : %c%.2f\n", currency, orange_price);

    printf("----------------\n");
    printf("Total (decimal format): %c%.2lf\n", currency, total);  // %c for char, %lf for double

/* Floats/Doubles in scientific notation. */
    // Useful for very large or very small numbers, like distances, weights, or prices in a different context.
    printf("Total (scientific format): %.2E\n", total);  
    // %E (or %e) prints a floating-point number in scientific notation.
    // Example: 3.50E+00 means 3.50 × 10^0

/* Decimal precision examples: */
    printf("\nDecimal precision examples:\n");

    printf("Default precision      : %c%lf\n", currency, total);
    // %lf prints the number with the default precision (usually 6 decimal places)

    printf("Zero decimal places    : %c%.0lf\n", currency, total);
    // %.0lf prints the number rounded to the nearest whole number

    printf("Two decimal places     : %c%.2lf\n", currency, total);
    // %.2lf prints the number with exactly 2 digits after the decimal point

    printf("Four decimal places    : %c%.4lf\n", currency, total);
    // %.4lf prints the number with 4 digits after the decimal point

    return 0;
}

/*
NOTE:
Besides the basic data types (int, float, double, char), C also provides type modifiers such as:
short, long, signed, and unsigned.  

These modifiers change the size of a number or whether it can be negative or not. For example:
Examples:
- short int      // smaller integer
- long int       // larger integer
- unsigned int   // integer that cannot be negative

These will be explored in more detail in later chapters.
*/