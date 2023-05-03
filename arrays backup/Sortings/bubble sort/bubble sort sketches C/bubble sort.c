 #include <stdio.h>
#include <malloc.h>


// void bubbleSort(int *arr, int len)
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
        printf(" %d", *ptr);
    }
}


int main() {
    int len = 4;
    int *array = (int*)malloc(sizeof(int*)*len);
    enterA(array, len);
    printA(array, len);
    printf("\n");
    bubbleSort(array, len);
    printA(array, len);
    free(array);

    return 0;
}
