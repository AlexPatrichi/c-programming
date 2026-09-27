/*
=============================================================================
FILE: 04_book_organizer.c

PURPOSE: Allows the user to delete a book title, shifts the remaining titles,
and sorts the catalogue alphabetically using Bubble Sort.
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

bookCount keeps track of how many books are currently
stored in the catalogue.
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
    char deletedTitle[TITLE_LENGTH];

    int bookCount = BOOK_COUNT;
    int found = 0;


/* === STEP 2: DISPLAY CATALOGUE BEFORE SORTING === */

    printf("Before:\n");

    for (int i = 0; i < bookCount; i++) {
        printf("%s\n", books[i]);
    }


/* === STEP 3: DELETE A BOOK TITLE ===

The user enters the title they want to delete.

The program searches for the title using a case-insensitive
comparison.

If the title is found, the remaining titles are shifted one
position to the left so that no empty gap remains.

    [Book A] [Book B] [Book C] [Book D]
                  ↓ delete
    [Book A] [Book C] [Book D]

bookCount is then decreased by 1.
*/

    printf("\nEnter the title of the book you want to delete: ");
    fgets(deletedTitle, TITLE_LENGTH, stdin);

    // Remove the newline character added by fgets()
    deletedTitle[strcspn(deletedTitle, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++) {

        if (compareIgnoreCase(books[i], deletedTitle) == 0) {

            found = 1;

            // Shift the remaining titles one position to the left
            for (int j = i; j < bookCount - 1; j++) {
                strcpy(books[j], books[j + 1]);
            }

            bookCount--;
            break;
        }
    }

    if (found) {
        printf("Book \"%s\" deleted successfully.\n", deletedTitle);
    } else {
        printf("Book \"%s\" not found in the catalogue.\n", deletedTitle);
    }


/* === STEP 4: SORT THE BOOK CATALOGUE USING BUBBLE SORT ===

Bubble Sort compares neighbouring titles:

    books[j]     -> current title
    books[j + 1] -> next title

If they are in the wrong alphabetical order, they are swapped.

After each pass, the title that comes latest alphabetically
moves towards the end of the catalogue.

This repeats until the entire catalogue is sorted.
*/

    for (int i = 0; i < bookCount - 1; i++) {

        for (int j = 0; j < bookCount - i - 1; j++) {

            if (compareIgnoreCase(books[j], books[j + 1]) > 0) {

                // Swap the two neighbouring book titles
                strcpy(temp, books[j]);
                strcpy(books[j], books[j + 1]);
                strcpy(books[j + 1], temp);
            }
        }
    }


/* === STEP 5: DISPLAY CATALOGUE AFTER SORTING === */

    printf("\nAfter:\n");

    for (int i = 0; i < bookCount; i++) {
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