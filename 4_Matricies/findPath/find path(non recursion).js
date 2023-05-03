
function findPath(index, y, array) {
    let x = index;
    let num = array[y][x];
    while (x < index+3) {
        if (array[y][x] == 0 && array[y][x-1] != 0) {
            y += 1;
            x -= 2;
        }
        if (array[y][x] == num+1) {
            return [x, y];
        }
        x++;
    }
 
}


let array = [
    [1, 2, 0, 0, 0],
    [0, 0, 3, 0, 0],
    [0, 4, 5, 6, 0],
    [0, 0, 0, 7, 0],
    [0, 0, 0, 0, 8]
];
let path = [];
let x = 0, y = 0;
if (array[y][x] == 1) {
    console.log("x:",x,"y:",y,"num:",array[y][x]);
}
for (let i = 0; i < array.length+2; i++) {
    let buffer = findPath(x, y, array);
    x=buffer[0];
    y=buffer[1]; 
    console.log("x:",x,"y:",y,"num:",array[y][x]);
}

findPath(0, 0, array);

