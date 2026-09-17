/*
=============================================================================
FILE: 03_file_io.c
PURPOSE: Introduction to file handling in C.
=============================================================================
*/

/* === WHAT IS FILE I/O? ===

File I/O (Input/Output) allows a program to read data from files
and write data to files.

    Output -> program writes data TO a file
    Input  -> program reads data FROM a file

Working with a file usually follows this lifecycle:

    Open/Create File -> Check -> Read or Write Data -> Close File
*/

#include <stdio.h>

/* === FILE POINTER ===

In C, FILE is a data type provided by <stdio.h> that is used to
represent a file.

To work with a file, we normally create a pointer to FILE:

    FILE *fptr;

    FILE    -> data type
    *       -> declares a pointer
    fptr    -> pointer variable

The FILE pointer is then used by file functions to work with the file.
*/

int main(void){
/* ==================== WRITING TO A FILE ==================== */

/* === STEP 1: OPEN/CREATE A FILE ===

In C, creating and opening are often the same operation.
To work with a file, we first need to open it using fopen().

fopen() syntax: fopen("filename", "mode");
    "filename" -> the name of the file 
    "mode"     -> what you want to do with file

Modes:
    "w" - WRITE to a file (creates it or overwrites existing contents)
    "a" - APPEND to a file (adds data to the end)
    "r" - READ from an existing file

If you want to create the file in a different directory, you can specify 
the absolute path in the filename.

FILE *file = fopen("a:\\GitHub\\c-programming\\04-structs-files\\shop_report.txt", "w");

If no path is specified, the file is opened/created in the current 
working directory.

If the file already exists, it will be overwritten in "w" mode.
*/

    FILE *file = fopen("shop_report.txt", "w");
    
/* === STEP 2: CHECK IF THE FILE OPENED ===

fopen() returns a pointer that represents the opened file.
If the file cannot be opened, fopen() returns NULL.

As a good practice, we should always check if the file was opened successfully.
*/

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1; // Exit the program with an error code
    }

/* === STEP 3: WRITE DATA TO THE FILE ===

We can use fprintf() to write formatted data to a file.

fprintf() works similarly to printf(), but its first argument is the FILE pointer 
that tells C which file to write to.

    printf("Hello");             -> prints to the screen
    fprintf(file, "Hello");      -> writes to the file
*/

    fprintf(file, "=== ONLINE SHOP REPORT ===\n");
    fprintf(file, "ID: %d\n", 101);
    fprintf(file, "Product: HP Laptop\n");
    fprintf(file, "Price: £%.2f\n", 899.99);
    fprintf(file, "Stock: %d\n", 25);

/* === STEP 4: CLOSE THE FILE ===

Now that we are finished working with this file, we should close it using fclose().

We pass our FILE pointer to fclose() so C knows which file to close.

    fclose(file);

After closing the file, we should no longer use that FILE pointer
to read from or write to the file.
*/

    fclose(file);
    printf("Shop report created successfully!\n"); 

/* ==================== READING FROM A FILE ==================== */

/* === STEP 1: OPEN THE FILE FOR READING ===

To read the file contents, we open it again, this time using "r" mode.
Unlike "w", "r" expects the file to already exist.

If the file cannot be opened, fopen() returns NULL.
*/
    file = fopen("shop_report.txt", "r");

/* === STEP 2: CHECK IF THE FILE OPENED === */

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1; // Exit the program with an error code
    }

/* === STEP 3: READ DATA FROM THE FILE ===

fgets() - helps us to read text from a file.

Instead of reading from stdin (keyboard input), it now reads
from the file represented by our FILE pointer.

We need a char array where the text can be stored.
*/

    char line[100]; // Buffer to hold each line read from the file

/* === STEP 4: READ UNTIL THE END OF THE FILE === 

fgets() reads one line at a time.

When fgets() successfully reads a line, we can print that line.
When there is nothing left to read, fgets() returns NULL.

Therefore, we can use a while loop to keep reading until
we reach the end of the file.
*/

    printf("\n=== READING SHOP REPORT ===\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); // Print the line read from the file
    }

/* === STEP 5: CLOSE THE FILE AFTER READING ===

After we are done reading from the file, we should close it again.
*/
    fclose(file);

/* ==================== APPENDING TO A FILE ==================== */

/* === STEP 1: APPEND DATA TO THE FILE ===

Opening a file with "a" keeps the existing contents and adds
new data at the end of the file.
*/
    file = fopen("shop_report.txt", "a");

/* === STEP 2: CHECK IF THE FILE OPENED === */
    if (file == NULL) {
        printf("Error opening file for appending!\n");
        return 1; // Exit the program with an error code    
    }

/* === STEP 3: APPEND DATA TO THE FILE === */
    fprintf(file, "\nStatus: Product Available\n");

/* === STEP 4: CLOSE THE FILE AFTER APPENDING === */
    fclose(file);

    printf("\nNew data appended successfully!\n");

    return 0;
}