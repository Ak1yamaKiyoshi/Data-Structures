//1. Використовуючи вказівники розвернути масив. 
//Розмір масиву та початкові значення елементів ввести з клавіатури. 
//Задачу зробити в одному циклі без використання додаткових масивів. 

#include <stdio.h>
#include <malloc.h>


int main() {

    int len;
    int *array;
    int *temp = (int*)malloc(sizeof(int*));

    printf("Enter array len: ");
    scanf("%d", &len);

    array = (int*)malloc(sizeof(int*)*len);

    for (int i = 0, *ptr = array; i < len; i++, ptr++) {
        printf("Enter %i elem: ", i+1);
        scanf("%d", ptr);
    }
    
    printf("\norigin array: ");
    for (int *beg = array; beg < array+len; beg++) {
        printf("\n*beg: %2d", *beg);
    }
    
    for (int *beg = array, *end = array+len-1; beg < end; beg++, end--) {
        *temp = *beg; //
        *beg = *end; // 
        *end = *temp; // 
    }

    printf("\nchanged array: ");
    for (int *beg = array; beg < array+len; beg++) {
        printf("\n*beg: %2d", *beg);
    }

    free(array); free(temp);

    return 0;
}
