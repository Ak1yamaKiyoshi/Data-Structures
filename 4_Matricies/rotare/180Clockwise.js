function turn180degA(array) {
  for (let y = 0, y1 = array.length - 1; y < array.length / 2; y++, y1--)
  for (let x = 0, x1 = array.length - 1; x < array.length; x++, x1--) {
    swap(array, y1, x1, y, x);
    }
}