#include <stdio.h>

int main()
{
    const int SIZE = 8;
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int slides, direction;

    printf("Enter slide\n");
    scanf("%d", &slides);
    printf("Enter direction\n");
    printf("1 - left\t2 - right\n");
    scanf("%d", &direction);

    for (int i=0; i<slides; i++) {
        if (direction == 1) {
            for (int j=0; j<SIZE-1; j++)
                array[j] = array[j+1];
            array[SIZE-1] = 0;
        } else {
            for (int j=SIZE-1; j>0; j--)
                array[j] = array[j-1];
            array[0] = 0;
        }
    }
    for (int i=0; i<SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}