// reverses each row of array
function transpose(array) {
    let temp;
    for (let y = 0; y < array.length; y++) {
      temp = array[y][0];
      array[y][0] = array[y][array.length - 1];
      array[y][array.length - 1] = temp;
    }
  }
  