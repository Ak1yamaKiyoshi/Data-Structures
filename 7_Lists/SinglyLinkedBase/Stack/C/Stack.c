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
 * @param value value to push in stack  
 * @param list stack to push node with given value in  
 * @return node list with pushed node 
*/
nNode* push(nNode *list, int value) {
    return allocateNode(value, list);
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
 * @param list list to top value in 
 * @return value first value of list 
*/
int top(nNode *list) {
    return list->value;
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
 * @return NULL
*/
nNode* print(nNode* list) {
    nNode* tmp = list;
    while (list != NULL) {
        tmp = list->next;
        printf("%d ", list->value);
        free(list);
        list = tmp;
    }
    return NULL;
}


int main() {
    nNode* list = NULL; 

    list = push(list, 1);
    list = push(list, 1);
    list = push(list, 1);
    list = push(list, 99);
    list = print(list);
    print(list);
    
    return 0;
}