#include <stdio.h>

const int SIZE = 4;

// void fillTable(int array[10][10], const int SIZE)
void fillTable(int array[4][4], const int SIZE){
    int i = 1; 
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            array[y][x] = i;
            i++; 
        }
    }
}

// void printTable(int array[10][10], const int SIZE)
void printTable(int array[4][4], const int SIZE){
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            printf("%4d", array[y][x]);
        }
        printf("\n");
    }
}

// swap(int arr[10][10], int aY, int aX, int bY, int bX)
void swap(int arr[4][4], int aY, int aX, int bY, int bX) {
    int temp = arr[aY][aX];
    arr[aY][aX] = arr[bY][bX];
    arr[bY][bX] = temp;
}


// 6. Повернути матрицю на 180 градусів за годинниковою стрілкою.
void transform(int array[4][4], const int SIZE) { // const int SIZE
    //for (int i = 0; i < 2; i++)    
    for (int y=0, y1=SIZE-1; y < SIZE/2; y++, y1--)
        for (int x=0, x1=SIZE-1; x < SIZE; x++, x1--) {
            swap(array, y1, x1, y, x);
        }
}


int main()
{
    int array[SIZE][SIZE];

    fillTable(array, SIZE);
    printTable(array, SIZE);

    printf("\n");
    transform(array, SIZE);
    printTable(array, SIZE);

    return 0;
}