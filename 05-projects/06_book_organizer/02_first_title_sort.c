/*
=============================================================================
FILE: 02_first_title_sort.c
PURPOSE: Find the alphabetically earliest book title using a single pass
         and move it to index 0 using case-insensitive comparison.
=============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BOOK_COUNT 8
#define TITLE_LENGTH 60


/* === CASE-INSENSITIVE STRING COMPARISON ===

This function compares two book titles one character at a time
while ignoring uppercase and lowercase differences.

For example:

    first  = "Atomic Habits"
    second = "atomic Theory"

The comparison works like this:

    'A' -> 'a'    'a' -> 'a'    same -> continue
    't' -> 't'    't' -> 't'    same -> continue
    'o' -> 'o'    'o' -> 'o'    same -> continue
        ...
    'H' -> 'h'    'T' -> 't'    different -> stop

Because 'h' comes before 't', the first title comes
before the second title alphabetically.

The function returns:

    negative value -> first title comes before second title
    0              -> both titles are equal
    positive value -> first title comes after second title
*/

int compareIgnoreCase(const char first[], const char second[]) {

    int i = 0;

    /* Compare the two strings one character at a time
    until the end of either string is reached. */
    while (first[i] != '\0' && second[i] != '\0') {

        /* Convert the current characters to lowercase so that
         uppercase and lowercase letters are treated the same. */
        char firstChar = tolower((unsigned char)first[i]);
        char secondChar = tolower((unsigned char)second[i]);

        /* If the characters are different, we have found
         which title comes first alphabetically. */
        if (firstChar != secondChar) {
            return firstChar - secondChar;
        }

        /* Characters were the same, so move to the next pair. */
        i++;
    }

    /* If all compared characters were the same, compare the
    ending characters. This also handles cases where one 
    title is shorter than the other, such as "Book" and "Books". */
    return tolower((unsigned char)first[i]) - tolower((unsigned char)second[i]);
}


int main(void) {

/* === STEP 1: CREATE THE BOOK CATALOGUE ===

The catalogue contains 8 book titles stored in deliberately
mixed alphabetical order.
*/

    char books[BOOK_COUNT][TITLE_LENGTH] = {
        "Rich Dad Poor Dad",
        "The Intelligent Investor",
        "The Psychology of Money",
        "Atomic Habits",
        "Mindset",
        "The Power of Discipline",
        "The Power of Positive Thinking",
        "Can't Hurt Me"
    };


/* === STEP 2: DISPLAY CATALOGUE BEFORE COMPARISON === */

    printf("Before:\n");

    for (int i = 0; i < BOOK_COUNT; i++) {
        printf("%s\n", books[i]);
    }


/* === STEP 3: FIND THE EARLIEST TITLE ===

Each title is compared with the title currently stored
at index 0.

If books[i] comes earlier alphabetically than books[0],
the two strings are swapped.

This is only ONE pass through the array.

It guarantees that the alphabetically earliest title
ends up at index 0, but it does not sort the entire array.
*/

    char temp[TITLE_LENGTH];

    for (int i = 1; i < BOOK_COUNT; i++) {

        if (compareIgnoreCase(books[i], books[0]) < 0) {

            strcpy(temp, books[0]);
            strcpy(books[0], books[i]);
            strcpy(books[i], temp);
        }
    }


/* === STEP 4: DISPLAY CATALOGUE AFTER COMPARISON === */

    printf("\nAfter:\n");

    for (int i = 0; i < BOOK_COUNT; i++) {
        printf("%s\n", books[i]);
    }

    return 0;
}