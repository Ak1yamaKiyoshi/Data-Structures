 #include <stdio.h>
#include <malloc.h>

struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node nNode; 


/* 
 * Allocate node with given value
 * @param value the value with which the node should be allocated
 * @param *prev pointer to previous node of allocated node 
 * @param *next pointer to next node of allocated node 
 * @return newNode allocated node 
*/
nNode* allocateNode(int value) {
    nNode *newNode = (nNode*)malloc(sizeof(nNode));\
    if (!newNode) return NULL;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/* 
 * Unlink b node from c and a nodes
 * @param *a b->prev 
 * @param *b node that will be unlinked from a node and b node  
 * @param *c b->next 
 * @return void
*/
void unlinkMiddleNode(nNode *a, nNode *b, nNode *c) {
    if (a !=NULL)
        a->next = c;
    if (c != NULL) 
        c->prev = a;
    b->next = NULL;
    b->prev = NULL;
}


/* 
 * Link three nodes
 * a <-> b <-> c
 * @param *a a node that will be linked with b node 
 * @param *b b node that will be linked with c node and a node 
 * @param *c c node that will be linked with b node 
 * @return void
*/
void link3(nNode *a, nNode *b, nNode *c) {
    if (a != NULL) 
        a->next = b;
    if (b != NULL) {
        b->prev = a;
        b->next = c;
    }
    if (c != NULL) 
        c->prev = b;
}


void link2(nNode *a, nNode *b) {
    if (a != NULL)
        a->next = b;
    if (b != NULL)
        b->prev = a;
}



/*
 * Move list pointer to last element element of the list
 * @param *list list pointer to move 
 * @return list pointer on last element
*/
nNode* moveLast(nNode *list) {
    while (list != NULL && list->next) list = list->next;
    return list;
}


/*
 * Move list pointer to first element of the list 
 * @param *list list pointer to move 
 * @return pointer on first element
*/
nNode* moveFirst(nNode *list) {
    while (list != NULL && list->prev) list = list->prev;
    return list;
}


/*
 * Length of list 
 * @param *list to find length of 
 * @return length length of list 
*/ 
int length(nNode *list) {
    list = moveFirst(list);
    if (!list) return 0; 
    int length = 0;
    for (;list; list=list->next, length++);
    return length;
}


/*
 * Insert value at the beginning of list 
 * @param list list to insert in 
 * @param value value to insert in list
 * @return   
*/
nNode* push(nNode *list, int value) {
    if (!list) return allocateNode(value);
    list = moveFirst(list);

    link3(allocateNode(value), list, list->next); 
    return list;
}


/*
 * Insert value at the end of list 
 * @param list list to insert in 
 * @param value value to insert in list
 * @return  
*/
nNode* append(nNode *list, int value) {
    list = moveLast(list);
    if (list == NULL) return allocateNode(value);

    link3(list->prev, list, allocateNode(value)); 
    return list;
}


/*
 * Removes all elements from the list 
 * @param *list - list to clear
*/
nNode* clear(nNode* list) {
    if (list != NULL) {
    list = moveFirst(list);
    nNode* tmp = list;
    while (list != NULL) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    }
    return NULL;
}


/*
 * Prints list
 * @param *list list to print 
*/
void print(nNode *list) {
    list = moveFirst(list);
    while (list) { // while list is not NULL
        printf("%d ", list->value); // print current node value 
        list = list->next; // move list pointer to prev node 

    }
}


/*
 * Prints list backwards
 * @param *list list to print 
*/
void printBackwards(nNode *list) {
    list = moveLast(list);
    while (list) { // while list is not NULL
        printf("%d ", list->value); // print current node value 
        list = list->prev; // move list pointer to prev node 

    }
}


/*
 * use only if len > 1
 * Pop first value of list 
 * @param list list to pop first element from 
 * @param pointer pointere where to store value of popped node  
 * @return list with deleted first node 
*/
nNode* popFirst(nNode* list, int* pointer) {
    if (list) {
        nNode *tmp = moveFirst(list);
        list = tmp->next;
        if (list) *pointer = tmp->value;
        if (list != NULL) list->prev = NULL;
        free(tmp);
    }
    return list;
}



/*
 * use only if len > 1
 * Pop last element from list 
 * @param list list to pop last element from 
 * @param pointer pointere where to store value of popped node  
 * @return list with deleted last node 
*/
nNode* popLast(nNode* list, int* pointer) {
    if (list) {
        nNode *tmp = moveLast(list);
        list = tmp->prev;
        if (list) *pointer = tmp->value;
        if (list != NULL) list->next = NULL;
        free(tmp);
    }
    return list;
}


void test() {


    /* Insert if list == NULL*/
    nNode*list = NULL;
    list = push(list, 0);
    print(list); /* expected output 0 */ 
    list = clear(list);
    print(list); /* expected output */ 
    list = append(list, 0);
    print(list); /* expected output 0 */ 
    list = clear(list);
    list = push(list, 0);
    print(list); /* expected output 0 */ 
    list = clear(list);
            /* expected output 0 0 0*/

    printf("|");

    /* append, push, insert tests */
    list = append(list, 0);
    list = append(list, 1);
    list = append(list, 2); 
    list = push(list, -2);
    list = push(list, -3);
    print(list);
    printf(" | len: %d |", length(list));


    int *num1 = (int*)malloc(sizeof(int));
    int *num2 = (int*)malloc(sizeof(int));

    printf("____|");
    print(list); /* expected output -2 1*/
    printf("|____");
    
    list = popFirst(list, num1);

    printf("____|");
    print(list); /* expected output -2 1*/
    printf("|____");

    list = popLast(list, num2);

    printf("____|");
    print(list); /* expected output -2 1*/
    printf("|____");

    printf(" PopFirst=%d PopLast=%d ", *num1,*num2 );
    list = clear(list);
    free(num1);
    free(num2);

}



int main() {

    test();

    return 0;
}
