/*
=======================================================================
FILE: 06_operators.c
PURPOSE: Demonstrates arithmetic, assignment, and relational operators
using an online clothing shopping cart example.
=======================================================================
*/

#include <stdio.h>

int main(void){
// Operators are symbols that allow us to perform operations on variables and values.
    printf("=== Online Clothing Shopping Cart ===\n\n");

    // Item quantities
    int shirts = 2;
    int pants = 1;
    int shoes = 3;

    // Item prices
    double shirt_price = 15.50;
    double pant_price = 40.00;
    double shoe_price = 59.99;  

    // Calculate total cost using arithmetic operators
    printf("Cart:\n");       // Show initial cart
    double total_cost = 0.0; // Basic assignment. Start with an empty cart.

    total_cost += shirts * shirt_price; // Compound assignment. 
    total_cost += pants * pant_price;  
    total_cost += shoes * shoe_price;   
    /*The addition assignment operator (+=) is a shorthand way to update 
    the total cost by adding the cost of each item. */
    printf("Shirts: %d, Pants: %d, Shoes: %d\n\n", shirts, pants, shoes);

// Increment items using assignment operators
    shirts++;  // Added one more shirt to the cart (shirts = shirts + 1)
    pants--;   // Removed one pair of pants from the cart (pants = pants - 1)
    printf("Added one more shirt. New quantity: %d\n", shirts);
    printf("Removed one pair of pants. New quantity: %d\n\n", pants);

    printf("Total cost before discount: £%.2f\n", total_cost);

// Using integer division for Special Offer: Buy 2 shoes, get 1 free
    int free_shoes = shoes / 3;  // Integer division gives the number of free shoes
    printf("Special Offer: Buy 2 shoes, get 1 free.\n");
    printf("Free shoes: %d\n", free_shoes);
    shoes = shoes - free_shoes;  // Update shoe quantity after applying the offer
    // Alternatively, readable math: shoes -= free_shoes;

    total_cost = (shirts * shirt_price) + (pants * pant_price) + (shoes * shoe_price);
    // Update the total cart cost after applying the special offer
    // C simply follows standard math rules. 
    // Parentheses () control order of the calculations.
    printf("Total cost after applying special offer: £%.2f\n", total_cost);

// Apply a discount using subtraction and multiplication operators
    const double discount_rate = 0.10;     // 10% discount
    total_cost = total_cost * (1 - discount_rate);
    // Alternatively, readable math: total_cost *= (1 - discount_rate); 
    // Using assignment operators can make the code more concise and easier to read.
    printf("Total cost after discount: £%.2f\n", total_cost);

// Apply tax using addition and multiplication operators
    const double tax_rate = 0.15;          // 15% tax
    total_cost = total_cost * (1 + tax_rate);
    // Alternatively, readable math: total_cost *= (1 + tax_rate);  
    printf("Total cost after tax: £%.2f\n", total_cost);
    printf("\nFinal cart total: £%.2f\n", total_cost);

// Check the budget using relational operators
    double budget = 150.00;
    printf("Budget: £%.2f\n", budget); 

    int within_budget = total_cost <= budget;  
    // They helps us to compare values and make decisions.
    printf("Is the total cost within the budget? %d (1 = Yes, 0 = No)\n", within_budget);  
    // 1 for true, 0 for false

    return 0;
}