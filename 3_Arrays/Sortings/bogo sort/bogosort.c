#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

void swap(int *array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void shuffle(int *array, int len) {
    for (int i = len-1; i > 0; i--) 
        swap(array, rand() % i, i);
}

void fill(int *array, int len, int limit) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) array[i] = rand() % limit;
}

void print(int *array, int len) {
    srand(time(NULL));
    for (int i = 0;i < len; i++) printf("%d ", array[i]);
}

int verifyArray(int *array, int len) {
    for (int i = 1; i < len; i++) 
        if (array[i-1] > array[i]) return -1;
    return 0;
}

void bogoSort(int *array, int len) {
    while (verifyArray(array, len)) 
        shuffle(array, len);
}


int main() {
    srand(time(NULL));
    int len = 2;
    int *array = (int*)calloc(sizeof(int), len);
    
    printf("\n filled : \n");
    fill(array, len, 320);
    print(array, len);

    printf("\n sorted : \n");
    bogoSort(array, len);
    print(array, len);

    free(array);

    return 0; 
}

