def array_min(array):
    nmin = None
    for i in array:
        if nmin is None or i < nmin:
            nmin = i
    return nmin

print(f" min {array_min([1,2,3,4,5,6,7,8,9,10])}")