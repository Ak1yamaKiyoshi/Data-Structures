
let array = [10, 3, 6, 7, 8, 3, 1, 4];
let min, minIndex, num; 
let j = 0, i = 0;

function selection_sort() {
    while (j < array.length) {
        for (i = j; i < array.length; i++) {
            if (i == j || min > array[i]) {
                min = array[i];
                minIndex = i; 
            }
        }
        num = array[minIndex];
        array[minIndex] = array[j];
        array[j] = num;
        j++;
    }
}

selection_sort(array);

for (let i = 0; i < array.length; i++) {
    console.log(array[i]);
}