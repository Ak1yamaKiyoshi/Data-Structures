#include <stdio.h>


/*
Написати функцію яка виводить елементи масиву. Функція окрім 
необхідних параметрів стосовно масиву 
мусить приймати додатковий 
параметр який вказує як друкувати масив: в рядок чи у стовпчик.
*/
// arrayPrint(int array[], int ARRSIZE, int flag)
// flag == 1: prints " ", else prints "\n"
void arrayPrint(int array[], const int ARRSIZE, int flag) {
    if (flag == 1) {
        for (int i = 0; i < ARRSIZE; i++)
            printf("%d ", array[i]);
    }
    else {
        for (int i = 0; i < ARRSIZE; i++)
            printf("%d\n", array[i]);
    }
}


int main()
{
    const int ARRSIZE = 5;
    int array[] = {1, 2, 3, 4, 5};
    arrayPrint(array, ARRSIZE, 1);

    return 0;
}
