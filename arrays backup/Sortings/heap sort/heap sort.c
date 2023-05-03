#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void swap(int *array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void heapify(int *array, int len, int root) {
    int max = root, left = (2*root)+1, right = (2*root)+2;
    // root must be largest element

    // if left child or right child is larger than root 
    // we change max index
    if (left < len && array[root] < array[left]) 
        max = left;
    if (right < len && array[max] < array[right]) 
        max = right;
    
    // and if max index != root, we swap max index with root
    // so it will be max in subtree
    if (max != root) {
        swap(array, root, max);
        heapify(array, len, max);
    }
}

void heapSort(int *array, int len) {
    // heapify initial array
    for (int i = len/2; i >=0; i--) 
        heapify(array, len, i);

    // heapify lesser and lesser slice of array, 
    // gradually swapping max element (after heapify) to end of array
    for (int i = len-1; i >=0 ; i--) {
        swap(array, 0, i);
        heapify(array, i, 0);
    }
    
}

void fill(int *array, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) array[i] = rand() % 10;
}

void print(int *array, int len) {
    srand(time(NULL));
    for (int i = 0;i < len; i++) printf("%d ", array[i]);
}

int main() {
    int len = 6;
    int *array = (int*)calloc(sizeof(int), len);

    printf("\n filled : \n");
    fill(array, len);
    print(array, len);
    printf("\n sorted : \n");
    heapSort(array, len);
    print(array, len);

    free(array);
    
}
