/*
==============================================================================
FILE: 10_nested_switch.c
PURPOSE: Demonstrates nested switch statements by building a simple calculator.
==============================================================================
*/

#include <stdio.h>

int main(void) {
/* Nested switch statements allow a program to make multiple levels of decisions. */

    int category, operation;
    double num1, num2; 

    printf("=== Simple Calculator ===\n");
    printf("Select category:\n");
    printf("1. Basic arithmetic \n2. Advanced operations\n");
    scanf("%d", &category);

/*  Nested switch program flow: 

        User selects category
                 ↓
        Outer switch runs
                 ↓
        User selects operation
                 ↓
        Inner switch runs
                 ↓
        Program calculates result  */

    switch (category) {  // Outer switch handles category.
        case 1: // Basic arithmetic
            printf("Select operation:\n\t1. Add\n\t2. Subtract\n\t3. Multiply\n\t4. Divide\n");
            scanf("%d", &operation);

            printf("Enter first number: ");
            scanf("%lf", &num1);

            printf("Enter second number: ");
            scanf("%lf", &num2);
    
        switch (operation) { // Inner switch handles the operation inside the category.
        // This decides which calculation to perform.
            case 1:  //Add 
                printf("Result: %.2lf\n", num1 + num2);
                break;
            case 2: //Subtract 
                printf("Result: %.2lf\n", num1 - num2);
                break;
            case 3: //Multiply
                printf("Result: %.2lf\n", num1 * num2);
                 break;
            case 4: //Divide 
                 if(num2 != 0){
                     printf("Result: %.2lf\n", num1 / num2); 
                } else {
                    printf("Error! Division by zero.\n");
                }
                 break;

             default:
                printf("Invalid operation!\n");  
        }
        break;
        
        case 2:
            printf("Advanced operations not implemented yet.\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}



    