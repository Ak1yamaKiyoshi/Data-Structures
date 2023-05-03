
// summs all rows and columns in array
function rowColumnSum(array) {
    let sumRow = 0,
      sumColumn = 0;
    let x, y;
    for (y = 0; y < array.length; y++) {
      sumRow = 0;
      sumColumn = 0;
      for (x = 0; x < array.length; x++) {
        sumRow += array[y][x];
        sumColumn += array[x][y];
      }
      console.log(y + " column sum:" + sumRow);
      console.log(y + " row sum: " + sumColumn);
    }
  }