#include <stdio.h>

void merge(int A[], int low, int mid, int high) {

  int n1 = low, n2 = mid + 1;
  int arr[high - low + 1], indx = 0;

  for (int i = low; i <= high; i++) {
    if (n1 > mid)
      arr[indx++] = A[n2++];

    else if (n2 > high)
      arr[indx++] = A[n1++];

    else if (A[n1] < A[n2])
      arr[indx++] = A[n1++];

    else
      arr[indx++] = A[n2++];
  }
  for (int i = 0; i < indx; i++) {
    A[low++] = arr[i];
  }
}

void merge_sort(int A[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    merge_sort(A, low, mid);
    merge_sort(A, mid + 1, high);

    merge(A, low, mid, high);
  }
}

void printArray(int A[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

int main() {
  int arr[] = {7, 4, 2, 8, 3, 0, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Given array: \n");
  printArray(arr, size);

  merge_sort(arr, 0, size - 1);

  printf("Sorted array: \n");
  printArray(arr, size);
  return 0;
}