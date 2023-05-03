#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <memory.h>

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
    int *left[mid-low];
    memcpy(&left, &array[low], sizeof(int)*(mid-low));
    int *right[high-mid];
    memcpy(&right, &array[mid], sizeof(int) * (high-mid));
    int k = low, i = 0, j = 0;
    while (low + i < mid && mid + j < high) {
        if (left[i] <= right[j]) array[k++] = left[i++];
        else array[k++] = right[j++];
    }
    if (low + i < mid) memcpy(&array[k], &left[i], sizeof(int)*(high-k));
    else memcpy(&array[k], &right[j], sizeof(int)*(high-k));

    free(left); free(right);
}

void mergeSort(int *array, int low, int high) {
    if (high-low > 1) {
        int mid = (low+high)/2;
        mergeSort(array, low, mid);
        mergeSort(array, mid, high);
        merge(array, low, mid, high);
    }
}
 

int main() {

    int len = 14; 
    int *array = (int*)calloc(sizeof(int), len);

    printf("\n filled ");
    randomFilling(array, len);
    print(array, len);

    mergeSort(array, 0, len);
    printf("\n sorted ");
    print(array, len);

    free(array);

    return 0;
}
