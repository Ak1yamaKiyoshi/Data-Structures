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
    newNode->value = value; 
    newNode->next = NULL; // because we assert that last node in list will have NULL as next pointer, so we know where list ends, otherwise, there is now way to know that
    return newNode;
}


/* 
 * int append(nNode *list, int value) 
 * Function appends new node at the end of list
 * Parameters: 
 *      nNode *list - pointer to head of the list
 *      int value - value to be added
 * Returns: 
 *      int result of execution (1 - on success, 0 - on fail)
 *      if function successeds, list pointer would be changed
*/ 
int append(nNode *list, int value) {
    struct nNode *newNode = allocateNode(value);
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
 * int appendFromArray(nNode *list, int *array, int len)
 * Function appends list from array, (appends each value in array)
 * Parameters: 
 *      nNode *list - pointer to head of the list
 *      int value - value to be added
 *      int *array - array to append from
 *      int len - lenght of array 
 * Returns: 
 *      int result of execution (1 - on success, 0 - on fail)
 *      if function successeds, list pointer would be changed
*/ 
int appendFromArray(nNode *list, int *array, int len) {
    for (int i = 0; i < len; i++) {
        if (!append(list, array[i])) return 0;
    }
    return 1;
}


/* 
 * void print(nNode *list) 
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
 * int lenght(nNode *list)
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


/* NOT TESTED YET ! NOT TESTED YET ! NOT TESTED YET 
 * nNode *findByValue(nNode *list, int value) 
 * Function searches node with given value in list
 * Parameters: 
 *      nNode *list - list to find lenght of 
 *      int value - value of node to search in list
 * Returns: 
 *      nNode list - node with given value OR NULL if no node with such value
*/
nNode *findByValue(nNode *list, int value) {
    while (list->next && list->value != value) 
        list = list->next;
    
    if (list->value == value)
        return list;

    else return NULL;
}


/*
 * nNode *findByIndex(nNode *list, int index)
 * Function searches node at given index in list
 * Parameters: 
 *      nNode *list - list to find lenght of 
 *      int index - index of list to search node at 
 * Returns: 
 *      nNode list - node at given index OR NULL if no such index
*/
nNode *findByIndex(nNode *list, int index) {
    int k = 0;
    while (list->next && k < index) {
        list = list->next;
        k++;
    }
    if (k == index)
        return list;
    else return NULL;
}


/*
 * nNode *insert(nNode *list, int value, int index)
 * ! If inserting at index 0, assign returned value to list 
 * Function inserts given value at given index in list 
 * Parameters: 
 *      nNode *list - list to insert in
 *      int value - value to insert in list
 *      int index - index in list where to insert value 
 * Returns:
 *      nNode newNode 
*/
nNode *insert(nNode *list, int value, int index) {
    nNode *newNode = allocateNode(value);
    if (index == 0 || !list)
        newNode->next = list;

    else {
        nNode *tmp = findByIndex(list, index-1);
        if (tmp) list = tmp;

        newNode->next = list->next;
        list->next = newNode;
    }
    return newNode;
}


/*
 * int indexOf(nNode *list, int value)
 * Function 
 * Parameters: 
 *      nNode *list - list to insert in
 *      int value - value to search in list
 * Returns:
 *      int i - index of node with given value in list
*/
int indexOf(nNode *list, int value) {
    int i = 0;
    while (list && list->value != value) {
        list = list->next;
        i++;
    } 
    
    if (list->value == value)
        return i;
    else return -1;
}


// delete element by index
nNode* delete(nNode* list, int index) {
    int len = length(list);
    if (len == 1 && index == 0) {
        free(list);
        return NULL;
    }

    if (index > -1 && index < len) {
        nNode *tmp, *tmp2;
        int i;
        for (tmp = list, i = len - 1; i > index + 1; i--, tmp=tmp->next);
        tmp2 = tmp->next;
        tmp2->next = tmp->next->next;
        free(tmp2);
    }
    return list;
}


nNode *removeFirst(nNode *list, int value) {    
    nNode* tmp = list;
    nNode* tmp2 = NULL;
    if (list) {
        while (tmp->next && tmp->value != value) 
            tmp2 = tmp;
            tmp = tmp->next;
        
        if (tmp2 && tmp) {
            
            tmp2->next = tmp->next;
            free(tmp);
            return list;
        }
        else {
            return list->next;
        }
    }
    return list;
}




/*
sort
listToArray
merge list;
insert list;
*/

int main() {

    nNode *head = allocateNode(1);
    append(head, 2);
    append(head, 3);
    append(head, 5);
    printf(" Appended 1,2,3,5\n   * list print: ");
    print(head);
    /* expected output: * list print: 1 2 3 5 */

    int array[] = {6, 7, 8, 9, 10}; // 5
    printf(" \n Appended from array 6, 7, 8, 9, 10\n   * list print: ");
    appendFromArray(head, &array, 5);
    print(head);
    /* expected output: * list print: 1 2 3 5 6 7 8 9 10*/

    printf("\n Lenght: %d", length(head));
    /*expected output: 9 */

    printf(" \n Inserted 100 at 0, 1000 at lenght, 500 at 5\n   * list print: ");
    head = insert(head, 100, 0);
    insert(head, 500, 5);
    insert(head, 1000, length(head));
    print(head);
    /* expected output: 100 1 2 3 5 6 500 7 8 9 10 1000 */

    printf("index of 100, 500, 1000 \n   *  %d %d %d ", indexOf(head, 100), indexOf(head, 500), indexOf(head, 1000));
    /* expected output: 0 5 11  */
    printf(" \n index of 8, 9, 10 \n   *  %d %d %d ", indexOf(head, 8), indexOf(head, 9), indexOf(head, 10));
    /* expected output: 8 9 10 */

    head = removeFirst(head, 100);
    head = removeFirst(head, 500);
    head = removeFirst(head, 1000);
    printf(" \n Removed 100, 500, 1000\n   * list print: ");
    print(head);
    /* expected output: 1 2 3 5 6 7 8 9 10 */


    return 0;
}