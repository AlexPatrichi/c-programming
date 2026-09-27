/*
=============================================================================
FILE: 05_define_constants.c

PURPOSE: Introduces #define and explains how symbolic constants can be used
         to give fixed values meaningful names.
=============================================================================
*/

/* === PREPROCESSOR DIRECTIVES ===
Preprocessor commands begin with a # symbol and are called directives.
Preprocessor directives are processed before the program is compiled.

Examples:
Including files:    #include <stdio.h>     -> includes a header file
Defining macros:    #define MAX_ITEMS 100  -> defines a named value
*/

#include <stdio.h>

#define MAX_ITEMS 100 // By convention, macro names are written in UPPERCASE.

int main(void) {

    /* === EXAMPLE: USING A DEFINED LIMIT === */

    int boxA  = 99;
    int boxB  = 101;

    printf("Maximum items: %d\n", MAX_ITEMS);
    printf("Current items Box A: %d\n", boxA);
    printf("Current items Box B: %d\n\n", boxB);

    if (boxA < MAX_ITEMS) {
        printf("Box A still has space available.\n");
    } else {
        printf("Box A has no more space available.\n");
    }

    if (boxB < MAX_ITEMS) {
        printf("Box B still has space available.\n");
    } else {
        printf("Box B has no more space available.\n");
    }

    return 0;
}
