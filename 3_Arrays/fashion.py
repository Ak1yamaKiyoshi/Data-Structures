""" 
array = [ 1, 2, 1, 3, 4, 4, 4, 5, 6, 7, 8]

fashion = 0
for i in set(array):
    if array.count(i) > array.count(fashion):
        fashion = i
print(fashion)
"""


array = [ 1, 2, 1, 2, 2, 4, 4, 4, 4, 5, 2, 4]
array_without_repeats = [] 

# create array without repeating numbers ( is equal to set() )
for i in array:
    if i not in array_without_repeats:
        array_without_repeats.append(i)

# find fashion of number 
fashion = None
fashion_count = None
# for each number in array without repeats 
for i in array_without_repeats:
    # calculate count of that number in initial array 
    current_count = array.count(i)  
    # if fashion is not set, or if current count > fashion count 
    if fashion is None or current_count > fashion_count: 
        # update fashion and fashion count 
        fashion = i
        fashion_count = current_count
        
print( f" fashion of array: {fashion}, fashion_count: {fashion_count}" )
    
    