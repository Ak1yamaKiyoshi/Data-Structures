
#include <stdio.h>
#include <math.h>

int findIndex(int arr[], const int SIZE)
{
    double sum = 0;
    for (int i=0; i<SIZE; i++) sum += arr[i];
    double avg = sum / SIZE;
    printf("%f\n", avg);
    int k = SIZE-1;
    double min = fabs(avg - arr[k]);
    for (int i = k; i >= 0; i--) {
        printf("min = %f\n", min);
        if (fabs(avg - arr[i]) < min) {
            min = fabs(avg - arr[i]);
            k = i;
            printf("k = %d\n", k);
        }
    }
    return k;
}

int main()
{
    const int SIZE = 8;
    int arr[] = { 10, 3, 2, 6, 7, 4, 8, 9 };
    int index = findIndex(arr, SIZE);
    printf("%d\n", index);
    return 0;
}

