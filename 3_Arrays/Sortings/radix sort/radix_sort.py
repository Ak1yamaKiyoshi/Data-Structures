def counting_sort(array, slce):

    out = [0] * len(array)
    count = [0] * 10

    for e in array:
        index = e // slce % 10
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i-1]

    for i in range(len(array)-1, -1, -1): 
        index = array[i] // slce % 10
        out[count[index]-1] = array[i]
        count[index] -= 1

    for i in range(len(array)):
        array[i] = out[i]

    return array


def radix_sort(array):
    slce = 1  # slice
    maxNum = max(array)
    while maxNum // slce >= 1:
        counting_sort(array, slce)
        slce *= 10
    return array

to_sort = [10, 4, 7, 5,1333, 12323,11231132132312, 90, 0, 80, 7, 3, 6, 2]
print(radix_sort(to_sort))
