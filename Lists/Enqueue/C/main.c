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
 * @return value value of last node 
*/
int top(nNode *list) {
    nNode *tmp = list;
    while (tmp->next) 
        tmp = tmp->next; 
    return tmp->value;
}


/*
 * @param list list to delete last element from 
 * @return list with deleted last node 
*/
nNode* deleteLast(nNode* list) {
    if (list) {
        nNode *tmp = list;
        nNode *tmp1 = NULL;
        while (tmp->next) {
            tmp1 = tmp;
            tmp = tmp->next; 
        }
        tmp1->next = NULL;
        free(tmp);
    }
    return list;
}


/*
 * @param list list to pop last element from 
 * @param pointer pointere where to store value of popped node  
 * @return list with deleted last node 
*/
nNode* pop(nNode* list, int* pointer) {
    if (list) {
        nNode *tmp = list;
        nNode *tmp1 = NULL;
        while (tmp->next) {
            tmp1 = tmp;
            tmp = tmp->next; 
        }
        *pointer = tmp->value;
        tmp1->next = NULL;
        free(tmp);
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

    list = push(list, 1);
    printf(" \npush: 1   * list print: ");
    print(list);
    list = push(list, 1);
    printf("\npush: 1   * list print: ");
    print(list);
    list = push(list, 1);
    printf(" \npush: 1   * list print: ");
    print(list);
    printf(" \nlenth: %d ", length(list));
    printf(" \nempty: %d ", empty(list));
    list = push(list, 99);
    printf(" \npush: 99   * list print: ");
    print(list);
    printf(" \ntop: %d ", top(list));
    list = deleteLast(list);
    printf(" \ndeleteLast  * list print: ");
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