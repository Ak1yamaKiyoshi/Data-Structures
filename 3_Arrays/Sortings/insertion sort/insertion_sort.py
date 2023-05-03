def insertion_sort(array):
    for i in range(1, len(array)):
        num = array[i]
        j = i - 1
        while j >= 0 and num < array[j]:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = num
    return array

# Driver code
to_sort = [0, 1, 4, 6, 2, 6, 1, 9, 12]
print(insertion_sort(to_sort))
