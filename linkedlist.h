/**
 * linkedlist.h
 * Hannah Soria
 * 4/14/2024
 * 
 * linkedlist header file
 * 
 */

#ifndef LINKEDLISTHEADER
#define LINKEDLISTHEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    void *data;
    struct node* next;
} node;

typedef struct LinkedList {
    node *head;
    int count;
} LinkedList;

/**
 * @brief creates a new LinkedList struct, initializes it, and returns it.
 * @return a reference to the linked list
*/
LinkedList *ll_create();

/**
 * @brief adds a node to the front of the list, storing the given data in the node.
 * @param linkedlist, data
*/
void ll_push(LinkedList *ll, void *data);

/**
 * @brief  removes the node at the front of the list and returns the associated data.
 * @param linkedlist
*/
void *ll_pop(LinkedList *ll);

/**
 * @brief adds a node to the end of the list, storing the given data in the node.
 * @param linkedlist, data
*/
void ll_append(LinkedList *ll, void *data);

/**
 * @brief removes the first node in the list whose data matches target given the comparison function.
 * @param linkedlist, target
 * @return the pointer to the data in the removed node.
*/
void *ll_remove(LinkedList *ll, void *target, int (*compfunc)(void *, void *));

/**
 * @brief finds the first node in the list whose data matches target given the comparison function. 
 * @param linkedlist
 * @return the pointer to the data in the node. If the target is not in the list
*/
void *ll_find(LinkedList *ll, void *target, int (*compfunc)(void *, void *));

/**
 * @brief returns the size of the list
 * @param linkedlist
 * @return the size of the list
*/
int ll_size(LinkedList *ll) ;

/**
 * @brief removes all of the nodes from the list, freeing the associated data using the given function.
 * @param linkedlist, function
*/
void ll_clear(LinkedList *ll, void (*freefunc)(void *));

/**
 * @brief traverses the list and applies the given function to the data at each node.
 * @param linkedlist, function
*/
void ll_map(LinkedList *ll, void (*mapfunc)(void *));

#endif