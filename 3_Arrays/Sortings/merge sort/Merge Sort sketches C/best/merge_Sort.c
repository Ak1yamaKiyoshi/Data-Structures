#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <malloc.h>

void randomFilling(int *array, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        array[i] = rand() % len;
}

void print(int *array, int len) {
    for (int i = 0; i < len; i++)
        printf("%2d ", array[i]);
}


void merge(int *array, int low, int mid, int high) {
    int n1 = low, n2 = mid + 1;
    int arr[high-low+1], k = 0;

    while (n2 <= high && n1 <= mid) 
        if (array[n1] < array[n2])
            arr[k++] = array[n1++];
        else
            arr[k++] = array[n2++];

    memcpy(&arr[k], &array[n2], sizeof(int)*(high-n2+1));
    memcpy(&arr[k], &array[n1], sizeof(int)*(mid-n1+1));
    memcpy(&array[low],   &arr, sizeof(int)*(high-low+1));
}


void merge_sort(int *array, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merge(array, low, mid, high);
  }
}

int main() {

    int len = 14; 
    int *array = (int*)calloc(sizeof(int), len);

    printf("\n filled ");
    randomFilling(array, len);
    print(array, len);

    merge_sort(array, 0, len);
    printf("\n sorted ");
    print(array, len);

    free(array);

    return 0;
}