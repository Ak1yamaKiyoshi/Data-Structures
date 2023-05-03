#include <stdio.h>
#include <malloc.h>

/*
void shellSort(int* array, int len) {
    int m = len/2 ;  
    
    int d[] = {20, 9, 4, 1, 0};

    for (int k = 1; k < m; k++) {
        for(int i = d[k] + 1; i < len; i++) {
            int a = array[i];
            int j = i;
            while (j-d[k] >= 1 && array[j-d[k]] > a) {
                array[j] = array[j-d[k]];
                j = j - d[k];
            }
            array[j] = a;
        }
    }
}
*/


void shellSort(int *array, int len) {
    /* shell gap, start with big gap and reduce it */
    for(int gap = len/2; gap > 0; gap /= 2) 
        /* Do a gapped insertionsort for current gap size
            First element already in gapped order array[0, gap-1]
            Keep incrementing until array is sorted */
        for ( int i = gap; i < len; i++) {
            /* Add array[i] to the elements that have been gap sorted 
                Save array[i] in temp and make a hole at position i*/
            int temp = array[i];
            /* Shift earlier gap-sorted elements up until next correct 
                location for array[i] is found */
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];
            /* put temp (the original array[i]) in its correct location*/ 
            array[j] = temp;
        }
}


void fill(int *array, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) array[i] = rand() % 10;
}

void print(int *array, int len) {
    srand(time(NULL));
    for (int i = 0;i < len; i++) printf("%d ", array[i]);
}



int main() {
    int len = 20;
    int *array = (int*)calloc(sizeof(int), len);
    
    printf("\n filled : \n");
    fill(array, len);
    print(array, len);
    printf("\n sorted : \n");
    shellSort(array, len);
    print(array, len);

    free(array);
    
    return 0; 
}