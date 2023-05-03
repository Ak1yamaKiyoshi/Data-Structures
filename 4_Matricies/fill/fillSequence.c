void fillSeq(int array[4][4], const int SIZE){
    int i = 1; 
    for (int y = 0; y < SIZE; y++) 
        for (int x = 0; x < SIZE; x++) {
            array[y][x] = i;
            i++; 
        }
}