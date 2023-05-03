#include <stdio.h>
#include <malloc.h>


// Можна передавати вказівник на вказівник 
void fill(int **array, int rows, int cols){
    int i = 1; 
    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {
            array[y][x] = i;
            i++; 
        }
    }
}

// Можна передавати вказівник на масив 
void print(int *array[], int rows, int cols){
    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {
            printf("%4d", array[y][x]);
        }
        printf("\n");
    }
}


int main()
{
    int cols=5;
    int rows=5;
    int **array = (int**)calloc(sizeof(int*), cols);
    for (int i = 0; i < cols; i++) {
       array[i] = (int*)calloc(sizeof(int*), rows);
    }

    fill(array, rows, cols);
    print(array, rows, cols);
    transform(array, rows, cols);
    printf("\n");
    print(array, rows, cols);

    for (int i = 0; i<rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}





