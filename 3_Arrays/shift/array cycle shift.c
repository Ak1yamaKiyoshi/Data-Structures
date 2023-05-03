#include <stdio.h>


int main()
{
    const int ARRSIZE = 5;
    int array[] = {1, 2, 3, 4, 5};
    int shiftSize, temp, direction;

    printf("enter shift direction: ");
    scanf("%d", &direction);

    printf("enter shift size: ");
    scanf("%d", &shiftSize);

    printf("\n");
    for(int i = 0; i < ARRSIZE; i++)
        printf("%d ", array[i]);
    
    for(int j = 0; j < shiftSize; j++)
    {

        if (direction == 0) {
            temp = array[0];
            for (int i = 0; i < ARRSIZE-1; i++)
                array[i] = array[i+1];
            array[ARRSIZE-1] = temp;
        }
        else {
            temp = array[ARRSIZE-1];
            for (int i = ARRSIZE-1; i > 0; i--)
                array[i] = array[i-1];
            array[0] = temp;
        }
    }
    
    printf("\n");
    for(int i = 0; i < ARRSIZE; i++)
        printf("%d ", array[i]);

    return 0;
}