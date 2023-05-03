#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int partition(int *array, int start, int end) {
    int pivot = array[end];
    int low = start;
    int high = end-1;
    while (1) {

        while (low <= high && array[high] >= pivot) high--;
        while (low <= high && array[low] <= pivot) low++;
        if (low <= high) {
            int temp = array[low];
            array[low] = array[high];
            array[high] = temp;
        }
        else break;
    }

    int temp = array[end];
    array[end] = array[low];
    array[low] = temp;
    return low;
}

void quick_sort(int *array, int start, int end) {
    if (start >= end) return;
    int p = partition(array, start, end);
    quick_sort(array, start, p-1);
    quick_sort(array, p+1, end);
}

int main() {
    int len = 5;
    int *array = (int*)calloc(sizeof(int), len);
    srand(time(NULL));

    for (int i = 0; i < len; i++) 
        array[i] = rand() % 20;
    
    printf("\n unsorted: ");
    for (int i = 0; i < len; i++)
        printf("%2d ", array[i]);
    
    quick_sort(array, 0, len-1);

    printf("\n   sorted: ");
    for (int i = 0; i < len; i++)
        printf("%2d ", array[i]);

    return 0;
}
