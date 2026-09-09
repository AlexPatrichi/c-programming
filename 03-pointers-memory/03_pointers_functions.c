/*
=============================================================================
FILE: 03_pointers_functions.c
PURPOSE: Introduction to using pointers with functions.
=============================================================================
*/

#include <stdio.h>

/* C normally passes a copy of the value of 'age' to this function.
The function parameter is a local variable that stores this copy.
Changing the parameter does not change the original variable.

 void update_age(int age) {
      age = 18;
    }   */

/* By passing the variable's address instead, the function can use
a pointer to access and change the original value.*/    
void update_age(int *age) {
    *age = 18;  // Dereference the pointer and change the original age
}

int main(void) {

    int age = 17;
    printf("Current age: %d\n", age);
    
    if (age >= 18) {
        printf("You are old enough to drive.\n");
    } else {
        printf("You are too young to drive.\n\n");
    }
   
/*  update_age(age);   // -> passes a copy of the value */ 
    update_age(&age);  // -> passes the address of age
    printf("Current age: %d\n", age);

    if (age >= 18) {
        printf("You are now old enough to drive.\n");
    } else {
        printf("You are still too young to drive.\n\n");
    }

    return 0;
}