void findMatrixMax(int matrix[4][4], const int SIZE, int * max) {
    max[0] = 0, max[1] = 0;
    for (int y = 0; y < SIZE; y++) 
        for (int x = 0; x < SIZE; x++) 
            if (matrix[y][x] > matrix[max[0]][max[1]]) {
                max[0] = y; 
                max[1] = x;
            }
}