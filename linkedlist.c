/**
 * linkedlist.c
 * Hannah Soria
 * 4/14/2024
 * 
 * create a linkedlist
 * 
 */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/** creates a new LinkedList struct, initializes it, and returns it.*/
LinkedList *ll_create(){
    LinkedList *ptr = (LinkedList*)malloc(sizeof(LinkedList));
    ptr->count = 0;
    return ptr;
}

/** adds a node to the front of the list, storing the given data in the node.*/
void ll_push(LinkedList *ll, void *data){
    node *new_node = (node*)malloc(sizeof(node)); //create a new node
    new_node->data = data; //store the param data in the node
    new_node->next = ll->head; // assign next pointer to the head
    ll->head = new_node; // new node is set to the head node
    ll->count++; // increment the count
}

/** removes the node at the front of the list and returns the associated data.*/
void *ll_pop(LinkedList *ll){
    node *head_ptr = ll->head; // ptr to the head
    void *head_data = ll->head->data; // head data stored in newData, void always for polymorphism
    ll->head = head_ptr->next; // set the next for head
    free(head_ptr); // free the node
    ll->count--; //decrement count of elements
    return head_data; // data of the popped node
}

/** adds a node to the end of the list, storing the given data in the node.*/
void ll_append(LinkedList *ll, void *data){
    node *new_node = (node*)malloc(sizeof(node)); // create the new node
    new_node->data = data; // give the new node the param data
    new_node->next = NULL; //null bc its the last node

    if(ll_size(ll)==0){
        ll->head = new_node; // new_node is assigned to the head
    } else {
        node *current_node = ll->head; // head is assigned to current node 
        while (current_node->next != NULL) { 
            current_node = current_node->next; // reassign the current node to the next node
        }
        current_node->next = new_node; // new node assgined to next after current node
    }
    ll->count++; // increment the count of elements 
}

/** removes the first node in the list whose data matches target given the comparison function.*/
void *ll_remove(LinkedList *ll, void *target, int (*compfunc)(void *, void *)){
    node *current_node = ll->head; // current node set to head
    node *before_move = NULL;
    void *target_data = NULL;
    
    // iterate through the linked list
    for(int i=0; i<ll_size(ll); i++){
        if(compfunc(current_node->data, target)!= 0){ // check if current node matches target
            node *temp_node = current_node;
            if(i==0){ // the data is equal to the target
                ll->head = temp_node->next; // set head to the next node
            } else { // data does not equal the target
                before_move->next = temp_node->next; // go to next
            }
            target_data = temp_node->data; // data of removed node stored
            free(temp_node);
            ll->count--;
            break; //because the only match needed has been found
        } else {
            before_move = current_node;
            current_node = current_node->next;
        }
    }
    return target_data;
    
}

/** finds the first node in the list whose data matches target given the comparison function. */
void *ll_find(LinkedList *ll, void *target, int (*compfunc)(void *, void *)){
    node *current_node = ll->head; // current node set to head

    //loop through the linkedlist
    while (current_node != NULL){
        if (compfunc(current_node->data, target) == 0){ // if target is found
            return current_node->data;
        }
        current_node = current_node->next; //go to the next node
    }
    return NULL; // if no match is found
}

/** returns the size of the list */
int ll_size(LinkedList *ll){
    return ll->count;
}

/** removes all of the nodes from the list, freeing the associated data using the given function.*/
void ll_clear(LinkedList *ll, void (*freefunc)(void *)){
    node *current_node = ll->head; // current node is the head

    //loop through the linkedlist
    while (current_node != NULL) {
        node *temp_node = current_node; // set the current as temp
        current_node = current_node->next; // move the current to next
        freefunc(temp_node->data); // free temp data
        freefunc(temp_node); // free the node
    }
    ll->head = NULL; // null because clear
    ll->count = 0; // 0 because empty
}

/** traverses the list and applies the given function to the data at each node. */
void ll_map(LinkedList *ll, void (*mapfunc)(void *)){
    node *current_node = ll->head; // set the current node to the head
    while (current_node != NULL){
        mapfunc(current_node->data); 
        current_node = current_node->next; // current node looks at next node
    }
}
