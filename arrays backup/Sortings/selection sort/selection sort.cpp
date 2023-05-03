#include <iostream>

void insertionSort(int *array, int len) {
    for (int j = 0, min, minIndex, num; j < len; j++) {
        for (int i = j; i < len; i++) {
            if (i == j || min > array[i]) {
                min = array[i];
                minIndex = i; 
            }
        }
        num = array[minIndex];
        array[minIndex] = array[j];
        array[j] = num;
    }
}



int main()
{

    const int LEN = 8;
    int array[] = {10, 3, 6, 7, 8, 3, 1, 4};

    insertionSort(&array[0], LEN);

    for (int i = 0; i < LEN; i++)
        std::cout << array[i]<< " ";

    return 0;
}
