#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int partition(int *array, int begin, int end) {
    int pivot = array[end];
    int i = begin - 1;
    for (int j = begin; j < end; j++)  
        if (array[j] <= pivot) 
            swap(array, j, ++i);
    
    swap(array, end, ++i);
    return i;
}

void quick_sort(int *array, int begin, int end) {
    if (begin < end) {
        int i = partition(array, begin, end);
        quick_sort(array, begin, i-1);
        quick_sort(array, i+1, end);
    }
}

int main() {
    int len = 20;
    int *array = (int*)calloc(sizeof(int), len);

    // fill with random elements
    srand(time(NULL));
    for (int i = 0; i < len; i++) 
        array[i] = rand() % 30;

    // print
    for (int i = 0; i < len; i++) 
        printf("%d ", array[i]);
    printf("\n");

    quick_sort(array, 0, len-1);

    // print
    for (int i = 0; i < len; i++) 
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
