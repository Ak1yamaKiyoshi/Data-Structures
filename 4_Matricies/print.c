#include <malloc.h>
#include <stdio.h>


int main() {
    
    int cols=5, rows=2;

    int **array = (int**)calloc(sizeof(int*), cols);
    for (int i = 0; i < cols; i++) {
        array[i] = (int*)calloc(sizeof(int*), rows);
    }

    int c = 1;
    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {
            array[y][x] = c++; 
        }
    }
    
    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {   
            printf(" %2d", *(*(array+y)+x));
        }
        printf("\n");
    }


    for (int i = 0; i < rows; i++) {
        free(array[i]); // same as *(array+i)
    }
    free(array);

    return 0;
}
