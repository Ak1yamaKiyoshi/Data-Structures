void swap(int arr[4][4], int aY, int aX, int bY, int bX) {
    int temp = arr[aY][aX];
    arr[aY][aX] = arr[bY][bX];
    arr[bY][bX] = temp;
}

// reverses each row of array
void transpose(int array[4][4], const int SIZE) {
    int temp;
    for (int x = 0; x < SIZE/2; x++)
        for (int y = 0; y < SIZE; y++) {
            temp = array[y][x];
            array[y][x] = array[y][SIZE-x-1];
            array[y][SIZE-x-1] = temp;   
        }
}


int rotate90Clockwise(int array[4][4], const int SIZE) {
    for (int y = 0; y < SIZE; y++) 
        for (int x = y; x < SIZE; x++) 
            swap(array, x, y, y, x);
  transpose(array, SIZE);
}