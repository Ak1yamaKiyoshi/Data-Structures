#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>


void fill(int **array, int rows, int cols){
    srand(time(NULL));
    for (int y = 0; y < cols; y++) {
      for (int x = 0; x < rows; x++) {
        array[y][x] = rand() % 10;
      }
    }
}


void print(int *array[], int rows, int cols){
    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {
            printf("%4d", array[y][x]);
        }
        printf("\n");
    }
}

    /* Відсортувати матрицю таким чином, 
	щоб на горі (у перших рядках) опинилися найменші елементи, 
	а також у кожному рядку менші елементи знаходились лівіше більших. 
    */
void bubbleSort(int *arr, int len) {
    int temp, flag=0;
    for (int i=0; i<len; i++) {
        flag = 0;
        for (int *j=arr; j<arr+len-1-i; j++) {
            if (*j > *(j+1)) {
                temp = *j;
                *j = *(j+1);
                *(j+1) = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

void sort(int **matrix, int rows, int cols) {
    int *array = (int*)calloc(sizeof(int), rows*cols);
    for (int y=0;y<rows;y++){
        for(int x=0;x<cols;x++){
            array[cols*y+x] = matrix[y][x];
        }
    }
    bubbleSort(array, rows*cols);
    for (int y=0;y<rows;y++){
        for(int x=0;x<cols;x++){
            matrix[y][x] = array[cols*y+x] ;
        }
    }
    free(array); 
}

int main()
{
    int cols=5;
    int rows=5;
    int **array = (int**)calloc(sizeof(int*), cols);
    for (int i = 0; i < cols; i++) {
       array[i] = (int*)calloc(sizeof(int), rows);
    }

    fill(array, rows, cols);
    print(array, rows, cols);
    sort(array, rows, cols);
    printf("\n");
    print(array, rows, cols);

    for (int i = 0; i<rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}