#include <stdio.h>



void fillSeq(int array[4][4], const int SIZE){
    int i = 1; 
    for (int y = 0; y < SIZE; y++) 
        for (int x = 0; x < SIZE; x++) {
            array[y][x] = i;
            i++; 
        }
}


void printTable(int array[4][4], const int SIZE){
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) 
            printf("%4d", array[y][x]);
        printf("\n");
    }
}

void swap(int arr[4][4], int aY, int aX, int bY, int bX) {
    int temp = arr[aY][aX];
    arr[aY][aX] = arr[bY][bX];
    arr[bY][bX] = temp;
}

// reverses each row of array
void transpose(int array[4][4], const int SIZE) {
    int temp;
    for (int x = 0; x < SIZE/2; x++)
        for (int y = 0; y < SIZE; y++) {
            temp = array[y][x];
            array[y][x] = array[y][SIZE-x-1];
            array[y][SIZE-x-1] = temp;   
        }
}

void TRotate90AntiClockwise(int array[4][4], const int SIZE) {
  transpose(array, SIZE);
  for (int y = 0; y < SIZE; y++) 
    for (int x = y; x < SIZE; x++) 
      swap(array, x, y, y, x);
}

void MRotate90AntiClockwise(int array[4][4], const int SIZE) {
    int arrayB[SIZE][SIZE];
    int i;
    for (int y = SIZE-1, i = 0; y >= 0;i++, y--) 
        for (int x = SIZE-1; x >= 0; x--) 
            arrayB[y][x] = array[x][i];
    for (int y = SIZE-1; y >= 0; y--) 
        for (int x = SIZE-1; x >= 0; x--) 
            array[y][x] = arrayB[y][x];
}

int main()
{
    const int SIZE = 4;

    int array[SIZE][SIZE];

    fillSeq(array, SIZE);
    printf("fillSeq \n");
    printTable(array, SIZE);

    MRotate90AntiClockwise(array, SIZE);
    printf("MRotate90AntiClockwise \n");
    printTable(array, SIZE);

    TRotate90AntiClockwise(array, SIZE);
    printf("TRotate90AntiClockwise \n");
    printTable(array, SIZE);



    return 0;
}
