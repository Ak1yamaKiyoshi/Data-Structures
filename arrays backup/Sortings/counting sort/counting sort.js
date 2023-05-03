
function countingSort(array) {
    let counters = new Array(10).fill(0);

    for (let i = 0, element = 0; i < array.length; i++) {
        element = array[i];
        counters[element]++;
    }

    for (let i = 0, k = 0; i < 10; i++) 
       for (let j = 0; j < counters[i]; j++) 
           array[k++] = i;
}


var toSort = [3, 5, 7, 4, 8, 1, 4, 6, 4, 2, 7, 6, 8, 0, 9, 2, 3, 7, 4, 3, 2];

console.log(toSort);
countingSort(toSort);
console.log(toSort);

