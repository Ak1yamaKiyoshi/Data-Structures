#include <stdio.h>
#include <malloc.h>


// Node structure
struct Node {
    int value; // Node value 
    struct Node *next; // Pointer to next element
} *head = NULL; // Head of list

typedef struct Node nNode;


/* 
 * nNode* allocateNode(int value)
 * Function allocates new node with value 
 * Parameters: 
 *      int value - value of allocated node
 * Returns: nNode newNode
*/ 
nNode* allocateNode(int value) {
    nNode *newNode = (nNode*)malloc(sizeof(nNode)); // Allocate Node to append
    if (newNode == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return NULL;
    }
    newNode->value = value; 
    newNode->next = NULL; // because we assert that last node in list will have NULL as next pointer, so we know where list ends, otherwise, there is now way to know that
    return newNode;
}


/* 
 * Function appends new node at the end of list
 * Parameters: 
 *      nNode *list - pointer to head of the list
 *      int value - value to be added
 * Returns: 
 *      int result of execution (1 - on success, 0 - on fail)
 *      if function successeds, list pointer would be changed
*/ 
int append(nNode *list, int value) {
    nNode *newNode = allocateNode(value);
    if (!newNode) return 0; 

    if (list) { // if list is not empty 
        while (list->next) // While next node is not null
            list = list->next; // Move pointer to next node
        list->next = newNode; // append new node to last node of the list
        return 1;
    } else { // if list is NULL
        list = newNode;  // list will be newNode 
        return 1;
    }
    return 0; // if none of expression worked 
}


/* 
 * Function prints list from left to right 
 * Parameters: 
 *      nNode *list  
 * Returns:
 *      no returning values
*/ 
void print(nNode *list) {
    while (list) { // while head is not NULL
        printf("%d ", list->value); // print current node value 
        list = list->next; // move list pointer to next node 
    }
}


/*
 * Function traverses list and counts nodes (lenght)
 * Parameters: 
 *      nNode *list - list to find lenght of 
 * Returns: 
 *      int lenght - lenght of given list
*/
int length(nNode *list) {
    int lenght = 0;
    for (;list; list=list->next, lenght++);
    return lenght;
}


/* 
 * Function that removes all elements from the list
 * Parameters: 
 *      nNode *list - list to clear
*/ 
nNode* clear(nNode* list) {
    nNode* tmp = list;
    while (list != NULL) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    return list;
}



int main() {

    nNode *head = allocateNode(1);
    append(head, 2);
    append(head, 3);
    append(head, 5);
    printf(" Appended 1,2,3,5\n   * list print: ");
    print(head);
    /* expected output: * list print: 1 2 3 5 */

    return 0;
}