/*
=============================================================================
FILE: 04_arrays.c
PURPOSE: Introduces arrays and basic data processing

TOPICS COVERED:
- Array declaration and initialization
- Accessing elements
- Looping through arrays
- Basic calculations (sum, average, max, min)

PROGRAM FEATURES:
- User input for multiple values
- Data analysis using loops
=============================================================================
*/

#include <stdio.h>

int main(void) {
/* An array is a collection of values of the same type stored in a single variable */

    int grades[10]; // Declare an array of 10 integers to store grades

/* All elements in an array must be of the same data type
   Array indexes start at [0] - first element, [1] - second element, etc */

/* Another way to initialize an array is to specify the values at the time of declaration
   The size of the array is fixed after declaration
   You can change existing elements, but you cannot increase its size

   1.Declare an array of 3 integers
    int grades[3] = {85, 90, 78}; 

   2. Add elements
    grades[0] = 85; // First element
    grades[1] = 90; // Second element  
    grades[2] = 78; // Third element */

    // Input values into the array
    printf("Enter 10 grades:\n");
    for (int i = 0; i < 10; i++) {
        printf("Grade %d: ", i + 1);
        scanf("%d", &grades[i]);
    }
    
/*Get Array Size:
- Knowing the memory size of an array is important for larger programs that require good memory management
- sizeof(array) gives the total size of the array in bytes (int type = 4 bytes, so 10 elements * 4 bytes = 40 bytes)
- sizeof(array[0]) gives the size of a single element in bytes 
- dividing them gives the number of elements */
    int array_size = sizeof(grades) / sizeof(grades[0]);
    printf("\nArray contains %d elements\n", array_size);

    // Calculate sum, average, max, and min
    int sum = grades[0];
    int max = grades[0];
    int min = grades[0];

    for (int i = 1; i < array_size; i++) { // Loop through the array to calculate sum, max, and min
        sum = sum + grades[i]; // Keep adding each grade to total

/*To access an array element, refer to its index number -> grades[i]
  To change an array element, assign a new value to it -> grades[i] = 85;*/
        if (grades[i] > max) { // If current grade is greater than max, update max
            max = grades[i];
        }

        if (grades[i] < min) { // If current grade is less than min, update min
            min = grades[i];
        }
    }

    double average = (double)sum / array_size; // Calculate average by dividing sum by number of elements

    // Output the results
    printf("\n--- Results ---\n");
    printf("Total Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Highest Grade: %d\n", max);
    printf("Lowest Grade: %d\n", min);

    return 0;
}