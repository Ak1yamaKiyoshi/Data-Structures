#include <stdio.h>


int main()
{

    const int ARRAYLEN = 8;
    int array[] = {10, 3, 6, 2, 6, 8, 1, 45, 7};
    int num, j;

    for (int i = 1; i < ARRAYLEN; i++)
    {
        num = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > num)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = num;
    }

    for (int i = 0; i < ARRAYLEN; i++)
        printf("%d ", array[i]);

    return 0;
}
