#include <stdio.h>
#include <malloc.h>


// structure to perform list node
struct _Node {
    int value;           // element value
    struct _Node* prev;  // previous element pointer
} *tail=NULL; // global list variable


// calculate length of list
size_t length(struct _Node* list)
{
    size_t result = 0;
    if (list != NULL) {
        struct _Node* tmp = list;
        for (; tmp != NULL; result++, tmp=tmp->prev);
    }
    return result;
}


// adds new element to the end of the list
struct _Node* append(struct _Node* list, int value)
{
    struct _Node* newNode = (struct _Node*)malloc(sizeof(struct _Node));
    newNode->value = value;
    newNode->prev = list;
    return newNode;
}


// adds new element before the element with `before` index
struct _Node* insert(struct _Node* list, size_t before, int value)
{
    size_t len = length(list);
    if (before > -1 && before < len) {
        struct _Node* tmp = list;
        if (!len) return append(list, value);
        for (size_t i = len - 1; i > before; i--, tmp=tmp->prev);
        struct _Node* newNode = (struct _Node*)malloc(sizeof(struct _Node));
        newNode->value = value;
        newNode->prev = tmp->prev;
        tmp->prev = newNode;
    }
    return list;
}

// removes last founded element with specified value
struct _Node* removeLast(struct _Node* list, int value)
{
    struct _Node* tmp = list;
    struct _Node* tmp2 = list;
    if (list != NULL) {
        while (tmp != NULL && tmp->value != value) {
            tmp2 = tmp;
            tmp = tmp->prev;
        }
        if (tmp != NULL) {
            tmp2->prev = tmp->prev;
            free(tmp);
        }
    }
    return list;
}


// delete element by index
struct _Node* delete(struct _Node* list, int index)
{
    size_t len = length(list);
    if (len == 1 && index == 0) {
        free(list);
        return NULL;
    }
    if (index > -1 && index < len) {
        struct _Node *tmp, *tmp2;
        size_t i;
        for (tmp = list, i = len - 1; i > index + 1; i--, tmp=tmp->prev);
        tmp2 = tmp->prev;
        tmp->prev = tmp->prev->prev;
        free(tmp2);
    }
    return list;
}


// remove all elements from the list
struct _Node* clear(struct _Node* list)
{
    struct _Node* tmp = list;
    while (list != NULL) {
        tmp = list->prev;
        free(list);
        list = tmp;
    }
    return list;
}


// forward index-based element printing
void print(struct _Node* list)
{
    if (list != NULL) {
        print(list->prev);
        printf("%d ", list->value);
    }
}


// backward index-based element printing
void printReverse(struct _Node* list)
{
    if (list != NULL) {
        printf("%d ", list->value);
        printReverse(list->prev);
    }
}


int main()
{   
    tail = append(tail, 5);
    tail = append(tail, 7);
    tail = append(tail, 9);
    print(tail);
    /*
    //check if start list is empty
    char* answer = (!length(tail)) ? "Yes" : "No";
    printf("List is empty? %s\n", answer);

    // inserts new lement
    tail = insert(tail, 0, 10);
    // ________ щось не те 
    printf("Length of array is %ld\n", (long)length(tail));
    print(tail);
    printf("\n");

    // appends new element
    tail = append(tail, 20);
    printReverse(tail);
    printf("\n");

    // inserts new element again
    tail = insert(tail, length(tail)-1, 15);
    print(tail);
    printf("\n");

    // remove element by value
    tail = removeLast(tail, 15);
    print(tail);
    printf("\n");

    // removes element by index
    tail = delete(tail, 0);
    print(tail);
    printf("\n");

    // clear the list
    tail = clear(tail);
    printf("\n");
    if (!length(tail))
        printf("List is empty\n");
    else
        printf("List is not empty\n");
    */
    return 0;
}
