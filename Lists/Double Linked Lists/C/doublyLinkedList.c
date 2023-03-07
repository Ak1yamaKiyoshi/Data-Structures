#include <stdio.h>
#include <malloc.h>

struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node nNode; 


; /* Helper functions */
nNode* allocateNode(int value, nNode *prev, nNode *next);       /* */
void   unlinkMiddleNode(nNode *a, nNode *b, nNode *c);          /* */
void   link(nNode *a, nNode *b, nNode *c);                      /* */
nNode* moveLast(nNode *list);                                   /* */
nNode* moveFirst(nNode *list);                                  /* */
nNode* moveToIndex(nNode *list, int index);                     /* */
nNode* moveToValue(nNode *list, int value);                     /* */
; /* Misc */      
void   swap(nNode *list, int index1, int index2);               /* */
int    length(nNode *list);                                     /* */
int    indexOf(nNode *list, int value);                         /* */
int    max(nNode *list);                                        /* */
int    min(nNode *list);                                        /* */
int*   listToArray(nNode *list);                                /* */
int*   slice(nNode* list, int begin, int end);                  /* */
void   reverse(nNode *list);                                    /* */
;/* adding / removing an elements from list */      
int    insert(nNode *list, int value, int index);               /* */
int    insertFirst(nNode *list, int value);                     /* */ 
int    insertLast(nNode *list, int value);                      /* */
int    insertLastFromArray(nNode *list, int *array, int len);   /* */ 
int   insertFirstFromArray(nNode *list, int *array, int len);   /* */ 
int    mergeLists(nNode *list, nNode *list2);                   /* */ 
nNode*    insertList(nNode *list, nNode *list2, int index);     /* */ 
int    delete(nNode* list, int index);                          /* */       
nNode *removeFirst(nNode *list, int value);                     /* */
int    popFirst (nNode* list);
int    popLast (nNode* list);
nNode* clear(nNode* list);                                      /* */
;/* sorting list */
int   bubbleSort(nNode *list);                                  /* */
;/* display functions */
void   print(nNode *list);                                      /* */
void   printBackwards(nNode *list);                             /* */



