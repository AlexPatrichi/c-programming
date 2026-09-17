/*
=============================================================================
FILE: 01_structs.c
PURPOSE: Introduction to structs in C.
=============================================================================
*/

#include <stdio.h>
#include <string.h>

/* === WHAT IS A STRUCT? ===

A struct lets us group related variables into one structure.
Unlike an array, a structure can contain many different data types (int, float, char, etc.).
The variables inside a struct are called members.

Here, struct Product describes what information every product
in our online shop can contain. */

/* STEP 1: DEFINE PRODUCT STRUCTURE/LAYOUT */
struct Product {           // structure tag/name
    int id;                // member
    char name[50];         // member    
    char category[50];     // member
    float price;           // member
    int stock;             // member
};

// Function prototype for printing keyboard details
void print_product(struct Product item); 

int main(void){
/* STEP 2: CREATE A PRODUCT */ 

    // Create a Product structure variable called mouse
    struct Product mouse; 

/* STEP 3: ASSIGN VALUES TO ITS MEMBERS 
    
The '.' operator is used to access members of a structure. 

mouse.id        -> access the id
mouse.name      -> access the name
mouse.category  -> access the category
mouse.price     -> access the price
mouse.stock     -> access the stock   */

    // Assign values to the members of mouse
    mouse.id = 1;  // structure variable.member we want to access
    strcpy(mouse.name, "Logi");
    strcpy(mouse.category, "Electronics");
    mouse.price = 29.99f;
    mouse.stock = 25;

/* STEP 4: CREATE AND INITIALIZE ANOTHER PRODUCT

Instead of creating the structure first and assigning each member
later, we can initialize all its members when it is created.

The values follow the same order as the members in struct Product. */
    struct Product keyboard = {2, "Keychron", "Electronics", 99.99f, 10};

/* STEP 5: PRINT PRODUCT DETAILS

Because each member has its own data type and format specifier, we can print 
the members one at a time. */
    printf("\nMouse Details (one at the time):\n");
    printf("ID: %d\n", mouse.id);
    printf("Name: %s\n", mouse.name);
    printf("Category: %s\n", mouse.category);
    printf("Price: £%.2f\n", mouse.price);
    printf("Stock: %d\n", mouse.stock);

/* Instead of repeating all the printf() statements for every product,
we can pass a Product structure to a function. */
    printf("\nKeyboard Details (using a function):\n");
    print_product(keyboard);

    return 0;
}

/* === PRINT PRODUCT FUNCTION ===

struct Product -> parameter type
item           -> parameter name

The entire keyboard structure is passed to item when we call:
    print_product(keyboard);   */

void print_product(struct Product item) {
    printf("ID: %d\n", item.id);
    printf("Name: %s\n", item.name);
    printf("Category: %s\n", item.category);
    printf("Price: £%.2f\n", item.price);
    printf("Stock: %d\n", item.stock);
}