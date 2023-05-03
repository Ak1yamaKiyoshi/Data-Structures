#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

const int len = 10;

void printArray(int* array, int size)
{
    for (int i=0; i<size; i++)
        printf("%3d", array[i]);    
    printf("\n");
}


int partition(int* array,int low,int high)
{
    int pivot = array[high];
    int i = low - 1;
    for(int j = low;   j < high; j++ ){
        if (array[j] <= pivot){
            i++;
            if (i != j ) {
                int temp = array[j];
                array[j]= array[i];
                array[i] = temp;
            }
        }
    }
    int temp = array[++i];
    array[i] = array[high];
    array[high] = temp;
    printf("In partitition\n");
    printArray(array, len);
    char c = getchar();
    return i;
}

void quicksort(int array[],int low,int high){
    if(low < high) {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array,pi+1,high);
    }
}


int main()
{
    int array[] = {20, 17, 13, 15, 7, 9, 11, 10, 1, 3};
//4, 3, 9, 2, 6};
    printf("Start array: ");
    printArray(array, len);
    printf("Sorting\n");
    quicksort(array,0,len-1);

    return 0;
}