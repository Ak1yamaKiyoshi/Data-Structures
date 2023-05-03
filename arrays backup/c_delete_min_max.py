
array = [1, 2, 3, 4, 1, 2, 3, 5, 6, 7, 5, 6, 7]

nMax = None
nMin = None
for i in array:
    if nMin is None or i < nMin:
        nMin = i
    if nMax is None or i > nMax:
        nMax = i

for i in array: 
    if i == nMax or i == nMin: 
        array.remove(i)

print( array )