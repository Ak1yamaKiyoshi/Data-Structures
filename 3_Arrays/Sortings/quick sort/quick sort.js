function swap(array, a, b) {
    let temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

function partition(array, begin, end) {
    let pivot = array[end];
    let i = begin - 1;
    for (let j = begin; j < end; j++)  
        if (array[j] <= pivot) 
            swap(array, j, ++i);
    
    swap(array, end, ++i);
    return i;
}

function quickSort(array, begin, end) {
    if (begin < end) {
        let i = partition(array, begin, end);
        quickSort(array, begin, i-1);
        quickSort(array, i+1, end);
    }
}


let arr = new Array(4)
for (let i = 0; i < arr.length; i++) 
    arr[i] = Math.floor(Math.random() * 10) 

console.log(arr)
quickSort(arr, 0, arr.length-1);
console.log(arr)
