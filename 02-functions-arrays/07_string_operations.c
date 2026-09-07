/*
=============================================================================
FILE: 07_string_operations.c
PURPOSE: Introduction to common string operations in C.
=============================================================================
*/
#include <stdio.h>  // Standard input/output functions: printf(), fgets()
#include <string.h> // String manipulation functions: strlen(), strcspn(), strcpy(), strcmp(), strcat()
#include <ctype.h>  // Character conversion functions: toupper(), tolower()

int main(void) {
    /* Strings are stored in character arrays.
    When working with functions such as strcpy() and strcat(),
    the destination array must have enough space to store the result. */

    char name[50];
    char issue[100];

    char issue_copy[100];
    char ticket[200] = "Customer: ";

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    printf("Describe the issue: ");
    fgets(issue, sizeof(issue), stdin);

    /* Remove the newline character added by fgets() and replace it 
    with '\0' to mark the end of the string. */
    name[strcspn(name, "\n")] = '\0';
    issue[strcspn(issue, "\n")] = '\0';

    /* strlen() - STRING LENGTH
    Returns the number of characters in a string, not including the final '\0'. */
    printf("\nIssue length: %zu characters \n", strlen(issue));

    /* strcpy() - COPYING A STRING
    Copies one string into another. 
    The destination must have enough space for the copied string.  */
    strcpy(issue_copy, issue); // strcpy(destination, source);
    printf("Copied issue: %s\n", issue_copy);

    /* strcmp() - COMPARING STRINGS 
    Compares the contents of two strings.

    Returns:  
    0           -> The strings are equal.
    Negative    -> string1 comes before string2 alphabetically.
    Positive    -> string1 comes after string2 alphabetically.

    The comparison is based on character values and is case-sensitive. */
    if (strcmp(name, "admin") == 0) {
        // Is the content of name exactly the same as "admin"?
        printf("Welcome, %s!\n", name);
    }

    /* strchr() - SEARCHING FOR A CHARACTER 
    Searches for a character inside a string.
    If the character is found, it returns its location.
    If it is not found, it returns NULL. */
    if (strchr(issue, '!') != NULL) { // strchr(string, character);
        printf("The issue contains an exclamation mark.\n");
    }

    /* strstr() - SEARCHING FOR A SUBSTRING
    Searches for a string inside another string.
    If the substring is found, it returns its location.
    If it is not found, it returns NULL. */
    if (strstr(issue, "urgent") != NULL) { // strstr(string, substring);
        printf("The issue is marked as urgent.\n");
    }

    /* toupper() and tolower() - CONVERTING CASE
    These functions convert characters to uppercase or lowercase.
    They work with one character at a time. To modify an entire string, 
    we use them inside a loop. */
    printf("\nIssue in uppercase: ");

    for (int i = 0; issue[i] != '\0'; i++) {
        printf("%c", toupper(issue[i]));
    }

    printf("\nIssue in lowercase: ");
    for (int i = 0; issue[i] != '\0'; i++) {
        printf("%c", tolower(issue[i]));
    }     
    
    printf("\n");

    /* strcat() - CONCATENATING STRINGS 
    Adds one string to the end of another.
    The destination must have enough space to hold the combined string. */

    strcat(ticket, name); // Customer: + Add the name to the ticket
    strcat(ticket, "\nIssue: "); // Customer + Name + Add the issue label to the ticket
    strcat(ticket, issue); // Customer + Name + Issue Label + Add the issue description to the ticket

    printf("\n----- SUPPORT TICKET -----");
    printf("\n%s\n", ticket); // Print the complete ticket (string concatenation result)
    printf("--------------------------\n");

    return 0;
}