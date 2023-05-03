#include <stdio.h>

const int SIZE = 5;


void fillTable(int array[5][5], const int SIZE){
    int i = 1; 
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            array[y][x] = i;
            i++; 
        }
    }
}


void printTable(int array[5][5], const int SIZE){
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            printf("%3d", array[y][x]);
        }
        printf("\n");
    }
}


//2. Порахувати суму елементів кожного рядка матриці.
//3. Порахувати суму елементів кожного стовпчика матриці.
void calcTable(int array[5][5], const int SIZE){
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


int main()
{
    int array[SIZE][SIZE];

    fillTable(array, SIZE);
    printTable(array, SIZE);
    calcTable(array, SIZE);
    return 0;
}

