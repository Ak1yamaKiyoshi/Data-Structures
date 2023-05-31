#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <malloc.h>

// fills matrix with semi - random numbers
void fillC(int **array, int rows, int cols) {
    srand(time(NULL));
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            array[i][j] = rand()%(i+1)+j;
        }
    }
}

// prints matrix
void print(int **array, int rows, int cols) {
    printf("\n Matrix %dx%d :", rows, cols);
    for (int i=0; i<rows; i++) {
        printf("\n");
        for (int j=0; j<cols; j++) {
            printf(" %2d", array[i][j]);
        }
    }
}

/*
Takes two marticies and ints sizes rows, cols, and multiplies matricies
void multiply(int **array, int rows, int cols, int **array1, int rows1, int cols1)*/
int **multiply(int **array, int rows, int cols, int **array1, int rows1, int cols1) 
{
    int colsR = cols1;
    int rowsR = rows;
    int **arrayR = (int**)calloc(sizeof(int*), rowsR);
    for (int i=0; i<rowsR; i++) {
        arrayR[i] = (int*)calloc(sizeof(int*), colsR);
    }
    if (cols == rows1) {
        for (int y1 = 0; y1 < rowsR; y1++) {
            for (int x1 = 0; x1 < colsR; x1++) {
                int element = 0;
                for (int x = 0; x < cols; x++) {
                    element += array[y1][x] * array1[x][x1];
                }
                arrayR[y1][x1] = element;
            }
        }
    }
    else {
        for (int i=0; i<rowsR; i++) {
            free(arrayR[i]);
        }
        free(arrayR);
    }
    return arrayR;
}


int main() {
    // array 1 allocating
    int cols = 3, rows = 2;
    int **array = (int**)calloc(sizeof(int*), rows);
    for (int i=0; i<rows; i++) {
        array[i] = (int*)calloc(sizeof(int*), cols);
    }
    // array 2 allocating
    int cols1 = 4, rows1 = 3;
    int **array1 = (int**)calloc(sizeof(int*), rows1);
    for (int i=0; i<rows1; i++) {
        array1[i] = (int*)calloc(sizeof(int*), cols1);
    }
    // result array 
    int **arrayR;

    fillC(array, rows, cols);
    fillC(array1, rows1, cols1);
    print(array, rows, cols);
    print(array1, rows1, cols1);

    // multiply 
    arrayR = multiply(array, rows, cols, array1, rows1, cols1);
    print(arrayR, rows, cols1);

    // array 1 deallocating
    for (int i=0; i<rows; i++) 
        free(array[i]);
    free(array);
    // array 2 deallocating
    for (int i=0; i<rows1; i++) 
        free(array1[i]);
    free(array1);
    for (int i=0; i<rows; i++) 
        free(arrayR[i]);
    free(arrayR);

    return 0;
}