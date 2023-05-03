#include <stdio.h>


/*
Виконати сортування вибором у такий спосіб, щоб внутрішній цикл разом зі своїм тілом були розміщені
 в окремій функції, а зовнішній цикл в окремій функції. Функція де міститься зовнішній цикл має викликати функцію 
 де міститься внутрішній цикл.*/
int inCycle(int array[], const int ARRAYLEN, int min, int minIndex, int j, int out[]) {       
    int i;
    for (i = j; i < ARRAYLEN; i++) {
        if (i == j || min > array[i]) {
            min = array[i];
            minIndex = i; 
        }
    }
    out[0] = min;
    out[1] = minIndex;
    return out;
}


// void selectionSort(int array, int ARRAYLEN)
void selectionSort(int array[], const int ARRAYLEN, int out[])
{
    int min, minIndex, num; 
    int j = 0;

    while (j < ARRAYLEN) {
        inCycle(array, ARRAYLEN, min, minIndex, j, out);
        min = out[0];
        minIndex = out[1];
    num = array[minIndex];
    array[minIndex] = array[j];
    array[j] = num;
    j++;
    }
}


int main()
{
    const int ARRAYLEN = 8;
    int array[] = {10, 3, 6, 7, 8, 3, 1, 4};
    int out[2];

    selectionSort(array, ARRAYLEN, out);

    for (int i = 0; i < ARRAYLEN; i++)
        printf("%d ", array[i]);
    return 0;
}
