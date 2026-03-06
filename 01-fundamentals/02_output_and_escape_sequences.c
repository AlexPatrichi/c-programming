/*
============================================================
FILE: 02_output_and_escape_sequences.c
PURPOSE: Illustrates sequential execution of statements with printf() and 
demonstrates the use of escape sequences in C, including: \n (newline), \t (tab), \\ (backslash), and \" (double quote). 
============================================================
*/

#include <stdio.h>  

int main(void) {  
    // A computer program is a list of statements (instructions) that a computer executes sequentially, from top to bottom.
    // Every line ending with semicolon (;) is a statement.
    printf("First line!\n");  //Statement 1
    printf("Second line!\n"); //Statement 2
    printf("Third line!\n\n");//Statement 3
   
    // The \n character is called an escape sequence and moves the cursor to a new line.
    // Therefore, the second printf() continues printing from the current position.
    // Two \n characters in a row will create a blank line.
    printf("Hello, "); //Statement 4
    printf("World!\n\n");  //Statement 5

    /*
    Other common escape sequences include:
    \t for a tab
    \\ for a backslash 
    \" for a double quote
    */
    printf("Shopping List:\n"); //Statement 6
    printf("\t- Apples\n"); //Statement 7   
    printf("\t- Bananas\n"); //Statement 8
    printf("\t- Oranges\n\n"); //Statement 9

    printf("Store location:\n"); //Statement 10
    printf("\t123 Main Street\n\n"); //Statement 11

    printf("\"Thank you for shopping with us!\"\n"); //Statement 12

    return 0; // Statement 13
}

/*
 This program contains multiple statements. 
Each printf() is a statement that outputs text to the console, 
and the return statement indicates that the program has finished executing successfully.
*/