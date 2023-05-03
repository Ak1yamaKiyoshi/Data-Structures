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
