def partition(arr, begin, end):
    pivot = arr[end]
    i = begin - 1  # smaller element index (bottom)
    for j in range(begin, end):  # greater element index
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # swap
    # pivot <> last smaller element (bottom)
    arr[i+1], arr[end] = arr[end], arr[i+1]
    return i + 1

def quick_sort(arr, begin, end):
    if begin < end:
        # index that divides array (smaller num index)
        i = partition(arr, begin, end)
        quick_sort(arr, begin, i - 1)  # sorting before pivot
        quick_sort(arr, i + 1, end)    # sorting after pivot
        return arr

# Driver code
#to_sort = [0, 5, 87, 12, 24, 78, 23, 67, 12]
#print(quick_sort(to_sort, 0, len(to_sort)-1))
