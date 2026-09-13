/*
=============================================================================
FILE: 06_double_pointers.c
PURPOSE: Introduction to pointers to pointers in C.
=============================================================================
*/

#include <stdio.h>

int main(void){
/* === POINTER TO POINTER ===

A pointer stores the address of another variable.
A pointer to a pointer stores the address of another pointer.

    age       -> stores the value 30
    ptr       -> stores the address of age
    ptr_ptr   -> stores the address of ptr

So we now have two levels of pointers:
    ptr_ptr -> ptr -> age -> 30
     
The number of '*' tells us how many levels of pointers we are working with.

    int age;        -> an int
    int *ptr;       -> pointer to an int
    int **ptr_ptr;  -> pointer to a pointer to an int
*/
    
    int age = 30; 
    // Declare an integer variable 'age' and initialize it to 30

    int *ptr = &age; 
    // Declare a pointer 'ptr' and assign it the address of 'age'
    int **ptr_ptr = &ptr; 
    // Declare a pointer to a pointer 'ptr_ptr' and assign it the address of 'ptr'

    printf("Age: %d\n", age);
    printf("*ptr: %d\n", *ptr);
    printf("**ptr_ptr: %d\n", **ptr_ptr);

/* === WHY USE A POINTER TO A POINTER? ===

A pointer to a pointer is useful when we need to work with
the pointer itself, not only the value it points to. */

    return 0;
}