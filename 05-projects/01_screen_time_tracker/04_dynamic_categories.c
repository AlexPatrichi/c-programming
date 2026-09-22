/*
=============================================================================
FILE: 04_dynamic_categories.c
PURPOSE: Track and compare screen time across user-defined categories
         over two consecutive weeks.
=============================================================================
*/

#include <stdio.h>
#include <string.h>

int main(void) {

/* === STEP 1: GET NUMBER OF CATEGORIES ===

Unlike the previous versions, the number of screen-time categories
is no longer fixed.

The user decides how many categories the program will track.
The value must be between 1 and 10.
*/

    // Ask the users for the number of categories
    int numCategories;

    printf("Enter number of categories: ");
    scanf("%d", &numCategories);

/* === STEP 2: INPUT VALIDATION === */
    if (numCategories < 1 || numCategories > 10) {
        printf("Please enter a number between 1 and 10.\n");
        return 1;
    }

/* === STEP 3: CREATE ARRAYS ===

The number entered by the user determines how many elements
are needed in each array.

week1[] and week2[] store the screen-time minutes.

categories[][] is a two-dimensional char array:
    first dimension  -> number of categories
    second dimension -> maximum characters for each name

For example:

    categories[0] -> "Social Media"
    categories[1] -> "Video"
    categories[2] -> "Games"
*/
    int week1[numCategories]; 
    int week2[numCategories]; 
    char categories[numCategories][30]; 

    getchar(); // Consume the '\n' left by scanf()   

/* === STEP 4: GET CATEGORY NAMES ===

A loop allows the user to name each category.

fgets() is used instead of scanf() because category
names may contain spaces, such as "Social Media".

fgets() may store the newline character entered by the user,
so it is removed before the category name is used.
*/
    for (int i = 0; i < numCategories; i++) {
        printf("Enter name of category %d: ", i + 1);
        fgets(categories[i], 30, stdin);

        // Remove newline character if present
        size_t len = strlen(categories[i]);
        if (len > 0 && categories[i][len - 1] == '\n') {
            categories[i][len - 1] = '\0';
        }
    }

/* === STEP 5: GET SCREEN-TIME FOR BOTH WEEKS ===

Each category has a corresponding position in all three arrays.

For example, if: categories[0] = "Social Media"

then:
    week1[0] -> Social Media minutes for Week 1
    week2[0] -> Social Media minutes for Week 2

The same index connects the related data.
*/

    printf("\n--- Week 1 Screen-Time ---\n");

    for (int i = 0; i < numCategories; i++) {
        printf("Enter minutes for %s: ", categories[i]);
        scanf("%d", &week1[i]);

        if (week1[i] < 0) {
            printf("Invalid minutes.\n");
            return 1;
        }
    }

    printf("\n--- Week 2 Screen-Time ---\n");

    for (int i = 0; i < numCategories; i++) {
        printf("Enter minutes for %s: ", categories[i]);
        scanf("%d", &week2[i]);

        if (week2[i] < 0) {
            printf("Invalid minutes.\n");
            return 1;
        }
    }

/* === STEP 6: CALCULATE WEEKLY TOTALS ===

Both totals start at 0.

Each loop iteration adds one category's screen time
to the corresponding weekly total.

    totalWeek1 += week1[i];

is equivalent to:

    totalWeek1 = totalWeek1 + week1[i];
*/
    
    int totalWeek1 = 0;
    int totalWeek2 = 0;

    for (int i = 0; i < numCategories; i++) {
        totalWeek1 += week1[i];
        totalWeek2 += week2[i];
    }

/* === STEP 7: DISPLAY WEEKLY BREAKDOWNS ===

Loop through each category and display its screen time.

The weekly totals are divided by 7.0 to calculate
the daily averages.
*/

    printf("\n========== WEEK 1 BREAKDOWN ==========\n");

    for (int i = 0; i < numCategories; i++) {
        printf("%s: %d minutes\n", categories[i], week1[i]);
    }

    printf("--------------------------------------\n");
    printf("Week 1 total: %d minutes\n", totalWeek1);
    printf("Week 1 daily average: %.2f minutes\n", totalWeek1 / 7.0);


    printf("\n========== WEEK 2 BREAKDOWN ==========\n");

    for (int i = 0; i < numCategories; i++) {
        printf("%s: %d minutes\n", categories[i], week2[i]);
    }

    printf("--------------------------------------\n");
    printf("Week 2 total: %d minutes\n", totalWeek2);
    printf("Week 2 daily average: %.2f minutes\n", totalWeek2 / 7.0);


/* === STEP 8: COMPARE CATEGORY TRENDS ===

Because the same index represents the same category in both
weeks, the two arrays can be compared element by element.

    week2[i] > week1[i]  -> Increase
    week2[i] < week1[i]  -> Decrease
    week2[i] == week1[i] -> No change
*/

    printf("\n========== SUMMARY ==========\n");
    printf("Week 1 total: %d minutes | Daily average: %.2f minutes\n", totalWeek1, totalWeek1 / 7.0);

    printf("Week 2 total: %d minutes | Daily average: %.2f minutes\n", totalWeek2, totalWeek2 / 7.0);

    printf("\nPer-category trends:\n");

    for (int i = 0; i < numCategories; i++) {
        printf("%s: ", categories[i]);

        if (week2[i] > week1[i]) {
            printf("Increase\n");
        } else if (week2[i] < week1[i]) {
            printf("Decrease\n");
        } else {
            printf("No change\n");
        }
    }

    return 0;
}