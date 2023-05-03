#include <stdio.h>
#include <malloc.h>


struct Node {
    int value; 
    struct Node *next; 
} *head = NULL; 

typedef struct Node nNode;

/*
 * @param value value to allocate node with  
 * @param next pointer to node next element 
 * @return newNode returns allocated node, with given value and given next pointer
*/
nNode* allocateNode(int value, nNode* next) {
    nNode *newNode = (nNode*)malloc(sizeof(nNode)); // Allocate Node to append
    newNode->value = value; 
    newNode->next = next; 
    return newNode;
}


/* 
 * Function appends new node at the end of list
 * @param *list - pointer to head of the list
 * @param value - value to be added
 * @return 
*/ 
nNode* append(nNode *list, int value) {
    nNode *newNode = allocateNode(value, NULL);
    nNode *tmp = list;
    if (tmp) { // if list is not empty 
        while (tmp->next) // While next node is not null
            tmp = tmp->next; // Move pointer to next node
        tmp->next = newNode; // append new node to last node of the list
    } else // if list is NULL
        list = newNode;  // list will be newNode 
    return list;
}


/*
 * @param list list to find length of 
 * @return len length of list 
*/
int length(nNode *list) {
    int len = 0;
    for (;list; list=list->next, len++);
    return len;
}


/*
 * @param list list to check if empty  
 * @return -1 if not empty, 0 if empty
*/
int empty(nNode* list) {
    if (!list) return 0;
    return -1;
}


/*
 * @param list list to clear
 * @return NULL
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


/*
 * @param list list to top value in 
 * @return value first value of list 
*/
int top(nNode *list) {
    return list->value;
}


/*
 * @param list list to delete first element from 
 * @return list with deleted first node 
*/
nNode* deleteFirst(nNode* list) {
    if (list) {
        nNode *tmp = list->next;
        free(list);
        return tmp;
    }
    return list;
}


/*
 * @param list list to pop first element from 
 * @param pointer pointere where to store value of popped node  
 * @return list with deleted first node 
*/
nNode* pop(nNode* list, int* pointer) {
    if (list) {
        nNode *tmp = list->next;
        *pointer = list->value;
        free(list);
        return tmp;
    }
    return list;
}



/*
 * @param list list to print
*/
void print(nNode *list) {
    while (list) { 
        printf("%d ", list->value); 
        list = list->next; 
    }
}


int main() {
    nNode* list = NULL; 

    list = append(list, 1);
    printf(" \nappend: 1   * list print: ");
    print(list);
    list = append(list, 1);
    printf("\nappend: 1   * list print: ");
    print(list);
    list = append(list, 1);
    printf(" \nappend: 1   * list print: ");
    print(list);
    printf(" \nlenth: %d ", length(list));
    printf(" \nempty: %d ", empty(list));
    list = append(list, 99);
    printf(" \nappend: 99   * list print: ");
    print(list);
    printf(" \ntop: %d ", top(list));
    list = deleteFirst(list);
    printf(" \ndeleteFirst  * list print: ");
    print(list);
    int *poppedValue = (int*)malloc(sizeof(int));
    list = pop(list, poppedValue);
    printf(" \n pop: %d  * list print: ", *poppedValue);
    print(list);
    free(poppedValue);
    list = clear(list);
    printf(" \nlist cleared\n ");
    print(list);
    
    return 0;
}