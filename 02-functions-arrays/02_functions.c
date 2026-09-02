/*
==================================================================================
FILE: 02_functions.c
PURPOSE: Introduction to passing information to functions using parameters
         and arguments.
==================================================================================
*/

/* A function can receive information when it is called.

A PARAMETER is the variable in the function that receives the information.
An ARGUMENT is the value we give to that parameter when calling the function.
*/

#include <stdio.h>

/* === FUNCTION DECLARATION vs FUNCTION DEFINITION ===
A function declaration tells the compiler that a function exists,
including its name, return type, and parameters.
- It describes the function but does not contain its code.
- Example: void greet(char name[]);

A function definition includes the function header and the body between the {} 
and contains the actual code the function will execute. */

void greet(char name[]) {          // FUNCTION DEFINITION {} - also acts as a declaration.
    printf("Hello, %s!\n", name);  
}
/* "name" is a parameter.
   It receives a value when greet() is called. */

/*If a function is defined before main(), a separate prototype is not needed
because the compiler has already seen the function before it is called.*/

int main(void){ // Program execution begins in main().

    greet("Alex"); // Function Call
/* "Alex" is an argument.
    It is passed to the parameter "name". */

    greet("Maria"); // Reuse the function

    return 0; // Return 0 to indicate successful execution of the program.
}

/*=== TYPES OF FUNCTIONS === 
 1. Library Functions  
Functions provided by C standard library, such as printf() and scanf(). 
To use them, we include the appropriate header file, such as #include<stdio.h>.

 2. User-Defined Functions
Functions that we manually create to perform specific tasks in our program.

void greet(char name[]) {                       // greet()  - USER-DEFINED FUNCTION 
    printf("Good morning, %s!\n", name);        // printf() - LIBRARY FUNCTION
}*/