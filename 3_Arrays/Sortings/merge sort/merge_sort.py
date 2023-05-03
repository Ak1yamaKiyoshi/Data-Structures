def merge(left, right):
    out = []
    while left != [] and right != []:
        if left[0] > right[0]:
            out.append(right.pop(0))
        else:
            out.append(left.pop(0))
    out += left
    out += right
    return out

def merge_sort(array):
    if len(array)//2 == 0:
        return array
    mid = len(array)//2
    left = merge_sort(array[:mid])
    right = merge_sort(array[mid:])

    return merge(left, right)


# Driver code
to_sort = [7, 8, 3, 9, 10, 2, 5, 3, 6, 3]
print(merge_sort(to_sort))
