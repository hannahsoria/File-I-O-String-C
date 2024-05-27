/**
 * task1.c
 * Hannah Soria
 * 4/25/2024
 * SIGSEGV Handler in C
 */

#include <stdio.h>
#include <stdlib.h>

// flag to determine if program should continue or quit
int quit = 0;

// function to handle interrupt signal, looking for SIGSEGV, invalid memory access
void sigsegvHandler(int signal){
    printf("\nSeqmentation Fault!\n"); // print to indicate an interrupt
    quit = 1; // the program should exit
    exit(-1);
}

int main(){
    signal(SIGSEGV, *sigsegvHandler); // call sigsegvHandler when SIGSEGV signal occurs
	int *a = NULL; // does not currently point to valid memory
    *a = 1; // trying to access the invalid memory pointer then set it to one -> result in undefined behavior
}