def partition(array, start, end):
    pivot = array[end]
    low = start
    high = end -1
    while True:
        while low <= high and array[high] >= pivot:
            high = high - 1
        while low <= high and array[low] <= pivot:
            low = low + 1
        if low <= high:
            array[low], array[high] = array[high], array[low]
        else:
            break
    array[end], array[low] = array[low], array[end]
    return low

def quick_sort(array, start, end):
    if start >= end:
        return array
    p = partition(array, start, end)
    quick_sort(array, start, p-1)
    quick_sort(array, p+1, end)
    return array
#array = [3, 6, 2, 7, 1, 5, 4]
#array = [3, 2, 1, 5, 4]
#quick_sort(array, 0, len(array) - 1)
#print(array)
