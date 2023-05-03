void swapFirstLastColumn(int array[4][4], const int SIZE) {
    int temp;
    for (int y = 0; y < SIZE; y++) {
            temp = array[y][0];
            array[y][0] = array[y][SIZE-1];
            array[y][SIZE-1] = temp;
    }
}