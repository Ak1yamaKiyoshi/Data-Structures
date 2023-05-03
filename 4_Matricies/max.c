#include <stdio.h>



void printArray(int matrix[4][4], const int SIZE) {
    for (int y = 0; y < SIZE; y++) {
        printf("\n");
        for (int x = 0; x < SIZE; x++) {
            printf("%3d ", matrix[x][y]);
        }
    }
}

/* 1. Знайти максимальний елемент матриці, а також номер стовпчика та номер рядка,
		на перетині яких він знаходиться. */
void findMatrixMax(int matrix[4][4], const int SIZE, int * max) {
    max[0] = 0, max[1] = 0;
    for (int y = 0; y < SIZE; y++) 
        for (int x = 0; x < SIZE; x++) 
            if (matrix[y][x] > matrix[max[0]][max[1]]) {
                max[0] = y; 
                max[1] = x;
            }
}



int main()
{
    const int SIZE = 4;
    int max[2];
    int matrix[][4] = { 
        { 1,  2,  3,  4}, 
        { 5, 6,  7,  8}, 
        { 9, 10, 11, 12}, 
        {13, 14, 15, 16}
    };

    printArray(matrix, SIZE);
    findMatrixMax(matrix, SIZE, max);


    printf("\nelem %d, y:%d x:%d", matrix[max[0]][max[1]], max[0], max[1]);

    return 0;
}
