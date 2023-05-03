#include <stdio.h>


int main()
{

    const int ARRAYLEN = 8;
    int array[] = {10, 3, 6, 7, 8, 3, 1, 4};
    int min, minIndex, num; 
    int j = 0, i;

    while (j < ARRAYLEN) {
        //min = none
        for (i = j; i < ARRAYLEN; i++) {
            if (i == j || min > array[i]) {
                min = array[i];
                minIndex = i; 
            }
        }
    num = array[minIndex];
    array[minIndex] = array[j];
    array[j] = num;
    j++;
    }

    for (i = 0; i < ARRAYLEN; i++)
        printf("%d ", array[i]);

    return 0;
}
