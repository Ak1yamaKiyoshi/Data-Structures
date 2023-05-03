
function insertion_sort(array) {
    let num = 0;
    let j;
    for (let i = 1; i < array.length; i++) {
        num = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > num) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = num;
    }
}


let array = [10, 3, 6, 2, 6, 8, 1, 45, 7];
insertion_sort(array);

for (let i = 0; i < array.length; i++) {
    console.log(array[i]);
}