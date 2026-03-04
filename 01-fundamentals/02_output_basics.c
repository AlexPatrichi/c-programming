#include <stdio.h>  

int main(void) {  
    // A computer program is a list of statements (instructions) that a computer executes sequentially, from top to bottom.
    printf("First line!\n");  //Statement 1
    printf("Second line!\n"); //Statement 2
    printf("Third line!\n");  //Statement 3
   
    // Without a newline character (\n), the cursor stays on the same line.
    // Therefore, the second printf continues printing from the current position.
    printf("Hello, "); //Statement 4
    printf("World!");  //Statement 5
    
return 0; // Statement 6
}

/* This program contains multiple statements. 
Each printf() is a statement that outputs text to the console, 
and the return statement indicates that the program has finished executing successfully.
*/