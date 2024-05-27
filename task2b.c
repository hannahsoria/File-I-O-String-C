/**
 * task1.c
 * Hannah Soria
 * 4/25/2024
 * SIGFPE Handler in C
 */

#include <stdio.h>
#include <stdlib.h>

// flag to determine if program should continue or quit
int quit = 0;

// function to handle interrupt signal, looking for SIGFPE meaning requested computation cannot be performed
void sigfpeHandler(int signal){
    printf("\nFloating Point Exception!\n"); // print to indicate an FPE
    quit = 1; // the program should exit
    exit(-1);
}

int main(){
    signal(SIGFPE, *sigfpeHandler); // call sigfpeHandler when SIGFPE signal occurs
	int i = 1;
    int result = i/0; // invalid operation
    printf("result: %f\n", result); // line should never be reached, but it would be if the program kept running
}