/*
=============================================================================
FILE: 04_pointers_arrays.c
PURPOSE: Introduction to pointers, arrays, and pointer arithmetic.
=============================================================================
*/

#include <stdio.h>

int main(void) {
    int stock[] = {12, 8, 25, 4, 16}; 
    // A warehouse stores the stock quantity of 5 products in an array. 

   /* The array name gives us the address of the first element of the array.

        stock       -> address of stock[0]
        &stock[0]   -> address of stock[0]
        ptr_stock   -> address of stock[0]

    This allows a pointer to point to the beginning of the array.
    */

    int *ptr_stock = stock;

    printf("First product stock: %d\n", stock[0]);
    printf("First product through pointer: %d\n", *ptr_stock);

    return 0;
}