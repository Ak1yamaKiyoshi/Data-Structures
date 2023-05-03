import random as rd
# Sub sort for sorting in buckets

def insertion_sort(to_sort):
    for i in range(1, len(to_sort)):
        num = to_sort[i]
        j = i - 1
        while j >= 0 and num < to_sort[j]:
            to_sort[j + 1] = to_sort[j]
            j -= 1
        to_sort[j + 1] = num
    return to_sort


def bucket_sort(array):
    # form bucket array
    bucket = [[] for i in range(len(array))]
    # insert elements * 10 in buckets
    for e in array:
        index = int(e * 10)
        bucket[index].append(e)
    # Sort elements in each bucket
    for i in range(len(bucket)):
        bucket[i] = insertion_sort(bucket[i])  # or sorted()
    # Get elements from buckets
    k = 0
    for i in range(len(bucket)):
        for j in range(len(bucket[i])):
            array[k] = bucket[i][j]
            k += 1
    return array


array = [round(rd.random(), 3) for i in range(rd.randint(0, 100))]
print(array)
print(bucket_sort(array))
