#include <stdio.h>
#include <malloc.h>


//За допомогою вказівників написати функцію двійкового пошуку у масиві
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

// returns 1 if not sorted, otherwise 1
int is_sorted(int *array, int len) {
    for (int *i=array; i<array+len-1; i++) {
        if (*i > *(i+1)) return 1;
    }
    return 0;
}


int binary_search(int *array, int len, int num) {
    int left=0, right=len-1, middle;
    int *ptr = array;
    if (is_sorted(array, len)==0) {
        while (*(ptr+left)<num && *(ptr+right)>num && (right-left)>1) {
            middle = (right + left + 1) / 2;
            if (num > *(array+middle))
                left = middle;
            else
                right = middle;
        }
        if (*(array+left) == num || *(array+right) == num) 
            return 0; // number found
        else 
            return 1; // number not found   
    }
    else 
        return -1; // array is not sorted
}


int main()
{
    int len = 5;    
    int *array = (int*)malloc(sizeof(int*)*len);
    int num; 

    enterA(array, len);
    printf("\nEnter number to search: ");
    scanf("%d", &num);

    printf("binary_search result: %d\n", binary_search(array, len, num));
    
    printA(array, len);

    free(array);
    return 0;
}


