#include <iostream>
#include <algorithm>


void randomFilling(int *array, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        array[i] = rand() % len;
}

void print(int *array, int len) {
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
}

void merge(int *array, int low, int mid, int high) {
    int n1 = low, n2 = mid + 1;
    int arr[high - low + 1], k = 0;

    for (int i = low; i <= high; i++) 
        if (n1 > mid)
            arr[k++] = array[n2++];
        else if (n2 > high)
            arr[k++] = array[n1++];
        else if (array[n1] < array[n2])
            arr[k++] = array[n1++];
        else
            arr[k++] = array[n2++];
    
    for (int i = 0; i < k; i++) 
        array[low++] = arr[i];
}

void merge_sort(int *array, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merge(array, low, mid, high);
  }
}

int main() {

    int len = 14; 
    int *array = new int[len];

    randomFilling(array, len);
    print(array, len);
    std::cout << "\n";
    merge_sort(array, 0, len);
    print(array, len);

    delete array;

    return 0;
}