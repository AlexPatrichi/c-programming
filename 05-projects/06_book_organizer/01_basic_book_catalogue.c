/*
=============================================================================
FILE: 01_basic_book_catalogue.c
PURPOSE: Store 8 book titles in an array and display each title together
         with the first title in the catalogue.
=============================================================================
*/

#include <stdio.h>

int main(void) {

/* === STEP 1: CREATE THE BOOK CATALOGUE ===

The catalogue contains 8 book titles stored in deliberately
mixed alphabetical order.

Because each book title is a string (an array of characters),
a two-dimensional char array is used:

    books[8][60]

    8  -> number of book titles
    60 -> maximum characters available for each title

Each row of the array stores one string:

    books[0] -> "Rich Dad Poor Dad"
    books[1] -> "The Intelligent Investor"
    books[2] -> "The Psychology of Money"
    ...
*/
    char books[8][60] = {
        "Rich Dad Poor Dad", 
        "The Intelligent Investor",
        "The Psychology of Money",
        "Atomic Habits",
        "Mindset",
        "The Power of Discipline",
        "The Power of Positive Thinking",
        "Can't Hurt Me" 
    };

/* === STEP 2: DISPLAY THE BOOK TITLES ===

The loop moves through each book in the array.

On every iteration:

    books[i] -> moves through the catalogue
    books[0] -> refers to the first title

books[0] does not change, so "Rich Dad Poor Dad" is displayed
as the first title during every iteration.
*/
    for (int i = 0; i < 8; i++) {
        printf("Current Title: \"%s\"\n", books[i]);
        printf("First Title: \"%s\"\n\n", books[0]);
    }

    return 0;
}
