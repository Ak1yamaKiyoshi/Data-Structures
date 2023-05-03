#include <stdio.h>

// swap(int arr[], int a, int b)
void swap(int arr[], int a, int b) {

    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// void bubbleSort(int arr[], int int)
void bubbleSort(int arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
}


int main() {

    int arrlen = 6;
    int array[] = {3, 6, 7, 2, 1, -2};

    bubbleSort(array, arrlen);
    printf("Array min: %d", array[0]);

    return 0;
}
