def selection_sort(arr):
    j = 0
    while j < len(arr):
        min = None
        for i in range(j, len(arr)):  # current num index
            if min == None or min[0] > arr[i]:
                min = [arr[i], i]  # min Number and index of it
        arr[j], arr[min[1]] = arr[min[1]], arr[j]
        j += 1
    return arr

# Driver code
to_sort = [10, 12, 5, 8, 7, 14, 2, 1, 0]
print(selection_sort(to_sort))
