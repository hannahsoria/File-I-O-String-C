/**
 * task1.c
 * Hannah Soria
 * 4/25/2024
 * 
 * implement a word counter that is able to count the number of occurrences of every word in a text file using a linkedlist
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "linkedlist.c"
#include "linkedlist.h"

// define a struct that will be the type of every node in the list
// the struct contains both the word and the matching frequency
typedef struct {
    char word[1000];
    int frequency;
    } Frequency;

// function used to compare two strings, this is compatible to the linkedlist
int compareStrings(void *str1, void *str2) {
    return strcmp(((Frequency *)str1)->word, ((Frequency *)str2)->word);
}

int main(int agrc, char *argv[]){
    LinkedList *counter; // create a linkedlist that hold the frequencies of words
    counter = ll_create(); // create a linkedlist that hold the frequencies of words

    // check if there 2 arguments = valiid
    if(agrc < 2){
        printf("error: missing arguments");
        return 1;
    }

    // check if filename is valid
    if(argv[1] == NULL){
        printf("error: ivalid filename");
        return 1;
    }

    //open the file and 
    FILE *fp = fopen(argv[1],"r");

    char word[100]; // this char holds the word that is currently being handled

    // this scans through the file
    while(fscanf(fp, "%s", word) != EOF){
        
        // convert the words to lowercase and get rid of periods and commas
        for(int i=0; word[i]; i++){
            if(word[i] != '.' && word[i] != ','){
                word[i] = tolower(word[i]);
            }
        }

        // updating the frequency
        Frequency *newFrequency = (Frequency *)malloc(sizeof(Frequency)); // create a new frequency struct
        strcpy(newFrequency->word, word); // copy the current word into the frequency word

        Frequency *existingFrequency = ll_find(counter, newFrequency, compareStrings); // set finding the newFrequency to a variable if it is already found in the list
        if (existingFrequency != NULL){ // if not null, meaning that the word has been found in the list
            existingFrequency->frequency++; // increase the frequency count
        } else {
            newFrequency->frequency = 1; // if the word did not already exist in the list then set the frequency to 1
            ll_append(counter, newFrequency); // add the frequency struct to the end if the list
        }
    }

    // Find and store the top 20 frequencies
    node *current = counter->head; // set a variable current to the head of the list
    Frequency *topFreqs[20] = {NULL}; // array of frequencies, to store pointers to the top 20 frequencies

    while (current != NULL) { // goes through the entire list
        Frequency *freq = (Frequency *)current->data; // freq is the current frequency being handled

        // Check if the current frequency is higher than any in the top 20
        for (int i = 0; i < 20; i++) { // loop to through top 20
            if (topFreqs[i] == NULL || freq->frequency > topFreqs[i]->frequency) { // if the current topFreg array element is null or if the current frequency is larger than the one in the current spot
                
                // freq should be inserted at i 
                // have to move the other elements so freq can be inserted at i
                for (int j = 19; j > i; j--) { // loop to start at the last position in the array and move towards i
                    topFreqs[j] = topFreqs[j - 1]; // shift all elements 
                }
                topFreqs[i] = freq; // store the new freq in the top 20
                break;
            }
        }
        current = current->next; // go to the next struct in the list
    }

// Print the top 20 frequencies
for (int i = 0; i < 20 && topFreqs[i] != NULL; i++) {
    printf("Word: %s \t\t Frequency: %d\n", topFreqs[i]->word, topFreqs[i]->frequency);
}
    return 0;
}
