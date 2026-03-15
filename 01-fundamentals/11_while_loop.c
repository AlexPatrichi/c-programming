#include <stdio.h>

int main(void) {

    int score;

    do {
        printf("Enter your score (0-100): ");
        scanf("%d", &score);

        if (score < 0 || score > 100) {
            printf("Invalid score. Please enter a value between 0 and 100.\n");
        }

    } while (score < 0 || score > 100);
    // Repeat until the user enters a valid score

    switch (score / 10) {

        case 10:
        case 9:
            printf("Grade: A\n");
            break;

        case 8:
            printf("Grade: B\n");
            break;

        case 7:
            printf("Grade: C\n");
            break;

        case 6:
            printf("Grade: D\n");
            break;

        default:
            printf("Grade: F\n");
    }

    return 0;
}