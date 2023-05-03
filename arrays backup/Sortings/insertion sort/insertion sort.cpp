#include <iostream>

void insertionSort(int *array, int len) {
    for (int i = 1; i < len; i++) {
        int num = array[i]; 
        int j = i;
        while (--j >= 0 && array[j] > num) 
            array[j+1] = array[j];
        array[++j] = num;
    }   
}

int main()
{
    const int len = 9;
    int array[] = {10, 3, 6, 2, 6, 8, 1, 45, 7};

    insertionSort(&array[0], len);

    // print array 
    std::cout << "\n";
    for (int& element: array) 
        std::cout << element << " ";

    return 0;
}
