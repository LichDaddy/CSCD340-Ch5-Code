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

    else if (rc == 0) {
        printf("child (pid:%d)\n", (int) getpid());
    } // end of else if statement

    else {
        int wc; 
        waitpid(rc, wc, 0);
        printf("parent of %d (status of child process:%d) (wc:%d)\n", rc, wc, (int) getpid());
    } // end of else statement 

    return 0;
} // end of main