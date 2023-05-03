def heap_sort(array):
    j = arr_len = len(array)-1
    for i in range(arr_len):
        # heapify
        for i in range(j, 0, -1):
            if i <= j:
                if array[i] > array[i//2]:
                    array[i], array[i//2] = array[i//2], array[i]
        # swap
        array[0], array[j] = array[j], array[0]
        j -= 1
    return array

# Driver Code
to_sort = [23, 15, 56, 34, 1, 5, 9]
print(heap_sort(to_sort))
