// filling array with random numbers
function fillArandom(array) {
    for (let y = 0; y < array.length; y++) {
      for (let x = 0; x < array.length; x++) {
        array[y][x] = Math.floor(Math.random() * 17);
      }
    }
  }