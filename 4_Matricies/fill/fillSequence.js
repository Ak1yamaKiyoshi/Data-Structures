
// filling array with sequence of numbers i = 1; i++
function fillASeq(array) {
    let i = 1;
    for (let y = 0; y < array.length; y++) {
      for (let x = 0; x < array.length; x++) {
        array[y][x] = i;
        i++;
      }
    }
  }