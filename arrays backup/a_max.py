def array_max(array):
    nmax = None
    for i in array:
        if nmax is None or i > nmax:
            nmax = i
    return nmax

print(f" max {array_max([1,2,3,4,5,6,7,8,9,10])}")