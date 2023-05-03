
// space complexity n +  ; time complexity n 
function MRotate90AntiClockwise(array) {
    let arrayB = Array.from(Array(array.length), () => new Array(array.length));
    console.log(array)
    let i;
    for (let y = array.length-1, i = 0; y >= 0;i++, y--) {
      for (let x = array.length-1; x >= 0; x--) {
        arrayB[y][x] = array[x][i];
      }
    }
  
    for (let y = array.length-1; y >= 0; y--) {
      for (let x = array.length-1; x >= 0; x--) {
        array[y][x] = arrayB[y][x];
      }
    }
  }