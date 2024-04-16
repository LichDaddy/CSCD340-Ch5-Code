#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

    int rc = fork();

    // if the fork fails, print an error message and exit
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } // end of if statement

    // child: redirect standard output to a file
    else if (rc == 0) {
        close(STDOUT_FILENO);
        // this does not work because we closed the file descriptor for STDOUT_FILENO
        printf("See if we can still print after closing STDOUT_FILENO\n");
    } // end of else if statement

    else {
        // simple print statement
        fprintf(stderr, "in the parent\n");        
    } // end of else statement

    return 0;
}