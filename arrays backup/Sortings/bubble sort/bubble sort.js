function bubble_sort(array) {
    let temp = 0;
    for (let i = 0; i < array.length - 1; i++) {
        for (let j = 0; j < array.length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }   
}


let array = [7, 6, 1, 9, 23, 4, 12, 4];
bubble_sort(array);

for (let i = 0; i < array.length; i++) {
    console.log(array[i]); 
}

