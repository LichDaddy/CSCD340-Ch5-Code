#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv []) {
    if (argc < 2){
        fprintf(stderr, "Not enough arguments\n");
    } // end of if statement

    // argv[0] is the name of the program
    // argv[1] is the first argument passed to the program
    int size = atoi(argv[1]);

    // make the array size 1MB times the size given
    int arraySize = size * 1024 * 1024;

    // allocate that size
    int *array = (int *) malloc(arraySize * sizeof(int));

    // will run because always true
    while (0 == 0){
        for (int i = 0; i < arraySize; i++){
            array[i] = 0;
        } // end of for loop
    } // end of while loop

} // end of main function