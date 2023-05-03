#include <iostream>

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

int main() {
    int LEN = 4;
    int array[LEN];
    
    for (int& element: array) {
        std::cout << "num: ";
        std::cin >> element;
    }

    bubbleSort(&array[0], LEN);
    
    for (int& element: array) 
        std::cout << element << "\t";

    return 0;
}
