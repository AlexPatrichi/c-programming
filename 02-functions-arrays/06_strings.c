/*
=============================================================================
FILE: 06_strings.c
PURPOSE: Introduction to strings and basic string processing in C.
=============================================================================
*/

#include <stdio.h>  // Standard input/output functions: printf(), fgets()
#include <string.h> // String manipulation functions: strlen(), strcspn()
#include <ctype.h>  // Character handling functions: isalpha(), isdigit(), isspace()

/* These are C standard library headers.
We include them to use functions for input/output, string operations,
and character checking. */

int main(void) {
/* C does not have a built-in string type like some other programming languages.
Instead, strings are stored using arrays of characters (char). */

    char username[50]; // String stored as a character array
    char message[] = "Good to see you,"; // String literal stored as a character array

    int letters = 0;
    int digits = 0;
    int spaces = 0;

    printf("Enter a username: ");
    fgets(username, sizeof(username), stdin); // Read a full line safely

    /* fgets() stores the newline character '\n' when Enter is pressed.
    strcspn() finds the position of '\n', and we replace it with '\0' 
    to remove the newline from the string.  */
    username[strcspn(username, "\n")] = '\0'; // Marks the end of the string

    /* A string in C is an array of characters ending with '\0'.
    The '\0' character is automatically added to the end of a string.
    We can therefore process the string one character at a time. 

        Example: char username[50] = "Alex";

        Index:    0    1    2    3     4
        Value:   'A'  'l'  'e'  'x'  '\0'
    */
    for (int i = 0; username[i] != '\0'; i++) { 
        // Moves through each character until the null terminator '\0'
        // username[i] - Access one character at a time
        if (isalpha(username[i])) {
            letters++;
        } else if (isdigit(username[i])) {
            digits++;
        } else if (isspace(username[i])) {
            spaces++;
        }
    }

     // Username Validation
    if (strlen(username) < 5) {
        printf("Username is too short.\n\n");
    } else if (spaces > 0) {
        printf("Username cannot contain spaces.\n\n");
    } else if (letters == 0) {
        printf("Username should contain at least one letter.\n\n");
    } else if (digits == 0) {
        printf("Username should contain at least one number.\n\n");
    } else {
        printf("Username accepted.\n");
        printf("%s %s!\n\n", message, username);
    }

    printf("Length: %zu\n", strlen(username)); // Find string length
    printf("Letters: %d\n", letters);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n\n", spaces);

    /* %zu is used because strlen() returns a value of type size_t.
            %   -> starts the format specifier
            z   -> the value is a size_t
            u   -> unsigned integer  */

    /* Strings can contain special characters using escape sequences,
    such as '\n' for a new line, '\t' for a tab, or '\"' for a double quote. */

    return 0;
}