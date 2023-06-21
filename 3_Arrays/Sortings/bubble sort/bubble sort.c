// void bubbleSort(int *arr, int len)
void bubbleSort(int *arr, int len) {
    int temp; // temp is for swap array values
    int flag; // flag to stop sort when array is already sorted
    for (int i = 0; i < len; i++) {
        flag = 0; 
        // iterate trough all array 
        for (int *j=arr; j<arr+len-1-i; j++) 
            if (*j > *(j+1)) {
                // swap values 
                temp = *j;
                *j = *(j+1);
                *(j+1) = temp;
                flag = 1;
            }
        // stop sort when it's iterated whole array and didn't do swaps
        if (flag == 0) break;
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
