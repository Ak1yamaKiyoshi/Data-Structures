def counting_sort(input):
    counters = [0] * (len(input))
    for i in range(len(input)):
        counters[i] += 1
    return [i for i in range(len(counters)) for j in range(counters[i])]
# Driver Code
to_sort = [1, 5, 2, 2, 6, 5, 3]
print(counting_sort(to_sort))
