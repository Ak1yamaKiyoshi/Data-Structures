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
//4. Поміняти місцями елементи першого та останнього стовпчиків матриці.

void transform(int array[5][5], const int SIZE) {
    int temp;
    for (int y = 0; y < SIZE; y++) {
            temp = array[y][0];
            array[y][0] = array[y][SIZE-1];
            array[y][SIZE-1] = temp;
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
