function swap(array, a, b) {
    let temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}



function heapify(array, len, root) {
    let max = root, left = (2*root)+1, right = (2*root)+2;
    // root must be largest element

    // if left child or right child is larger than root 
    // we change max index
    if (left < len && array[root] < array[left]) 
        max = left;
    if (right < len && array[max] < array[right]) 
        max = right;
    
    // and if max index != root, we swap max index with root
    // so it will be max in subtree
    if (max != root) {
        swap(array, root, max);
        heapify(array, len, max);
    }
}

function heapSort(array) {
    // heapify initial array
    for (let i = array.length/2; i >=0; i--) 
        heapify(array, array.length, i);

    // heapify lesser and lesser slice of array, 
    // gradually swapping max element (after heapify) to end of array
    for (let i = array.length-1; i >=0 ; i--) {
        swap(array, 0, i);
        heapify(array, i, 0);
    }
    
}

let arr = new Array(8)

for (let i = 0; i < arr.length; i++) 
    arr[i] = Math.floor(Math.random() * 10) 


console.log(arr)
heapSort(arr);
console.log(arr)