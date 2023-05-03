// filling array with random numbers
function fillArandom(array) {
  for (let y = 0; y < array.length; y++) {
    for (let x = 0; x < array.length; x++) {
      array[y][x] = Math.floor(Math.random() * 17);
    }
  }
}

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

// print array 
function printA(array) {
  let str;
  for (let i = 0; i < array.length; i++) {
    str = array[i].join(", ");
    console.log("[" + str + "]");
  }
}


// enter array from kbd
function enterA(array) {
  const prompt = require("prompt-sync")();
  for (let i = 0; i < array.length; i++) {
    for (let j = 0; j < array[i].length; j++) {
      const input = prompt("enter array elem:");
      array[i][j] = parseInt(input);
    }
  }
}


function turn180degA(array) {
  for (let y = 0, y1 = array.length - 1; y < array.length / 2; y++, y1--)
  for (let x = 0, x1 = array.length - 1; x < array.length; x++, x1--) {
    swap(array, y1, x1, y, x);
    }
}

// swap 2 elements of array 
function swap(array, aY, aX, bY, bX) {
  let temp = 0;
  temp = array[aY][aX];
  array[aY][aX] = array[bY][bX];
  array[bY][bX] = temp;
}


// reverses each row of array
function transpose(array) {
  let temp;
  for (let y = 0; y < array.length; y++) {
    temp = array[y][0];
    array[y][0] = array[y][array.length - 1];
    array[y][array.length - 1] = temp;
  }
}


// rotates array for 90 degrees clockwise
function rotate90Clockwise(array) {
  for (let y = 0; y < array.length; y++) {
    for (let x = y; x < array.length; x++) {
      swap(array, x, y, y, x);
    }
  }
  transpose(array);
}


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


var array = Array.from(Array(4), () => new Array(4));
fillASeq(array);
printA(array);


printA(array);