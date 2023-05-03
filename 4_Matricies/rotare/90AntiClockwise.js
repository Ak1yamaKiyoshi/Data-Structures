// space complexity n ; time complexity n+n
// rotates array for 90 degrees anti clockwise
function TRotate90AntiClockwise(array) {
  transpose(array);
  for (let y = 0; y < array.length; y++) {
    for (let x = y; x < array.length; x++) {
      swap(array, x, y, y, x);
    }
  }
}
