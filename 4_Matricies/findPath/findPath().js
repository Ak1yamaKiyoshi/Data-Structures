
function find(index, y, array) {
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

function findPath(array) {
    let path = [];
    let x = 0, y = 0;
    if (array[y][x] == 1) {
        path.push([x,y]);
    }
    for (let i = 0; i < array.length+2; i++) {
        let buffer = find(x, y, array);
        x=buffer[0];
        y=buffer[1]; 
        path.push([x,y]);
    }
    
    find(0, 0, array);
    return path;
}
let array = [
    [1, 2, 0, 0, 0],
    [0, 0, 3, 0, 0],
    [0, 4, 5, 6, 0],
    [0, 0, 0, 7, 0],
    [0, 0, 0, 0, 8]
];


console.log(findPath(array));
