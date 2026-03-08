/*
==================================================================================
FILE: 01_structure_of_C_program.c
PURPOSE: Demonstrates the basic structure of a C program, including main function,
printf(), and program execution flow.
==================================================================================
*/

#include <stdio.h>  
// Standard input/output library. This header lets us use input/output functions such as printf().

int main(void) {  
    // main() function is where the execution of the program begins.
    // The void in the parentheses indicates that this function does not take any parameters. 

      printf("Hello, C programming!\n");  
      // The printf() function is used to output text to the console.
      // Every C statement ends with a semicolon ;
      // The \n is a newline character that moves the cursor to the next line after printing the message.

      /*
      Could also be written as:
      int main(){printf("Hello, C programming!");return 0;} 
      But it is generally recommended to write code in a more readable format, with each statement on its own line and proper indentation.
      */

    return 0;  
    // Ends the main() function and indicates successful execution.
}
// Any code inside the curly brackets {} will be executed.

