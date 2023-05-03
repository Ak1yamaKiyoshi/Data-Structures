// filling array with sequence of numbers i = 1; i++
function fillASeq(array) {
  let i = 0;
  for (let y = 0; y < array.length; y++) {
    for (let x = 0; x < array.length; x++) {
      array[y][x] = i;
      i++;
    }
  }
}

function findZeros(array, lim, counter = 0, x = 0, y = 0) {
  if (array[y][x] == 0) counter++;
  if (x + 1 < lim) 
    counter = findZeros(array, lim, counter, x + 1, y);
  else if (y + 1 < lim) 
    counter = findZeros(array, lim, counter, 0, y + 1);
  return counter;
}

var array = Array.from(Array(4), () => new Array(4));
fillASeq(array);
array[2][3] = 0;
console.log(findZeros(array, 4, 0, 0, 0));
