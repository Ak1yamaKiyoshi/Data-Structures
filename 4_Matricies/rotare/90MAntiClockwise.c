void MRotate90AntiClockwise(int array[4][4], const int SIZE) {
    int arrayB[SIZE][SIZE];
    int i;
    for (int y = SIZE-1, i = 0; y >= 0;i++, y--) 
        for (int x = SIZE-1; x >= 0; x--) 
            arrayB[y][x] = array[x][i];
    for (int y = SIZE-1; y >= 0; y--) 
        for (int x = SIZE-1; x >= 0; x--) 
            array[y][x] = arrayB[y][x];
}