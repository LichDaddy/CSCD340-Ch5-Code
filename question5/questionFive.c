#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    printf("hello (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } // end of if statement

    // just testing what happens when we wait for the child process
    else if (rc == 0) {
        int wc = wait(NULL);
        printf("child (wc:%d) (pid:%d)\n", wc, (int) getpid());
    } // end of else if statement

    else {
        printf("parent of %d (pid:%d)\n", rc, (int) getpid());
    } // end of else statement 

    return 0;
} // end of main