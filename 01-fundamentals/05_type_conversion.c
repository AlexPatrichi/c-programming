/*
===============================================================================
FILE: 05_type_conversion.c
PURPOSE: Demonstrates implicit and explicit type conversion using a shopping 
basket example.
===============================================================================
*/

#include <stdio.h>

int main(void)
{
//Type conversion is the process of converting the value of one data type to another data type.
    
    int apples = 5;     
    double price = 1.75;

    printf("Shopping Basket Items\n");
    printf("------------------------\n");

    printf("Apples: %d\n", apples);
    printf("Price per apple: %.2f\n\n", price);

    printf("Shopping Basket Costs\n");
    printf("------------------------\n");
 
/* Implicit conversion
Implicit conversion is done automatically by the compiler. */
    double total = apples * price;
    printf("Total price (implicit conversion): %.2f\n", total);
    // int * double = double (apples is automatically converted to double before multiplication)

/* Losing precision when casting from double to int
Converting from larger types to smaller types may lead to loss of precision. */
    int rounded_total = (int)total;
    printf("Total price cast to int (precision loss): %d\n", rounded_total);
    // decimal part is truncated

/* Explicit conversion or casting
This conversion is done manually by the programmer, placing the type in parentheses () 
in front of the value. */
    double corrected_total = (double)apples * price;
    printf("Total price using explicit casting: %.2f\n", corrected_total);

    return 0;
}