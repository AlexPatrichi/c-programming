/*
=============================================================================
FILE: 01_memory_addresses.c
PURPOSE: Introduction to variables, memory addresses, and the address-of operator.
=============================================================================
*/

#include <stdio.h>

int main(void) {
/* Every variable is stored at a location in memory.
That location has a memory address, which tells us where the variable is stored.

The '&' address-of operator gives us the memory address of a variable.

    Example:
    User enters: 30
          ↓
       scanf()
          ↓
    Where should 30 be stored?
          ↓
       &user_age
          ↓
    Address of user_age
          ↓
    30 is stored at that address */

    int user_age; 
    
    printf("\nEnter your age: ");
    scanf("%d", &user_age); 
    /* scanf() - needs the memory address of a variable so it knows where in memory 
    to store the value entered by the user. 
    
     user_age   ->  WHAT is stored there (the value)
     &user_age  ->  WHERE it is stored (the address)  */

    printf("Your age is: %d\n", user_age); // Value
    printf("Stored at address: %p\n", (void *)&user_age); // Address
    /* (%p) - PRINTING MEMORY ADDRESSES
    %p is the printf() format specifier used for memory addresses.
    Memory addresses usually appear as hexadecimal values, for example: 0x7ffd1234
    The actual address can be different every time the program runs.  */

    return 0;
}