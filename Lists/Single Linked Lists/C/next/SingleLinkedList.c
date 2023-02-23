#include <stdio.h>
#include <malloc.h>


// Node structure
struct Node {
    int value; // Node value 
    struct Node *next; // Pointer to previous element
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
 *      nNode list  
 * Returns:
 *      no returning values
*/ 
void print(nNode *list) {
    while (list) { // while head is not NULL
        printf("%d ", list->value); // print current node value 
        list = list->next; // move list pointer to next node 
    }
}


int main() {

    nNode *head = allocateNode(1);
    append(head, 2);
    append(head, 3);
    append(head, 5);
    printf(" Appended 1,2,3,5\n   * list print: ");
    print(head);
    /* expected output: * list print: 1 2 3 5 */

    int array[] = {6, 7, 8, 9, 10}; // 5
    printf(" Appended from array 6, 7, 8, 9, 10\n   * list print: ");
    appendFromArray(head, &array, 5);
    print(head);
    /* expected output: * list print: 1 2 3 5 6 7 8 9 10*/


    /* 
    insert(head, 4, 3);
    printf("\n Inserted 4 at index 2\n   * list print: ");
    print(head);
    expected output: * list print: 1 2 3 4 5 */

    /* 
    insert(head, 90, 0);
    printf("\n Inserted 90 at index 0\n   * list print: ");
    print(head);
    expected output: * list print: 90 1 2 3 4 5 */

    /* 
    insert(head, 90, 6);
    printf("\n Inserted 90 at index 6\n   * list print: ");
    print(head);
    expected output: * list print: 90 1 2 3 4 5 90 */

    /* 
    removeFirst(head, 1, 0);
    printf("\n Removed 1 \n   * list print: ");
    print(head);
    expected output: * list print: 90 2 3 4 5 90 */

    /* 
    removeFirst(head, 2, 0);
    printf("\n Removed 2 \n   * list print: ");
    print(head);
    expected output: * list print: 90 3 4 5 90 */

    /* 
    removeFirst(head, 90, 0);
    printf("\n Removed 90 \n   * list print: ");
    print(head);
    expected output: * list print: 3 4 5 90 */


    return 0;
}