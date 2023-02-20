#include <stdio.h>
#include <malloc.h>


// Node structure
struct Node {
    int value; // Node value 
    struct Node *next; // Pointer to previous element
} *head = NULL; // Head of list


/* struct Node* allocateNode(int value)
 * Allocate new node with value */ 
struct Node* allocateNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate Node to append
    newNode->value = value; 
    newNode->next = NULL; // because we assert that last node in list will have NULL as next pointer, so we know where list ends, otherwise, there is now way to know that
    return newNode;
}


/* struct Node append(struct Node head, int value) 
 * Append node with value at the end of list  */ 
struct Node* append(struct Node *list, int value) {
    struct Node *newNode = allocateNode(value);

    if (list) { // if list is not empty 
        while (list->next) // While next node is not null
            list = list->next; // Move pointer to next node
        list->next = newNode; // append new node to last node of the list
    }
    return newNode;
}


/* void print(struct Node list) 
 * print list with left - right indexing */ 
void print(struct Node *list) {
    while (list) { // while head is not NULL
        printf("%d ", list->value); // print current node value 
        list = list->next; // move list pointer to next node 
    }
}


/* void print(struct Node list) */ 
int lenght(struct Node *list) {
    int counter;
    for (counter = 1; list; counter++, list=list->next);
    return counter;
}


/* void insertAt0(struct Node *list, int value, int index) {
 * inserts value at index 0 by changing first node value and shifting all next nodes values to the right */
void insertAtZeroIndex(struct Node *list, int value, int index) {
    struct Node *node = list; // pointer to first node, so we can insert value at index 0 
    append(list, 0); // append because we inserting and we need 1 more node in list, value doesn't matter

    struct Node *tmp = list; // For swapping values with prev and current nodes
    for (;list;list = list->next) { // Iterate trough whole list
        // swap
        int temp = list->value; 
        list->value = tmp->value;
        tmp->value = temp;
    }
    node->value = value; // change value of very first node to given value 
}


/* void insert(struct Node *list, int value, int index)
 * inserts value in the list at index */ 
void insert(struct Node *list, int value, int index) {
    if (list && index > 0 && index <= lenght(list)) {
        int i;
        for (i = 0; i < index-1; i++, list = list->next); // go to index-1 node in the list
        struct Node *newNode = allocateNode(value); // Node to insert 
        struct Node *tmpNode = list->next; // next node from current that will be after inserted node 
        list->next = newNode; // link new node to list 
        newNode->next = tmpNode; // link right part of list to node
    }
    else if (list && index == 0) insertAtZeroIndex(list, value, index); // if index 0 call insert at zero function which uses different algorythm to insert so it's possible
}


// TODO: 
/* void removeAtIndexZero(struct Node *list)
*/
void removeAtIndexZero(struct Node *list) {
    struct Node *node = list; // pointer to first node, so we can insert value at index 0 
    append(list, 0); // append because we inserting and we need 1 more node in list, value doesn't matter

    struct Node *tmp = list; // For swapping values with prev and current nodes
    
    for (int value = list->value; list->next;list = list->next, tmp = list, value = tmp->value) { // Iterate trough whole list
        list->value = value;

    }
    free(list);
    tmp->next = NULL;
}


// TODO:
/* void removeFirst(struct Node *list, int value, int offset)
 * removes first found node with given value from the list, if (offset), will be looking for given value after offset index nodes */
void removeFirst(struct Node *list, int value, int offset) {
    struct Node *tmp = list; // tmp value for previous node, so we can link previous to next, where current node will be node with given value 
    if (offset <= lenght(list)) {
        int i = 0; // current index of list 

        while (i++ <= offset) { // iterate trought list to offset element
            tmp = list; // update previous node pointer 
            list = list->next; // move current pointer 
        }

        for (;list;tmp = list, list = list->next, i++)  // iterate trought list 
            if (list->value == value) break; // while current node->value != value 

        if (i == 0) removeAtIndexZero(list); // if current index zero, need to remove zero index element, so we use removeArIndexZero because it has different delete algorythm
        else tmp->next = list->next; // unlink current (list) element 
    }
}



// TODO:
void sort() {
    ;
}


// TODO:
void delete() {
    ;
}


// TODO;
void clear() {
    ;
}


int main() {

    head = append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 5);
    printf(" Appended 1,2,3,5\n   * list print: ");
    print(head);
    /* expected output: * list print: 1 2 3 5 */

    insert(head, 4, 3);
    printf("\n Inserted 4 at index 2\n   * list print: ");
    print(head);
    /* expected output: * list print: 1 2 3 4 5 */

    insert(head, 90, 0);
    printf("\n Inserted 90 at index 0\n   * list print: ");
    print(head);
    /* expected output: * list print: 90 1 2 3 4 5 */

    insert(head, 90, 6);
    printf("\n Inserted 90 at index 6\n   * list print: ");
    print(head);
    /* expected output: * list print: 90 1 2 3 4 5 90 */

    removeFirst(head, 1, 0);
    printf("\n Removed 1 \n   * list print: ");
    print(head);
    /* expected output: * list print: 90 2 3 4 5 90 */

    removeFirst(head, 2, 0);
    printf("\n Removed 2 \n   * list print: ");
    print(head);
    /* expected output: * list print: 90 3 4 5 90 */

    removeFirst(head, 90, 0);
    printf("\n Removed 90 \n   * list print: ");
    print(head);
    /* expected output: * list print: 3 4 5 90 */


    return 0;
}