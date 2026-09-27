/*
=============================================================================
FILE: 03_alphabetical_sort.c
PURPOSE: Sort a catalogue of book titles into alphabetical order
         using nested loops and case-insensitive comparison.
=============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BOOK_COUNT 8
#define TITLE_LENGTH 60


// Function prototype
int compareIgnoreCase(const char first[], const char second[]);


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

    char temp[TITLE_LENGTH];


/* === STEP 2: DISPLAY CATALOGUE BEFORE SORTING === */

    printf("Before:\n");

    for (int i = 0; i < BOOK_COUNT; i++) {
        printf("%s\n", books[i]);
    }


/* === STEP 3: SORT THE BOOK CATALOGUE ===

The outer loop selects the position currently being sorted.
The inner loop checks all titles that come after it.

    i -> current position
    j -> searches the remaining titles

If books[j] comes earlier alphabetically than books[i],
the two titles are swapped.

After each outer-loop pass, the earliest remaining title
is placed in the current position.

This repeats until the entire catalogue is sorted.
*/

    for (int i = 0; i < BOOK_COUNT - 1; i++) {

        for (int j = i + 1; j < BOOK_COUNT; j++) {

            if (compareIgnoreCase(books[j], books[i]) < 0) {

                // Swap the two book titles
                strcpy(temp, books[i]);
                strcpy(books[i], books[j]);
                strcpy(books[j], temp);
            }
        }
    }


/* === STEP 4: DISPLAY CATALOGUE AFTER SORTING === */

    printf("\nAfter:\n");

    for (int i = 0; i < BOOK_COUNT; i++) {
        printf("%s\n", books[i]);
    }

    return 0;
}


/* === CASE-INSENSITIVE STRING COMPARISON ===

This function compares two strings one character at a time.

Each character is temporarily converted to lowercase so that
uppercase and lowercase letters are treated the same.

For example:

    'A' and 'a' -> treated as equal
    'B' and 'b' -> treated as equal

The function keeps moving through the strings until it finds
two different characters.

It returns:

    negative -> first title comes before second title
    0        -> titles are equal
    positive -> first title comes after second title
*/

int compareIgnoreCase(const char first[], const char second[]) {

    int i = 0;

    while (first[i] != '\0' && second[i] != '\0') {

        char firstChar = tolower((unsigned char)first[i]);
        char secondChar = tolower((unsigned char)second[i]);

        if (firstChar != secondChar) {
            return firstChar - secondChar;
        }

        i++;
    }

    return tolower((unsigned char)first[i]) - tolower((unsigned char)second[i]);
}