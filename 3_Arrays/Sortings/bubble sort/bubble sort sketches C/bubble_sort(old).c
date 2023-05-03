#include <stdio.h>
#include <stdlib.h>


void printArr(int arr[], int len) {

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}


void swap(int arr[], int a, int b) {

    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void bubbleSort(int arr[], int len) {

    int i, j;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
}


void main(int argc, char const *argv[]) {

    int arr[] = {4, 7, 2, 5, 8};
    int len = sizeof(arr);

    bubbleSort(arr, len);
    printArr(arr, len);
}
