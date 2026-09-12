/*
=============================================================================
FILE: 05_dynamic_memory.c
PURPOSE: Introduction to dynamic memory allocation in C.
=============================================================================
*/      

#include <stdio.h>
#include <stdlib.h> // Dynamic memory functions

int main(void) {
    
  int products;

/* Normally, variables and arrays have a size decided when we write
the program. 
Dynamic memory is useful when we do not know beforehand how much memory 
the program will need.

The required amount might become known only while the program is already running.

For example, here we do not know how many products the user wants to track 
until they enter a number. */

    /* STEP 1: Ask how many products we initially need. */
    printf("How many products do you want to track?\n");
    printf("Input: ");
    scanf("%d", &products); 

/* 1. malloc() 
Allows us to request memory while the program is running.
    
    Visual example: 
    sizeof(int)                  -> memory needed for one int
    products * sizeof(int)       -> memory needed for all products
    malloc(...)                  -> requests that amount of memory
    malloc(...)                  -> returns the address of that memory
    int *stock                   -> stores that address    */

    /* STEP 2: Allocate memory for those products using malloc(). */
    int *stock = malloc(products * sizeof(int)); 

/* In most cases, malloc() successfully allocates the requested memory,
but sometimes it can fail.

If malloc() fails, it returns NULL.
We should check for NULL before trying to use the allocated memory. */
    
    /* STEP 3: Check if malloc() worked. */
    if (stock == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Stop the program because something went wrong
    }

    /* STEP 4: Enter the stock values into the allocated memory. */
    // The allocated memory can now be used like an array.
    for (int i = 0; i < products; i++) {
        printf("Enter stock for product %d: ", i + 1);
        scanf("%d", &stock[i]);
    }

    printf("\nWarehouse stock using malloc:\n");
    for (int i = 0; i < products; i++) {
        printf("Product %d: %d\n", i + 1, stock[i]);
    }

/* There is one crucial rule: 
Memory obtained with malloc() needs to be released when it is no longer needed.

    free(stock);

In this scenario, we will use it alongside realloc() example. 
*/

/* 2. realloc()
Using malloc() we already allocated memory for a certain number of products.

If the warehouse adds more products, instead of starting over, we can use realloc() 
to resize the existing dynamically allocated memory.
*/

    int old_products = products; // Remember the old size
    int added_products;

    /* STEP 5: Ask how many new products are being added. */
    printf("\nHow many new products are being added?\n");
    printf("Input: ");
    scanf("%d", &added_products); 

    /* STEP 6: Calculate and update the total */
    products = old_products + added_products; 

    /* STEP 7: Resize the existing memory using realloc().*/
    int *temp = realloc(stock, products * sizeof(int)); 

    /* STEP 8: Check if realloc() worked */
    if (temp == NULL) {
        printf("Memory reallocation failed!\n"); 
        free(stock); // Release the memory
        return 1; // Stop the program because something went wrong
    } 

    stock = temp; // Update stock to point to the resized memory

    /* STEP 9: The old stock values are kept.
    We only need to enter values for the newly added products. */
    for (int i = old_products; i < products; i++) {
        printf("Enter stock for new product %d: ", i + 1);
        scanf("%d", &stock[i]);
    }

    /* STEP 10: Print all products after resizing the memory. */
    printf("\nWarehouse stock after realloc:\n");
    for (int i = 0; i < products; i++) {
        printf("Product %d: %d\n", i + 1, stock[i]);
    } 

    /* STEP 11: We are finished with this memory, so release it. */
    free(stock); 
    
/* 3. calloc() 
Is another way to request dynamic memory.
Allocates memory and initializes it to zero.

    malloc(products * sizeof(int)) -> requests memory
    calloc(products, sizeof(int))  -> requests memory and initializes it to zero bytes
*/
    /*STEP 12: calloc() creates a new block of dynamic memory
    and initializes it to zero.*/
    int *new_stock = calloc(products, sizeof(int));

    /* STEP 13: Check if calloc() worked */
    if(new_stock == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Stop the program because something went wrong
    }

    /* STEP 14: Show that the fresh memory starts at zero. */
    printf("\nInitial values using calloc:\n");
    for (int i = 0; i < products; i++) {
        printf("Product %d: %d\n", i + 1, new_stock[i]);
    }

    /* STEP 15: Release the memory created with calloc(). */
    free(new_stock);

    return 0;
}