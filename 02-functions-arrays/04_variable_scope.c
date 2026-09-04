/*
==================================================================================
FILE: 04_variable_scope.c
PURPOSE: Introduction to local and global variable scope in C.
==================================================================================
*/

/*  SCOPE describes where a variable can be accessed in a program.

There are two important cases:
 
    GLOBAL VARIABLE -> Declared outside all functions.
                    It can be accessed by functions in the file after its declaration. 

    LOCAL VARIABLE  -> Declared inside a function or block. It can only be used there.

Function parameters also have local scope.  */

#include <stdio.h>

/* === GLOBAL VARIABLE ===
This variable is declared outside all functions.
It can be used by main() and by the other functions below. */
int total_sales = 0;


/* === FUNCTION PROTOTYPE === */
void process_order(int price, int quantity);


int main(void) {
    /* === LOCAL VARIABLES ===
    These variables belong to main().
    They can be used inside main(), but not directly inside process_order(). */
    int price = 12;
    int quantity = 3;

    process_order(price, quantity);

    printf("Total sales: £%d\n", total_sales);

    /*  This would cause an error:

        printf("%d\n", order_total);

    order_total is local to process_order(), so main() cannot access it.  */

    return 0;
}


/* === FUNCTION DEFINITION === */
void process_order(int price, int quantity) {
    /* price and quantity are PARAMETERS. Parameters are local to the function they belong to.
    The values from main() are passed into these parameters when process_order() is called. */

    int order_total = price * quantity;
    /* order_total is a LOCAL VARIABLE.
    It exists inside process_order() and can only be accessed within this function. */

    printf("Order total: £%d\n", order_total);

    /* total_sales is GLOBAL, so this function can access and modify it. */
    total_sales = total_sales + order_total;
}

/* The 'price' in main() and the 'price' in process_order() are different variables.

    int price = 12;                  // LOCAL VARIABLE in main()

    void process_order(int price, int quantity)
                           ^^^^^
                           PARAMETER

    process_order(price, quantity);
                  ^^^^^
                  ARGUMENT                       

The value stored in 'price' in main() is passed as an argument to the parameter 'price' 
in process_order().

In general, global variables should be used carefully because they can be accessed and 
modified by multiple functions.  */

/* === VARIABLE SHADOWING === 
If variables have the same name (total_sales), C uses the one declared in the nearest scope (main).
A local variable can therefore hide a global variable with the same name.  

Example: 
int total_sales = 0;  // This is a global variable

int main(void) {
    int total_sales = 50;  // Local variable - will shadow the global variable

    printf("%d\n", total_sales); // Uses the local variable -> 50

    return 0;
  
} */