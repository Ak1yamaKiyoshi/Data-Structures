void swap(int arr[4][4], int aY, int aX, int bY, int bX) {
    int temp = arr[aY][aX];
    arr[aY][aX] = arr[bY][bX];
    arr[bY][bX] = temp;
}


void transform(int array[4][4], const int SIZE) { // const int SIZE
    //for (int i = 0; i < 2; i++)    
    for (int y=0, y1=SIZE-1; y < SIZE/2; y++, y1--)
        for (int x=0, x1=SIZE-1; x < SIZE; x++, x1--) {
            swap(array, y1, x1, y, x);
        }
}
