/*
==================================================================================
FILE: 01_functions.c
PURPOSE: Introduction to the basic structure, declaration, definition, and
         calling of functions in C.
==================================================================================
*/     

/*A function is a named block of code that performs a particular task.

Functions allow us to organize code into smaller, reusable pieces.
Instead of writing the same logic multiple times, we can define it once
and call the function whenever that task needs to be performed.

This helps make programs easier to read, organize, maintain, and debug.*/

#include <stdio.h>

/* === FUNCTION PROTOTYPE ===
A function prototype tells the compiler about a function before the function
is actually defined.

It describes:
    - the function's return type
    - the function's name
    - the type and number of parameters it expects

General syntax: return_type function_name(parameters);*/

void print_separator(void); 
// void before the function name means the function does not return a value.
// (void) after the function name means the function does not receive any parameters.

/* === MAIN FUNCTION ===
The functions declared above can now be called from main().*/
int main(void) {

// FUNCTION CALL 
   print_separator();
   /* Writing the function's name followed by parentheses calls the function. 
   This tells the program to execute the code inside print_separator() function.*/

   printf("Welcome to the program!\n");

// FUNCTION REUSE
   print_separator(); 
   /*This function can be called multiple times from main().
   This shows one of the main benefits of functions: reuse.*/
   return 0;
}

/* === FUNCTION DEFINITION ===
The function definition contains the actual code that runs when the function is called.*/
void print_separator(void) {
    printf("=======================\n");
}