/*
=============================================================================
FILE: 13_nested_loops.c
PURPOSE: Demonstrates nested loops in C by printing a pyramid pattern
using spaces and stars.
=============================================================================
*/

/* Note:
   A nested loop is a loop inside another loop.
   The inner loop will be executed one time for each iteration of the outer loop. */

#include <stdio.h>

int main() {

   // Outer loop controls the rows
   for (int i = 1; i <= 6; i++) { // i = current row

        //1️⃣First inner loop prints spaces
        for (int space = 1; space <= 6 - i; space++) {
            // i represents the current row number.
            // As the row number increases, the number of spaces decreases (6 - i).
            // Each iteration prints a single space.
            printf(" ");
        }

        //2️⃣Second inner loop prints stars
        for (int j = 1; j <= i; j++) { 
            // j represents the current star being printed.
            // As the space number decreases, the star numbers increases.
            printf("* "); 
            // The space after * creates a gap between stars and gives the pyramid shape
        }
        // Move to the next row
        printf("\n"); // 
    }
    
    return 0;
}

/* Output:
Row 1:      *       (5 spaces + 1 star)
Row 2:     * *      (4 spaces + 2 stars)
Row 3:    * * *     (3 spaces + 3 stars)
Row 4:   * * * *    (2 spaces + 4 stars)
Row 5:  * * * * *   (1 space + 5 stars)
Row 6: * * * * * *  (0 spaces + 6 stars)
*/