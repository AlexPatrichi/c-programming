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

/*  In most expressions, the array name acts like the address
of the first element of the array.

    stock       -> address of stock[0]
    &stock[0]   -> address of stock[0]
    ptr_stock   -> address of stock[0]

This allows a pointer to point to the beginning of the array. */

/* === POINTER ARITHMETIC DEPENDS ON TYPE === 
Pointer arithmetic lets us move through array elements
by adding or subtracting from a pointer.

Adding 1 to a pointer moves it to the next element of the type
it points to, not simply 1 byte forward.

For example:
    int *ptr   -> ptr + 1 moves to the next int
    char *ptr  -> ptr + 1 moves to the next char

So pointer movement depends on the type of data it points to.*/

    int *ptr_stock = stock;

    printf("First product stock: %d\n", stock[0]);
    printf("First product through pointer: %d\n", *ptr_stock);

    printf("\nSecond product stock: %d\n", stock[1]);
    printf("Second product through pointer: %d\n", *(ptr_stock + 1)); 
    // Adding 1 gives the position of the next element, which is stock[1].

    printf("\nThird product stock: %d\n", stock[2]);
    printf("Third product through pointer: %d\n", *(ptr_stock + 2));

/* === ARRAY INDEXING vs POINTER NOTATION ===
Both expressions can access the same array element:

    stock[i]         ->     stock[2]      ->  25  ->   array notation
    *(ptr_stock + i) ->  *(ptr_stock + 2) ->  25  ->  pointer notation   */

    printf("\nLoop through array using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("Product %d stock: %d\n", i + 1, *(ptr_stock + i));
    }

/*  === MOVING THE POINTER ===
ptr_stock + 1 looks at the next position without changing the pointer.
ptr_stock++ moves the pointer itself to the next position.

    ptr_stock + 1  -> calculates the next position
                      ptr_stock stays where it is

    ptr_stock++    -> changes ptr_stock itself
                      it now points to the next element*/
    printf("\nMoving the pointer:\n");
    printf("Current stock: %d\n", *ptr_stock);  

    ptr_stock++;

    printf("Next stock: %d\n", *ptr_stock); 

/* Pointers provide another way to access and process array elements.
They must be handled carefully, because moving outside the array
can access invalid memory. */

    return 0;
}