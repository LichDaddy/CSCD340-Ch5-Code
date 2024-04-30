#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv []) {
    if (argv < 2){
        fprintf(stderr, "Not enough arguments\n");
    } // end of if statement

    // argv[0] is the name of the program
    // argv[1] is the first argument passed to the program
    int size = atoi(argv[1]);

} // end of main function