/**
 * task1.c
 * Hannah Soria
 * 4/25/2024
 * SIGINT Handler in C
 */

#include <stdio.h>
#include <stdlib.h>

// flag to determine if program should continue or quit
int quit = 0;

// function to handle interrupt signal, looking for SIGINT signal (ctrl-C)
void sigintHandler(int signal){
    printf("\nInterrupted!\n"); // print to indicate an interrupt
    quit = 1; // the program should exit
    exit(-1);
}

int main(){
    signal(SIGINT, *sigintHandler); // call sigintHandler when SIGINT signal occurs
	while (!quit) // runs until quit value changes
	{
		// infinite loop
	}
}