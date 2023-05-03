#include <stdio.h>

int main()
{
    const int SIZE = 6;
    int array[] = { 1, 3, 4, 7, 9, 10};
    for (int i=0; i<SIZE-1; i++)
        if (array[i] > array[i+1]) {
            printf("Array is not sorted\n");
            return -1;
        }
    int x;

    printf("Enter search number: ");
    scanf("%d", &x);
    
    int left=0, right=SIZE-1, middle;
    while (array[left]<x && array[right]>x && (right-left) >1) {
        middle = (right + left + 1) / 2;
        if (x > array[middle])
            left = middle;
        else
            right = middle;
    }
    if (array[left] == x || array[right] == x)
        printf("Number found\n");
    else
        printf("Number not found\n");
    return 0;
}