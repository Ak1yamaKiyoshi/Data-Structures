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