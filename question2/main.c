#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

    //////////////////////////////////////
    // THIS IS OBVIOUSLY FOR QUESTION 2 //
    //////////////////////////////////////

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
        open("./child.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

        // we are creating a pointer of char because we can use this 
        // to pass in strings efficiently to the execvp function
        char *myargs[3];
        // open the file to write to and to see the output of the hexdump command if it will open the file twice
        myargs[0] = strdup("hexdump"); // this is like piping in the command "wc" into the terminal
        myargs[1] = strdup("main.c"); // the file we want to count
        myargs[2] = NULL; // placeholder for the end of the array
        execvp(myargs[0], myargs); // this is like running the command "hexdump loren.txt" in the terminal

    } // end of else if statement

    // parent: wait for the child to complete
    // parent goes down this path (original process)
    else {
        
        close(STDOUT_FILENO);
        // open the file to write to and to see the output of the wc command if it will open the file twice
        open("./parent.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);      

        char *myargs[3];
        // we are diffrerentiating the two commands by using the -l flag in the wc command
        myargs[0] = strdup("wc"); // this is like piping in the command "wc -l" into the terminal
        myargs[1] = strdup("main.c"); // the file we want to count
        myargs[2] = NULL; // placeholder for the end of the array
        execvp(myargs[0], myargs); // this is like running the command "wc loren.txt" in the terminal  

        // simple print statement to check if we are in the parent process
        fprintf(stderr, "in the parent\n");        

    } // end of else statement

    return 0;
}