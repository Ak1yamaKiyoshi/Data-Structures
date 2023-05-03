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

int rotate90Clockwise(int array[4][4], const int SIZE) {
    for (int y = 0; y < SIZE; y++) 
        for (int x = y; x < SIZE; x++) 
            swap(array, x, y, y, x);
  transpose(array, SIZE);
}

void transform(int array[4][4], const int SIZE) { // const int SIZE
    //for (int i = 0; i < 2; i++)    
    for (int y=0, y1=SIZE-1; y < SIZE/2; y++, y1--)
        for (int x=0, x1=SIZE-1; x < SIZE; x++, x1--) {
            swap(array, y1, x1, y, x);
        }
}

void calcTable(int array[4][4], const int SIZE){
    int sumRow = 0;
    int sumColumn = 0;
    int x, y;
    for ( y = 0; y < SIZE; y++) {
        sumRow = 0;
        sumColumn = 0;
        for (x = 0; x < SIZE; x++) {
            sumRow += array[y][x];
            sumColumn += array[x][y];
        }
        printf("\n");
        printf("%d column sum: %d\n", y, sumRow);
        printf("%d row sum: %d", y,  sumColumn);
    }
}

void findMatrixMax(int matrix[4][4], const int SIZE, int * max) {
    max[0] = 0, max[1] = 0;
    for (int y = 0; y < SIZE; y++) 
        for (int x = 0; x < SIZE; x++) 
            if (matrix[y][x] > matrix[max[0]][max[1]]) {
                max[0] = y; 
                max[1] = x;
            }
}

void swapFirstLastColumn(int array[4][4], const int SIZE) {
    int temp;
    for (int y = 0; y < SIZE; y++) {
            temp = array[y][0];
            array[y][0] = array[y][SIZE-1];
            array[y][SIZE-1] = temp;
    }
}


int main()
{
    const int SIZE = 4;

    int array[SIZE][SIZE];

    fillSeq(array, SIZE);
    printf("fillSeq \n");
    printTable(array, SIZE);

    rotate90Clockwise(array, SIZE);
    printf("rotate90Clockwise \n");
    printTable(array, SIZE);
    
    MRotate90AntiClockwise(array, SIZE);
    printf("MRotate90AntiClockwise \n");
    printTable(array, SIZE);

    TRotate90AntiClockwise(array, SIZE);
    printf("TRotate90AntiClockwise \n");
    printTable(array, SIZE);

    transpose(array, SIZE);
    printf("transpose \n");
    printTable(array, SIZE);

    swapFirstLastColumn(array, SIZE);
    printf("swapFirstLastColumn \n");
    printTable(array, SIZE);

    calcTable(array, SIZE);

    int max[2];
    findMatrixMax(array, SIZE, max);
    printf("\n max elem %d, y:%d x:%d", array[max[0]][max[1]], max[0], max[1]);

    return 0;
}
