#include <stdio.h>

void enterArray(int array[], int ARRSIZE) {
    for (int i = 0; i < ARRSIZE; i++) {
        scanf("%d", &array[i]);
    }
}

void printArray(int array[], int ARRSIZE) {
    for (int i = 0; i < ARRSIZE; i++) {
        printf("%d ", array[i]);
    }
}

int main()
{   
    // Створити функцію для введення елементів масиву
    const int ARRSIZE = 4;
    int array[ARRSIZE];
    printf(" enter array:\n");
    enterArray(array, ARRSIZE);
    printf("array:\n");
    printArray(array, ARRSIZE);
    return 0;
}
