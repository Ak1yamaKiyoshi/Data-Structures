function flip(array, len) {
    for (let i=0, j=len; i<j; i++, j--) {
        let temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

function pancakeSort(array) {
    for (let len = array.length; len > 1; --len) { 
        let max = array.indexOf(Math.max(...array.slice(0, len)));
        if (max != len-1) { 
            flip(array, max); 
            flip(array, len-1); 
        }
    }
}


let arr = new Array(9)
for (let i = 0; i < arr.length; i++) 
    arr[i] = Math.floor(Math.random() * 10) 


console.log(arr)
pancakeSort(arr);
console.log(arr)