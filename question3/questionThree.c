#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int rc = fork();

    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } // end of if statement

    else if (rc == 0) {
        printf("hello\n");
    } // end of else if statement

    else {
        int i;
        int acc = 1;

        // 1 << 21 = 2^21 = 2097152. 2 to the power of 21 iterations
        for (i = 1; i < (1U << 21); i++) {
            acc *= 1;
        } // end of for loop    

        printf("goodbye\n");
    } // end of else statement

    return 0;
} // end of main function