/* 
 * Allocate node with given value
 * @param value the value with which the node should be allocated
 * @param *prev pointer to previous node of allocated node 
 * @param *next pointer to next node of allocated node 
 * @return newNode allocated node or NULL if node not allocated 
*/
nNode* allocateNode(int value, nNode *prev, nNode *next) {
    nNode *newNode = (nNode*)malloc(sizeof(nNode));\
    if (!newNode) return NULL;
    newNode->value = value;
    newNode->next = next;
    newNode->prev = prev;
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
void link(nNode *a, nNode *b, nNode *c) {
    if (a) {
        a->next = b;
    }
    b->prev = a;
    b->next = c;
    if (c != NULL)
    c->prev = b;
}


/*
 * Move list pointer to last element element of the list
 * @param *list list pointer to move 
 * @return list pointer on last element
*/
nNode* moveLast(nNode *list) {
    while (list && list->next) list = list->next;
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
 * Move list pointer to first element with given index in the list 
 * @param *list list pointer to move 
 * @return pointer on given index  or NULL if no node with such index
*/
nNode* moveToIndex(nNode *list, int index) {
    list = moveFirst(list);
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
 * Move list pointer to first element with given value in the list 
 * @param *list list pointer to move 
 * @return pointer on given value or NULL if no node with such value
*/
nNode* moveToValue(nNode *list, int value) {
    list = moveFirst(list);
    while (list->next && list->value != value) 
        list = list->next;
    
    if (list->value == value)
        return list;

    else return NULL;
}


/*
 * Swap two values in the list by indecies (indexes)
 * @param *list the list in which you want to swap the values 
 * @param index1 index of first node
 * @param index1 index of second node
 * @return void
*/
void swap(nNode *list, int index1, int index2) {
    nNode *tmp1 = moveToIndex(list, index1);
    nNode *tmp2 = moveToIndex(list, index2);
    int tmp = tmp1->value;
    tmp1->value = tmp2->value;
    tmp2->value = tmp;
}


/*
 * Length of list 
 * @param *list to find length of 
 * @return length length of list 
*/ 
int length(nNode *list) {
    list = moveFirst(list);
    int length = 0;
    for (;list; list=list->next, length++);
    return length;
}


/*
 * Index of value in list 
 * @param *list list to search value in
 * @param value value to search in list
 * @returns index of value in list or -1 if no value in list  
*/
int indexOf(nNode *list, int value) {
    list = moveFirst(list);
    int i = 0;
    while (list && list->value != value) {
        list = list->next;
        i++;
    } 
    
    if (list->value == value)
        return i;
    else return -1;
}



/* 
 * Max value of list
 * @param *list list to find max value in
 * @return maxValue - first maximum value of the list  
*/ 
int max(nNode *list) {
    list = moveFirst(list);
    int maxValue = NULL;
    if (list) 
        for ( ;list; list=list->next) 
            if (!maxValue || maxValue < list->value)
                maxValue = list->value;
    return maxValue;
}


/* 
 * Min value of list 
 * @param *list - list to find min value in
 * @param minValue - first minimum value of the list  
*/ 
int min(nNode *list) {
    list = moveFirst(list);
    int minValue = NULL;
    if (list) 
        for ( ;list; list=list->next) 
            if (!minValue || minValue > list->value)
                minValue = list->value;
    return minValue;
}


/* 
 * Copies list values into array 
 * @param *list - list to copy from 
 * @return *array - array with list values (lenght of array == lenght of list)
*/ 
int* listToArray(nNode *list) {
    list = moveFirst(list);
    int len = length(list);
    int *array = (int*)calloc(sizeof(int), len);

   

    nNode *tmp = list;
    for (int i = 0; i < len; i++, tmp = tmp->next){
        array[i] = tmp->value;
    }

    return array;
}


/* 
 * Copies list element to array
 * @param *list - list to sort
 * @return *array - array with list values from begin index to end index (lenght of array end-begin)
*/ 
int* slice(nNode* list, int begin, int end) {
    list = moveToIndex(list, begin);
    int len = length(list);
    if (begin > -1 && end < len) {
        int *array = (int*)calloc(sizeof(int), end-begin);
 
        nNode *tmp = list;
        for (int i = 0; i < end-begin; i++, tmp = tmp->next)
                array[i] = tmp->value;

        return array;
    }
}


/*
 * Reverses list
 * @param *list list to reverse
 * @return void
*/
void reverse(nNode *list) {
    list = moveFirst(list);
    for (int i=0, j=length(list)-1; i <= j; i++) 
        swap(list, i, j);
}


/*
 * Insert value at index in list
 * @param list list to insert in 
 * @param value value to insert in list
 * @param index index of list to insert value in
 * @return 0 if inserted succesfully or 1 if not   
*/
int insert(nNode *list, int value, int index) {
    list = moveToIndex(list, index);
    if (list) {
        nNode *newNode = allocateNode(value, NULL, NULL);
        if (newNode) link(list->prev, newNode, list);
        else return 1;
    } else return 1;
    return 0;
}


/*
 * Insert value at the beginning of list 
 * @param list list to insert in 
 * @param value value to insert in list
 * @return 0 if inserted succesfully or 1 if not   
*/
int insertFirst(nNode *list, int value) {
    list = moveFirst(list);
    if (list != NULL) {
        nNode *newNode = allocateNode(value, NULL, NULL);
        if (newNode) 
            link(newNode, list, list->next); 
        else return 1;
    } else list = allocateNode(value, NULL, NULL);
    return 0;
}


/*
 * Insert value at the end of list 
 * @param list list to insert in 
 * @param value value to insert in list
 * @return 0 if inserted succesfully or 1 if not   
*/
int insertLast(nNode *list, int value) {
    list = moveLast(list);
    if (list != NULL) {
        nNode *newNode = allocateNode(value, NULL, NULL);
        if (newNode) 
            link(list->prev, list, newNode); 
        else return 1;
    } else list= allocateNode(value, NULL, NULL);
    return 0;
}


/*
 * Insert int array at the end of list 
 * @param list list to insert in 
 * @param array array of values to insert in list
 * @param len array length 
 * @return 0 if inserted succesfully or 1 if not   
*/
int insertLastFromArray(nNode *list, int *array, int len) {
    for (int i = 0; i < len; i++) 
        insertLast(list, array[i]);
    return 0;
}


/*
 * Insert int array at the beggining of list 
 * @param list list to insert in 
 * @param array array of values to insert in list
 * @param len array length 
 * @return 0 if inserted succesfully or 1 if not   
*/
int insertFirstFromArray(nNode *list, int *array, int len) {
    for (int i = 0; i < len; i++) 
        if (insertFirst(list, array[i])) return 1;
    return 0;
}



/* 
 * Merge second list in first 
 * @param *list base list, second list will be appended to it 
 * @param *list2 list that will be appended to list 
 * @return 0 if merge succeded, else 1 
*/ 
int mergeLists(nNode *list, nNode *list2) {
    list = moveFirst(list);
    if (list != list2) {
        while (list2->next) {
            list2 = list2->next; 
            if (insertLast(list, list2->value)) return 1;
        }  
    } else return 1;
}


/* 
 * Inserts second list in first 
 * @param *list base list, second list will be inserted to it 
 * @param *list2 list that will be inserted to list 
 * @param  index index in first list after which will be inserted list2 
*/ 
nNode* insertList(nNode *list, nNode *list2, int index) {
    list = moveFirst(list);
    if (list != list2) {
        while (list2->next) {
            list2 = list2->next; 
            list = insert(list, list2->value, index);
        }  
    }
    return list;
}


/*
 * delete node by index from list
 * @param *list list to delete from
 * @param index index of node to delete
 * @return 0 if inserted succesfully or 1 if not   
*/
int delete(nNode* list, int index) {
    list = moveToIndex(list, index);
    if (list) {
        nNode* tmp1 = list->prev;
        nNode* tmp2 = list->next;
        unlinkMiddleNode(tmp1, list, tmp2);
        free(list);
        list = (tmp1 != NULL) ? tmp1 : tmp2;
    } else return 1;
    return 0;
}


/*
 * remove node by value from list 
 * @param *list list to remove value from
 * @param value value of node to remove
 * @return list if succeded, else NULL
*/
nNode *removeFirst(nNode *list, int value) {    
    list = moveFirst(list);
    if (list) {
        nNode *tmp = list;
        nNode *tmp2;

        while (tmp->next && tmp->value != value) {
            tmp2 = tmp;
            tmp = tmp->next;
        }

        /* if node with target value at index 0 */
        if ( list->value == tmp->value ) return list->next;

        if (tmp && tmp->value == value) {            
            tmp2->next = tmp->next;
            free(tmp); 
        }
    } else return NULL;
    return list;
}


/*
 * Pop first value of list 
 * @param list list to pop from 
*/
int popFirst (nNode* list) {
    list = moveFirst(list);
    if (list) {
        int value = list->value;
        nNode* tmp2 = list->next;
        free(list);
        tmp2->prev = NULL;
        list = tmp2;
        return value;
    } else return NULL;
}


/*
 * Pop last value of list 
 * @param list list to pop from 
*/
int popLast (nNode* list) {
    list = moveLast(list);
    if (list) {
        int value = list->value;
        nNode* tmp1 = list->prev;
        free(list);
        tmp1->next = NULL;
        list = tmp1->prev;
        return value;
    } else return NULL;

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
 * Sorts list
 * @param *list - list to sort
 * @return 0 if sort succeded, else 1
*/
int bubbleSort(nNode *list) {
    list = moveFirst(list);
    int len = length(list);
    for (int i = 0; i < len - 1; i++) 
        for (int j = 0; j < len - i - 1; j++) {
            nNode* jNode = moveToIndex(list, j);
            nNode* jPNode = moveToIndex(list, j+1);
            if (jPNode == NULL || jNode == NULL) return 1;
            if (jNode->value > jPNode->value)
                swap(list, j, j + 1);
        }
    return 0;
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


int main() {
    nNode* list = allocateNode(1, NULL, NULL); 
    printf("\n allocateNode 1 \n  * print: ");
    print(list);
    /* expected output: 1 */ 

    insertFirst(list, 2);
    printf("\n insertFirst 2 \n  * print: ");
    print(list);
    /* expected output: 2 1 */ 

    printf("\n list length: %d", length(list) );
    /* expected output: 2 */ 
    insertFirst(list, 3);
    printf("\n insertFirst 3 \n  * print: ");
    print(list);
    /* expected output: 3 2 1 */ 
    printf("\n list length: %d", length(list) );
    /* expected output: 3 */ 
    printf("\n Index of 3: %d", indexOf(list, 3));
    /* expected output: 0 */ 
    printf("\n Index of 3: %d", indexOf(list, 1));
    /* expected output: 2 */ 
    printf("\n max: %d min: %d", max(list), min(list));

    insert(list, 100, 1);
    printf("\n insert 100 at index 1 \n  * print: ");
    print(list);
    /* expected output: 3 100 2 1 */
    
    insertLast(list, 100);
    printf("\n  insert last 100 \n  * print: ");
    print(list);
    /* expected output: 3 100 2 1 100*/

    insertFirst(list, 100);
    printf("\n  insert last 100 \n  * print: ");
    print(list);
    /* expected output: 100 3 100 2 1 100*/
    
    printf("\n PopFirst %d \n  * print: ", popFirst(list));
    print(list);
    /* expected output: 3 100 2 1 100*/

    printf("\n popFirst %d \n  * print: ", popFirst(list));
    print(list);
    /* expected output: 100 2 1 100 */

    printf("\n popFirst %d \n  * print: ", popFirst(list));
    print(list);
    /* expected output: 2 1 100 */

    insertFirst(list, 3);
    printf("\n insertFirst 3 \n  * print: ");
    print(list);
    /* expected output: 3 2 1 100 */

    bubbleSort(list);
    printf("\n Sorted \n  * print: ");
    print(list);
    /* expected output: 1 2 3 100 */

    list = removeFirst(list, 3);
    printf("\n removedFirst 3 \n  * print: ");
    print(list);
    /* expected output: 1 2 100 */

    list = removeFirst(list, 100);
    printf("\n removedFirst 100 \n  * print: ");
    print(list);
    /* expected output: 1 2 */

    delete(list, 1);
    printf("\n deleted at index 1 \n  * print: ");
    print(list);
    /* expected output: 1 */

    insertFirst(list, 3);
    printf("\n insertFirst 3 \n  * print: ");
    print(list);
    /* expected output: 3 1 */

    int *array = listToArray(list);
    printf("\n list to array \n  * array print: ");
    for (int i = 0; i < length(list); i++)
        printf("%d ", array[i]);
    /* expected output: 3 1 */

    insertFirstFromArray(list, array, 2);
    printf("\n insertFirstFromArray 3 1 \n  * print: ");
    print(list);
    /* expected output: 3 1 3 1*/
    
    insertLastFromArray(list, array, 2);
    printf("\n insertLastFromArray 3 1 \n  * print: ");
    print(list);
    /* expected output: 1 3 3 1 3 1*/

    free(array);
    printf("\n sliced from list 1, 3 \n  * array print: ");
    array = slice(list, 1, 3);
    for (int i = 0; i < 2; i++)
        printf("%d ", array[i]);
    /* expected output: 3 1 */
    free(array);


    list = clear(list);
    int array1[] = {1, 2, 3, 4, 5, 6}; // 6 
    
    list = allocateNode(0, NULL, NULL);
    insertLastFromArray(list, array1, 6);
    printf("\n insertLastFromArray 1, 2, 3, 4, 5, 6 \n  * print: ");
    print(list);
    /* expected output: 1 2 3 4 5 6*/

    
    reverse(list);
    printf("\n Reverse List \n  * print: ");
    print(list);
    
    /* expected output: */ 

    /*
    printf("\n PopLast %d \n  * print: ", popLast(list));
    print(list);
    */
    /* expected output: 3 100  */
    /*
    printf("\n PopLast %d \n  * print: ", popLast(list));
    print(list);
    */
    /* expected output: 3  */

    
    


    return 0;
}

/* TODO some problems with insert first/ last when pointer is null*/
/* TODO Insert should return nNode */
void    reverse(nNode *list);                                    /* NOT WORKING PROPERLY */
int     mergeLists(nNode *list, nNode *list2);                   /* */ 
nNode*  insertList(nNode *list, nNode *list2, int index);        /* */ 
int     delete(nNode* list, int index);                          /* DELETE AT INDEX 0 */       
nNode * removeFirst(nNode *list, int value);                     /* TODO: TEST AT INDEX 0 AND LAST*/
int     popLast (nNode* list);                                   /* NOT WORKING PROPERLY */