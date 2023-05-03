void printTable(int array[4][4], const int SIZE){
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) 
            printf("%4d", array[y][x]);
        printf("\n");
    }
}