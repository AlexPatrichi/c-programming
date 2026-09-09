/*
=============================================================================
FILE: 02_pointer_basics.c
PURPOSE: Introduction to pointers in C.
=============================================================================
*/

#include <stdio.h>

/* A pointer is a variable that stores the memory address of another variable as its value.
The '*' symbol is used to declare a pointer variable. */

/* === WHY ARE POINTERS USEFUL? ===
Pointers let us access and change data using its memory address.
They are useful when working with functions, arrays, strings,
and memory management. */

int main(void){

    int age = 30;          // Integer Variable
    int *ptr_age = &age;   // Int Pointer Variable that stores the address of age

/* ptr_age is a pointer variable that stores the memory address of age.
Since ptr_age contains the address of age, we can access the value of age through ptr_age. */
    
    printf("Age: %d\n", age);                           // Value of age
    printf("Address of age: %p\n\n", (void *)&age);     // Address of age

    printf("Value of age through pointer: %d\n", *ptr_age);                
    // Dereferencing the pointer to get the value
    printf("Address of age stored in pointer: %p\n\n", (void *)ptr_age);  
    // Printing the address stored in the pointer

/* === ADDRESS-OF AND DEREFERENCING ===
Using the '&' operator gives us the memory address of a variable (referencing).
When '*' is used with an existing pointer, it is called dereferencing.

    ptr_age   -> gives us the address stored in the pointer
    *ptr_age  -> goes to that address and accesses the value there

Since ptr_age contains the address of age, *ptr_age accesses age indirectly. */

    *ptr_age = 40; // Dereferencing the pointer to change the value of age
    printf("New value of age: %d\n", age);           

/* The '*' symbol therefore has two uses in this example:
        int *ptr_age;   -> declares a pointer
        *ptr_age        -> dereferences the pointer   */

    return 0;
}