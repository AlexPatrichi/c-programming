/*
=============================================================================
FILE: 12_for_loop.c
PURPOSE: Demonstrates the use of a for-loop in C by generating a
multiplication table for a user-provided number.
=============================================================================
*/


#include <stdio.h>
int main(void){
/* Note:
    A for loop is typically used when the number of iterations is known.
    It uses a counter variable (i) that increases or decreases each iteration.
    
    i - It controls how many times the loop runs.
    Each iteration increases i by 1 (i++).
   */

    int num, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    for ( i = 1; i <= 10; i++) { 
        /* i = 1 → initialization (starting value)
           i <= 10 → condition (loop runs while this is true)
           i++ → increment (increase i by 1 each iteration)*/
        printf("%d X %d = %d\n", num, i, num * i); 
        /* num → is the first %d, 
           i → is the second %d
           num * i → is the third %d */
    }

    return 0;
}