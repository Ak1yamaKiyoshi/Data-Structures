// finds max number of matrix
function findMax(matrix) {
    let max = Array(2);
    (max[0] = 0), (max[1] = 0);
    for (let y = 0; y < matrix.length; y++) {
      for (let x = 0; x < matrix.length; x++) {
        if (matrix[y][x] > matrix[max[0]][max[1]]) {
          max[0] = y;
          max[1] = x;
        }
      }
    }
    return max;
  }