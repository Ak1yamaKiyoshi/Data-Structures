#include <stdio.h>
#include <malloc.h>


// void enterA(int *arr, int len) 
void enterA(int *arr, int len) {
   printf("enter array \n");
   for (int i = 0, *ptr=arr; i < len; i++, ptr++) {
      printf("[%d]: ", i);
      scanf("%d", ptr);
   }
}

// void printA(int *array, int len) 
void printA(int *array, int len) {
    for (int i = 0, *ptr = array; i < len; i++, ptr++) {
        printf("%2d", *ptr);
    }
}

/*
За допомогою вказівників виконати циклічний зсув масиву праворуч на два елементи. */
void shiftA(int *array, int len, int sSize, int direction) {
    int temp;
    for (int j = 0; j < sSize; j++) {
        if (direction == 0) { // left
            temp = *array;
            for (int *i=array; i<array+len-1; i++)
                *i = *(i+1);
            *(array+len-1) = temp;
        }   
        if (direction == 1) { // right
            temp = *(array+len-1);
            for (int *i = array+len-1; i > array; i--)
                *i = *(i-1);
            *array = temp;
        }   
    }
}


int main() {
    int len = 5;    
    int *array = (int*)malloc(sizeof(int*)*len);

    enterA(array, len);
    shiftA(array, len, 2, 1);
    printA(array, len);

    free(array);


    return 0;
}