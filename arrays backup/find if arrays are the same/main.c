#include <stdio.h>


// swap(int arr[], int a, int b)
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// void bubbleSort(int arr[], int int)
void bubbleSort(int arr[], int len) {
    int i, j;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
}

// samenessCheck(int array[], int arrayTwo[], int ARRSIZE)
// returns: 1 - Arrays are not same, 0 - arrays same 
int samenessCheck(int array[], int arrayTwo[], int ARRSIZE)
{
    int flag = 0;
    for (int i = 0; i < ARRSIZE; i++)
    {
        if (array[i] != arrayTwo[i])
            flag = 1;
    }
    return flag;
}

/* Перевірити чи містять масиви однакові елементи. 
(кількість елементів має бути однакова, але порядок появи елементів у масиві може відрізнятись) */
// returns: 1 - Arrays are not simmilar, 0 - arrays similar 
int similarityCheck(int aMain[], int aToCheck[], int ARRSIZE)
{
    bubbleSort(aMain, ARRSIZE);
    bubbleSort(aToCheck, ARRSIZE);
    return samenessCheck(aMain, aToCheck, ARRSIZE);
}

int main()
{
    const int ARRSIZE = 6;
    int array[] =    {4, 5, 2, 2, 7};
    int arrayTwo[] = {4, 5, 2, 7, 1};

    printf("%d", similarityCheck(array, arrayTwo, ARRSIZE));
    return 0;
}