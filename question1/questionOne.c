#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x = 0;
    x = 100;

    printf("Initial value of x: %d\n", x);

    // fork a child process
    int rc = fork();

    // if the fork fails, print an error message and exit
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } // end of if statement 
    
    // if the fork is successful, print the child value of x
    else if (rc == 0) {
        x = 666;
        printf("Child: x = %d\n", x);
    } // end of else if statement 
    
    // if the fork is successful, print the parent value of x
    else {
        x = 333;
        printf("Parent: x = %d\n", x);
    } // end of else statement

    printf("End value of x: %d\n", x);

    // need to print a return 0 in C to indicate that the program ran successfully
    return 0;
} // end of main function