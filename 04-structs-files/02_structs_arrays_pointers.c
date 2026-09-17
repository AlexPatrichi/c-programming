/*
=============================================================================
FILE: 02_structs_arrays_pointers.c
PURPOSE: Working with arrays and pointers to structs in C.
=============================================================================
*/

#include <stdio.h>

/* Each Product contains information about one item in our online shop. */
struct Product {
    int id;
    char name[50];
    char category[50];
    float price;
    int stock;
};

void print_product(struct Product item);
void update_stock(struct Product *item, int new_stock);

int main(void) {
/* === STEP 1: ARRAY OF STRUCTS ===

Just like we can create an array of int: int numbers[3];
We can create an array of structures: struct Product products[3];

Each element of the array is a complete Product structure.
    products[0] -> first Product
    products[1] -> second Product
    products[2] -> third Product
*/
    
    struct Product products[3] = {
        {1, "Logi Mouse", "Electronics", 29.99f, 25},
        {2, "Keychron Keyboard", "Electronics", 99.99f, 10},
        {3, "USB-C Cable", "Accessories", 12.99f, 40}
    };
    
/* === STEP 2: ACCESS STRUCTS INSIDE THE ARRAY ===

First we select an element from the array: products[0]
Then we use '.' to access one of its members:
    products[0].name
    products[0].price

So: products[i].member
         ↑        ↑
      Product    member
*/   
    printf("First product: %s\n", products[0].name);
    printf("Price: £%.2f\n", products[0].price);
    

/* === STEP 3: LOOP THROUGH AN ARRAY OF STRUCTS ===

Because products is an array, we can use a loop to process every Product 
in the catalogue.
*/
    printf("\n=== ONLINE SHOP CATALOGUE ===\n");

    for (int i = 0; i < 3; i++) {
        printf("\nProduct %d\n", i + 1);
        print_product(products[i]);
    }

/* === STEP 4: POINTER TO A STRUCT ===

A pointer can also store the address of a structure.
    products[0]       -> first Product structure
    &products[0]      -> address of the first Product
    product_ptr       -> stores that address
*/

    struct Product *product_ptr = &products[0];

/* Usually we access struct members with '.': products[0].price

When we have a POINTER to a structure, we can access its members using 
the '->' operator: product_ptr->price

The '->' operator means: access a member through a pointer to a structure.

product_ptr->price is a shorter version of (*products_ptr).price
*/  
    printf("\n=== STRUCT POINTER ===\n");
    printf("Name: %s\n", product_ptr->name);
    printf("Price: £%.2f\n", product_ptr->price);

/* === STEP 5: MODIFY A STRUCT THROUGH A POINTER ===

Because product_ptr points to the original Product, we can also change its members.
*/

    product_ptr->price = 24.99f;

    printf("\nNew mouse price: £%.2f\n", products[0].price);

/* === STEP 6: PASS A STRUCT ADDRESS TO A FUNCTION ===

Instead of passing: products[0]
We pass its address: &products[0]
The function receives that address using: struct Product *item

This allows the function to modify the original Product.
*/
    update_stock(&products[0], 30);
    printf("New mouse stock: %d\n", products[0].stock);

    return 0;
}

/* Print a Product.

The structure is passed by value, so item receives a copy. 
The function can read the copy, but changing it would not change the
original Product. */

void print_product(struct Product item) {

    printf("ID: %d\n", item.id);
    printf("Name: %s\n", item.name);
    printf("Category: %s\n", item.category);
    printf("Price: £%.2f\n", item.price);
    printf("Stock: %d\n", item.stock);
}

/* Update the original Product.

item is a pointer to a Product, so we use -> to access
the Product's members through the pointer. */

void update_stock(struct Product *item, int new_stock) {
    item->stock = new_stock;
}