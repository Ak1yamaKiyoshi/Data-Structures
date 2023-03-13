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
    if (list == NULL) return NULL; 

    int k = 0;
    while (list && list->next && k < index)  {
        list = list->next;
        k++;
    }

    if (k == index) return list;
    else return NULL;
}


/*
 * Move list pointer to first element with given value in the list 
 * @param *list list pointer to move 
 * @return pointer on given value or NULL if no node with such value
*/
nNode* moveToValue(nNode *list, int value) {
    list = moveFirst(list);
    if (!list) return; 
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
    if (!list) return 0; 
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
    if (!list) return; 
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
 * @return maxNode - first maximum value of the list  
*/ 
nNode* max(nNode *list) {
    list = moveFirst(list);
    if (!list) return; 

    nNode* maxNode = NULL;
    for (;list; list=list->next) 
        if (!maxNode || maxNode->value < list->value)
            maxNode = list;
    return maxNode;
}



/* 
 * Min value of list 
 * @param *list - list to find min value in
 * @param minValue - first minimum value of the list  
*/ 
nNode* min(nNode *list) {
    list = moveFirst(list);
    if (!list) return; 

    nNode* minNode = NULL;
    for (;list; list=list->next) 
        if (!minNode || minNode->value > list->value)
            minNode = list;
    return minNode;
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
    for (int i = 0; i < len; i++, tmp = tmp->next)
        array[i] = tmp->value;

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
    for (int i=0, j=length(list)-1; i <= j; i++, j--) 
        swap(list, i, j);
}


/*
 * Insert value at the beginning of list 
 * @param list list to insert in 
 * @param value value to insert in list
 * @return   
*/
nNode* insertFirst(nNode *list, int value) {
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
 * Insert value at index in list
 * @param list list to insert in 
 * @param value value to insert in list
 * @param index index of list to insert value in 
*/
nNode* insert(nNode *list, int value, int index) {
    if (!list) return allocateNode(value);

    int len = length(list);
    if (index == 0) list = insertFirst(list, value);
    else if (index == len-1) list = append(list, value);
    else {
        list = moveToIndex(list, index);
        if (!list) return NULL;
        link3(list->prev, allocateNode(value), list);
    }

    return list;
}


/*
 * Insert int array at the end of list 
 * @param list list to insert in 
 * @param array array of values to insert in list
 * @param len array length 
 * @return  
*/
int insertLastFromArray(nNode *list, int *array, int len) {
    for (int i = 0; i < len; i++) 
        append(list, array[i]);
    return 0;
}


/*
 * Insert int array at the beggining of list 
 * @param list list to insert in 
 * @param array array of values to insert in list
 * @param len array length 
 * @return 
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
 * @return 
*/ 
int mergeLists(nNode *list, nNode *list2) {
    list = moveFirst(list);
    list2 = moveFirst(list2);
    if (list != list2 && list != NULL && list2 != NULL) {
        while (list2->next) {
            list2 = list2->next; 
            if (append(list, list2->value)) return 1;
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
    list = moveToIndex(list, index);
    list2 = moveFirst(list2);
    if (list != list2) {
        while (list != NULL && list2 != NULL && list2->next) {
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
 * @return 
*/
nNode* delete(nNode* list, int index) {
    list = moveToIndex(list, index);
    if (list) {
        nNode* tmp1 = list->prev;
        nNode* tmp2 = list->next;
        unlinkMiddleNode(tmp1, list, tmp2);
        free(list);
        if (tmp1) list=tmp1;
        if (tmp2) list=tmp2;
    } else return NULL;
    return list;
}


/*
 * remove node by value from list 
 * @param *list list to remove value from
 * @param value value of node to remove
 * @return 
*/
nNode *removeFirst(nNode *list, int value) {    
    if (list) {
        nNode *tmp = list;
        nNode *tmp2;
        while (tmp->next && tmp->value != value) {
            tmp2 = tmp;
            tmp = tmp->next;
        }
        // if node with target value at index 0 
        if ( list->value == tmp->value ) return list->next;

        if (tmp && tmp->value == value) {
            tmp2->next = tmp->next;
            free(tmp); 
        }
    }
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


void test() {


    /* Insert if list == NULL*/
    nNode*list = NULL;
    list = insertFirst(list, 0);
    print(list); /* expected output 0 */ 
    list = clear(list);
    print(list); /* expected output */ 
    list = append(list, 0);
    print(list); /* expected output 0 */ 
    list = clear(list);
    list = insert(list, 0, 0);
    print(list); /* expected output 0 */ 
    list = clear(list);
            /* expected output 0 0 0*/

    printf("|");

    /* append, insertFirst, insert tests */
    list = append(list, 0);
    list = append(list, 1);
    list = append(list, 2); 
    list = insertFirst(list, -2);
    list = insertFirst(list, -3);
    list = insert(list, -1, 2);
    list = insert(list, 3, 5);
    list = insert(list, -4, 0);
    print(list);
    /* expected output -4 -3 -2 0 1 2 3 */
    printf(" | len: %d |", length(list));
    //reverse(list);

    if (
        (moveToIndex(list, 0)->value == -4) &&
        (moveToIndex(list, 1)->value == -3) &&
        (moveToIndex(list, 2)->value == -2) &&
        (moveToIndex(list, 3)->value == -1) &&
        (moveToIndex(list, 4)->value == 0) &&
        (moveToIndex(list, 5)->value == 1) &&
        (moveToIndex(list, 6)->value == 2) &&
        (moveToIndex(list, 7)->value == 3)
    ) printf("moveToIndex working fine|");

    reverse(list);
    print(list); /* expected output 3 2 1 0 -1 -2 -3 -4*/ 
    printf("|");
    bubbleSort(list);
    print(list); /* expected output -4 -3 -2 -1 0 1 2 3 */








}



int main() {

    test();

    return 0;
}
