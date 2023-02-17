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

// TODO: 
void insertAt0(struct Node *list, int value, int index) {
    struct Node *tmpNode = list;
    
    int tmpValue = list->value;
    while (list->next) {

        
        list->value = tmpValue;
        list = list->next;
        tmpValue = list->value;
        
    }

    list->next = allocateNode(list->value);
    tmpNode->value = value;

}


/* void insert(struct Node *list, int value, int index)
 * inserts value in the list at index
*/ 
void insert(struct Node *list, int value, int index) {
    if (list && index > 0 && index <= lenght(list)) {
        int i;
        for (i = 0; i < index-1; i++, list = list->next); // go to index-1 node in the list

        struct Node *newNode = allocateNode(value);

        struct Node *tmpNode = list->next;    
        list->next = newNode;
        newNode->next = tmpNode;
    }
    else if (list && index == 0) insertAt0(list, value, index);

}


int main() {
    // Tests 
    head = append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 5);
    printf(" Appended 1,2,3,5\n   * list print: ");
    print(head);
    insert(head, 4, 3);
    printf("\n Inserted 4 at index 2\n   * list print: ");
    print(head);
    insert(head, 90, 0);
    printf("\n Inserted 90 at index 0\n   * list print: ");
    print(head);



    //printf("%d ", head->next->value);



    return 0;
}