void calcTable(int array[4][4], const int SIZE){
    int sumRow = 0;
    int sumColumn = 0;
    int x, y;
    for ( y = 0; y < SIZE; y++) {
        sumRow = 0;
        sumColumn = 0;
        for (x = 0; x < SIZE; x++) {
            sumRow += array[y][x];
            sumColumn += array[x][y];
        }
        printf("\n");
        printf("%d column sum: %d\n", y, sumRow);
        printf("%d row sum: %d", y,  sumColumn);
    }
}