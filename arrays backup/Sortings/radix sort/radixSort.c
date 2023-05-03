#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

void fill(int *array, int len, int limit) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) array[i] = rand() % limit;
}

void print(int *array, int len) {
    srand(time(NULL));
    for (int i = 0;i < len; i++) printf("%d ", array[i]);
}

int max(int *array, int len) {
    int max = array[0];
    for (int i = 0; i < len; i++) 
        if (array[i] > max) 
            max = array[i];
    return max;
}

void countingSortMod(int *array, int len, int slice) {
    int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int *out = (int*)calloc(len, sizeof(int));
    for (int i = 0; i < len; i++) count[array[i] / slice % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i-1];
    for (int i = len-1; i > -1; i--) out[--count[array[i] / slice % 10]] = array[i];
    for (int i = 0; i < len; i++ ) array[i] = out[i];
    free(out);
}

void radixSort(int *array, int len) {
    int slice = 1;
    for (int m = max(array, len); m/slice >= 1; slice *= 10)
        countingSortMod(array, len, slice);
} 

int main() {
    srand(time(NULL));
    int len = 20;
    int *array = (int*)calloc(sizeof(int), len);
    
    printf("\n filled : \n");
    fill(array, len, 320);
    print(array, len);
    printf("\n sorted : \n");
    radixSort(array, len);
    print(array, len);

    free(array);

    return 0; 
}

