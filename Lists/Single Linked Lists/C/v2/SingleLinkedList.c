#include <stdio.h>
#include <malloc.h>

// Node structure
struct Node {
    int value; // Node value 
    struct Node *next; // Pointer to previous element
} *head = NULL; // Head of list


// struct Node append(struct Node head, int value) 
struct Node* append(struct Node *head, int value) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node)); // Allocate Node to append

    node->value = value;

    if (head) {
        while (head->next) 
            head = head->next;
        head->next = node;
        head->next->next = NULL;
    }
    return node;
}

// void print( struct Node head) 
void print(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        print(head->next);
    }
}

int main() {//  head->next->value, head->next->next->value
    head = append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 5);
    print(head);

    //print(head);



    return 0;
}